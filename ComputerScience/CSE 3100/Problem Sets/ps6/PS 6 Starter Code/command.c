#include "command.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dirent.h>


char* makeFileList(char* path)
{
	DIR* theCWD = opendir(path);
	struct dirent buf;
	struct dirent* cur = NULL;
	readdir_r(theCWD,&buf,&cur);
	int ttlBytes = 0;
	while(cur != NULL) {
		ttlBytes += strlen(cur->d_name) + 1;
		readdir_r(theCWD,&buf,&cur);
	}
	char* txt = malloc((ttlBytes + 10)*sizeof(char));
	rewinddir(theCWD);
	readdir_r(theCWD,&buf,&cur);
	*txt = 0;
	while(cur != NULL) {
		strcat(txt,cur->d_name);
		strcat(txt,"\n");
		readdir_r(theCWD,&buf,&cur);
	}
	closedir(theCWD);
	return txt;
}

int getFileSize(char* fName)
{
	FILE* f = fopen(fName,"r");
	fseek(f,0,SEEK_END);
	long sz = ftell(f);
	fclose(f);
	return (int)sz;
}

void sendFileOverSocket(char* fName,int chatSocket)
{
  /*
    TODO: Open the file, and send it over the socket.
   */
  // init bufs and vars
  FILE* fd = fopen(fName,"r");
  int size = getFileSize(fName);
  char* buf = (char*)malloc(size*sizeof(char));
  int index = 0;
  int cur = fgetc(fd);
  while(cur != EOF){
      buf[index] = cur;
      index++;
      cur = fgetc(fd);
  }
  send(chatSocket, buf, size, 0);
  fclose(fd);
  free(buf);
}

void receiveFileOverSocket(int sid,char* fname,char* ext,int fSize)
{

  /*
    TODO: fsize is the size of the file in bytes. Allocate a buffer to store the file, and use the recv function to recieve the file.

   */
  // init variables
  int read = 0;
  int left = fSize;
  char* buf = malloc(sizeof(char)*fSize);
  // while loop for reading and counting through
  while(left != 0) {
      int num = recv(sid, buf+read,left,0);
      read += num;
      left -= num;
  }

  char fn[512];
  strcpy(fn,fname);
  strcat(fn,ext);
  FILE* fd = fopen(fn,"w");
  /*
    TODO: fwrite the file contents to fd, close fd, and then free the allocated buffer.
   */
  fwrite(buf,sizeof(char),fSize,fd);
  fclose(fd);
  free(buf);
}
