#define BUFFER_SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
void write_message(char * message, int fd) {
  // initialize character
  char ch;
  // for loop to go from start to end of string
  for(int i=0; i < strlen(message); i++){
      ch = message[i];
      if(write(fd,&ch, 1)!=1){
          exit(-1);
      }
  }
}
char* read_message(int fd) {
  // make buffer, character to write, and counter
  char ch;
  int count = 0;
  char* buffer = calloc(BUFFER_SIZE, sizeof(char));
 // read the message with a while loop
 while(read(fd, &ch, 1) > 0){
     if(count >= BUFFER_SIZE){
         // increase buffersize by one char if limit is reached
         buffer = realloc(buffer, sizeof(char)*(count+1));
     }
     buffer[count] = ch;
     count++;
     if(ch == '\n'){
         if(count >= BUFFER_SIZE){
             buffer = realloc(buffer, sizeof(char)*(count+1));
         }
         // replace the '\n' with an EOF
         buffer[count] = '\0';
         return buffer;
     }
 }
}
void encrypt(char * message) {
  for(int i=0;i<strlen(message);i++) {
    if(message[i] == '\n') break;
    message[i] += 1;
  }
}
void decrypt(char * message) {
  for(int i=0;i<strlen(message);i++) {
    if(message[i] == '\n') break;
    message[i] -= 1;
  }
}



int main() {
  // Set up pipes
  int pTOc1[2], c1TOc2[2], c2TOp[2];
  if(pipe(pTOc1) == -1) exit(-1);
  if(pipe(c1TOc2) == -1) exit(-1);
  // Create Pipes
  pid_t pid1 = fork();
  if (pid1 == 0) {
    // Child 1
    char* msg;
    // TODO: Close Unneeded Pipes (Parent->Child1, Child1->child2)
    close(pTOc1[1]);
    close(c1TOc2[0]);
    msg = read_message(pTOc1[0]);
    printf("Child 1 is Encrypting!\n");
    encrypt(msg);
    write_message(msg,c1TOc2[1]);
    // TODO: Close Remaining Pipes
    free(msg);
    close(pTOc1[0]);
    close(c1TOc2[1]);
    exit(0);
  } else {
    if(pipe(c2TOp) == -1) exit(-1);
    pid_t pid2 = fork();
    if (pid2 ==0) {
      // Child 2
      char* msg;
      // TODO: Close Unneeded Pipes
      close(pTOc1[1]);
      close(pTOc1[0]);
      close(c1TOc2[1]);
      close(c2TOp[0]);
      msg = read_message(c1TOc2[0]);
      printf("Child 2: %s", msg);
      write_message(msg, c2TOp[1]);
      // TODO: Close Remaining Pipes
      // free memory
      free(msg);
      close(c1TOc2[0]);
      close(c2TOp[1]);
      exit(0);
    } else {
      // Parent
      char * msg = "This is a test.\n";
      //TODO: Close Unneeded Pipes
      close(pTOc1[0]);
      close(c1TOc2[1]);
      close(c1TOc2[0]);
      close(c2TOp[1]);
      printf("Parent: %s", msg);
      write_message(msg,pTOc1[1]);
      msg = read_message(c2TOp[0]);
      decrypt(msg);
      printf("Parent: %s",msg);
      // TODO: Close Remaining Pipes and free the msg
      free(msg);
      close(pTOc1[1]);
      close(c2TOp[0]);
      return 0;
    }

  }
}
