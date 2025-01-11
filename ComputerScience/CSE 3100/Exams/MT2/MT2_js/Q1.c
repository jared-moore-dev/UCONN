#define BUFFER_SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define READEND 0
#define WRITEEND 1

char* read_message(int fd) {
  // Read from fd until you hit a newline
  int index = 0;
  char c;
  char* arr = (char*)malloc(sizeof(char)*BUFFER_SIZE);
  while (read(fd, &c, 1) > 0){
      if (index >= BUFFER_SIZE){
          arr = realloc(arr, sizeof(char)*(index+1));
      }
      arr[index] = c;
      index++;
      if (c == '\n'){
          arr[index] = '\0';
          break;
      }
  }
  arr[index] = '\0';
  return arr;
}

int main(int argc,char* argv[])
{
   /* TODO: Q1
      Implement "ls /dev | xargs | cut -d ' ' -f<a>-<b>" 
      where <a> and <b> are from the command line
      The use of system is prohibited.
   */
   char* a = argv[1];
   char* b = argv[2];
    char* command = (char*)malloc(6);
    command[0] = '-';
    command[1] = 'f';
    strcat(command, a);
    strcat(command, "-");
    strcat(command, b);
    strcat(command, "/0");

   
   int fd1[2], fd2[2];
   
   if (pipe(fd1) == -1) exit(-1);
   pid_t fork1 = fork();
   if (fork1 == 0){
       // Child
       char* msg; // TODO: Initialize this
       msg[0] = 'h';
       close(fd1[0]);
       
       dup2(fd1[1], STDOUT_FILENO);
       
       msg = read_message(fd1[1]);

       close(fd1[1]); // TODO: add comments labeling what pipe is what, and what end is what 
       
       if (execl("ls", "/dev", NULL) == -1) exit(-1);
       // TODO: The result of this should be saved/stored somehow
   }
   else{
       if (pipe(fd2) == -1) exit(-1);
       pid_t fork2 = fork();
       if (fork2 == 0){
           // Child
           char* msg;
          
           close(fd1[1]);
           close(fd2[0]);
           
           dup2(fd2[1], STDOUT_FILENO);
           close(fd2[1]);

           msg = read_message(fd1[0]);
           close(fd1[0]);

           
           printf("%s", msg);
           
           if (execl("xargs", msg, NULL) == -1) exit(-1);
       }
       else{
           char* msg;

           close(fd1[1]);
           close(fd2[1]);
           dup2(fd1[0], STDIN_FILENO);
           close(fd1[0]);
           
           msg = read_message(fd2[0]);
           close(fd2[0]);
           
           printf("%s", msg);

           // TODO: Change "-f" to be a new string of that + num1 + "-" + num2
           if (execl("cut", "-d", command, msg, NULL) == -1) exit(-1);
       }
   }
   return 0;
}