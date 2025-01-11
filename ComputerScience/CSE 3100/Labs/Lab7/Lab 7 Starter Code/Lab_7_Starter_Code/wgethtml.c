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

char* readResponse(int sid)
{
   size_t sz = 8;
   char* buf = malloc(sizeof(char)* sz);
   int done = 0,received = 0;  
   while (!done) {
      int nbb = read(sid,buf + received,sz - received);
      if (nbb > 0)
         received += nbb;
      else if (nbb == 0)
         done = 1;
      if (received == sz) {
         buf = realloc(buf,sz * 2);
         sz  *= 2;
      }
   }
   if (received == sz)
      buf = realloc(buf,sz + 1);
   buf[received] = 0;
   return buf;
}
char* responsehelp(int sid, char* url){
    // create a buffer of 1024 bytes
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
    // intake the response from the server
    char* response = readResponse(sid);
    return response;
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
   
   // TODO: Finish the function!
   /* Namely: send the request via a GET (see PDF)
      retrieve the response 
      display it on the standard output
   */
   int sid = socket(PF_INET, SOCK_STREAM, 0);
   struct sockaddr_in srv;
   struct hostent *server = gethostbyname(host);
   if (server == NULL){
       printf("No Host named %s found\n", argv[1]);
       return 2;
   }
   srv.sin_family = AF_INET;
   srv.sin_port = htons(port);
   memcpy(&srv.sin_addr,server->h_addr_list[0],server->h_length);
   int sts = connect(sid,(struct sockaddr*)&srv,sizeof(srv));
   checkError(sts,__LINE__);

   char* response = responsehelp(sid, url);
   printf("%s\n",response);
   free(response);
   close(sid);
   return 0;
}



