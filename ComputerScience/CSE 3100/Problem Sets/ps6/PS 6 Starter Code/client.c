#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>

#include "command.h"
void checkError(int status,int line)
{
   if (status < 0) {
      printf("socket error(%d)-%d: [%s]\n",getpid(),line,strerror(errno));
      exit(-1);
   }
}

void doLSCommand(int sid);
void doExitCommand(int sid);
void doGETCommand(int sid);
void doPUTCommand(int sid); 


int main(int argc,char* argv[]) 
{
   // Create a socket
   int sid = socket(PF_INET,SOCK_STREAM,0);
   struct sockaddr_in srv;
   struct hostent *server = gethostbyname("localhost");
   srv.sin_family = AF_INET;
   srv.sin_port   = htons(8080);
   memcpy(&srv.sin_addr.s_addr,server->h_addr,server->h_length);
   int status = connect(sid,(struct sockaddr*)&srv,sizeof(srv));
   checkError(status,__LINE__);
   int done = 0;
   do {
      char opcode[32];
      scanf("%s",opcode);
      if (strncmp(opcode,"ls",2) == 0) {
         doLSCommand(sid);
      } else if (strncmp(opcode,"get",3)==0) {
         doGETCommand(sid);
      } else if (strncmp(opcode,"put",3)==0) {
         doPUTCommand(sid);
      } else if (strncmp(opcode,"exit",4) == 0) {
         doExitCommand(sid);
         done = 1;
      }
   } while(!done);

   return 0;
}

void doLSCommand(int sid)
{
   Command c;
   Payload p;
   int status;
   char* buf;
   c.code = htonl(CC_LS);
   memset(c.arg, 0, sizeof(c.arg));
   /*
     TODO: Send Command c to the server. Then, use recv to read the response of the server into Payload p. Following this payload, the actual actual message will be sent to the client by the server. Payload p has a length field, which is the length of this message. 

     You should store the list of files in buf. 
    */
   // first send c the message save the response in stautus
   status = send(sid,&c,sizeof(c),0);
   checkError(status,__LINE__);
   // next, recieve the message and store it in payload
   status = recv(sid, &p,sizeof(p),0);
   checkError(status, __LINE__);
   //decode payload code and length
   p.code = ntohl(p.code);
   p.length = ntohl(p.length);
   // prep env to read through the payload
   int start = 0;
   int end = p.length;
   buf = malloc(sizeof(char)*p.length);
   // Read the buffer save it
   while (end != 0){
       int num = recv(sid, buf+start,end,0);
       checkError(status,__LINE__);
       start += num;
       end -= num;
   }
   if(p.code == PL_TXT) 
      printf("Got: [\n%s]\n",buf);
   else { 
      printf("Unexpected payload: %d\n",p.code);
   }
   free(buf);
}

void doGETCommand(int sid) 
{
   Command c;
   Payload p;
   int status;
   printf("Give a filename:");
   char fName[256];
   scanf("%s",fName);	
   /*
     TODO: Prepare Command c, send it, and recv back into Payload p. 

     
     Something that is important to note: payload p contains the code and length as integers in network byte order. You need to use the proper function to convert p.length to host byte order. What function would you use for this? It's either htonl, htons, ntohl, or ntohs.
    */
   // translate CC_get and store in c.code
   c.code = htonl(CC_GET);
   // copy from fname to c.arg, trim the last char and add a 0
   strncpy(c.arg,fName,255);
   c.arg[255] = 0;
   //send command, check, recieve, check
   status = send(sid,&c,sizeof(c),0);
   checkError(status,__LINE__);
   status = recv(sid,&p,sizeof(p),0);
   checkError(status, __LINE__);
   // Translate code and length
   p.code = ntohl(p.code);
   p.length = ntohl(p.length);

   receiveFileOverSocket(sid,c.arg,".download",p.length);
   printf("transfer done\n");
}

void doPUTCommand(int sid) 
{
   Command c;
   Payload p;
   int status;
   printf("Give a local filename:");
   char fName[256];
   scanf("%s",fName);
   /*
     TODO: Prepare Command c, and send it to the server. Then, prepare the Payload p, and send it to the server.

     Be sure c.code, p.length are in network byte order. 
    */
   //prep the code
   c.code = htonl(CC_PUT);
   strncpy(c.arg,fName,255);
   c.arg[255] = 0;
   // send command
   status = send(sid,&c,sizeof(c),0);
   checkError(status,__LINE__);
   // send file
   int size = getFileSize(c.arg);
   p.code = htonl(PL_FILE);
   p.length = htonl(size);
   status = send(sid,&p,sizeof(p),0);
   checkError(status,__LINE__);


   sendFileOverSocket(c.arg,sid);
   printf("transfer done\n");
}

void doExitCommand(int sid)
{
   Command c;
   Payload p;
   int status;
   c.code = htonl(CC_EXIT);
   memset(c.arg, 0, sizeof(c.arg));
   status = send(sid,&c,sizeof(c),0);checkError(status,__LINE__);
}
