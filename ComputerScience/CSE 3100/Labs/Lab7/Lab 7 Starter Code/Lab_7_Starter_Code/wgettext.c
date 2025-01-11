#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/select.h>
#include <assert.h>
#include "analyze.h"

void checkError(int status,int line)
{
   if (status < 0) {
      printf("socket error(%d)-%d: [%s]\n",getpid(),line,strerror(errno));
      exit(-1);
   }
}

int main(int argc,char* argv[])
{
   // Create a socket
   if (argc < 2) {
      printf("Usage is: wgettext <url>\n");
      return 1;
   }
   char host[512];
   int  port = 80;
   char url[512];
   analyzeURL(argv[1],host,&port,url);
   printf("[%s] [%d] [%s]\n",host,port,url);

   // TODO: Finish the program. Follow the specification in the PDF
   // set up the request for the server
   int sid = socket(PF_INET, SOCK_STREAM, 0);
   struct sockaddr_in srv;
   struct hostent *server = gethostbyname(host);
   if (server==NULL){
       printf("No Host named %s found\n", argv[1]);
       return 2;
   }
   srv.sin_family = AF_INET;
   srv.sin_port = htons(port);
   memcpy(&srv.sin_addr, server->h_addr_list[0],server->h_length);
   // connect
   int status = connect(sid,(struct sockaddr*)&srv, sizeof(srv));
   checkError(status, __LINE__);
    // instead of popping out the function for cleanliness, I'll implement it in line
   //if connection successful, make the request
    char msgbuf[1024];\
    // create msg in the "GET url\n" format and put it in buffer
    sprintf(msgbuf, "GET %s\n",url);
    int bytessent = 0;
    int totalbytes = strlen(msgbuf);
    // send the msg to the server
    while (bytessent != totalbytes){
        int num = write(sid, msgbuf + bytessent, totalbytes - bytessent);
        bytessent += num;
    }
    // put the output file to be standard output
    dup2(sid, STDIN_FILENO);
    // check and make sure the file works
    status = execlp("html2text","html2text",NULL);
    checkError(status,__LINE__);
   return 0;
}

