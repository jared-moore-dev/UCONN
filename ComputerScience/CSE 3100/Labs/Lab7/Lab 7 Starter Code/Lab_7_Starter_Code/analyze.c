#include "analyze.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>

void analyzeURL(char* url,char* host,int* port,char* doc)
{
   /* TODO: Implement the URL decomposition.
    * input: URL the given url
      output: host : where you place the host part of the URL
              port : where you place the port number (if any)
              doc  : where you place the document name
   */
   char* cur = url;
    if (strstr(cur,"//")!=NULL){
        cur= strstr(url, "//")+2;
    }
    //gets hostname with or without port
    if (strstr(cur, ":") !=NULL){
        // get hostname from url with port number
        size_t dist = strstr(cur, ":")- cur;
        strncpy(host,cur,dist);
        host[dist] = '\0';
        cur=strstr(cur,":")+1;
        char temp[10];
        //gets port number
        dist = strstr(cur, "/") - cur;
        strncpy(temp,cur,dist);
        *port = atoi(temp);
        cur=strstr(cur,"/");
    }else{
        size_t dist = strstr(cur, "/")-cur;
        strncpy(host,cur,dist);
        host[dist] = '\0';
        cur=strstr(cur,"/");
    }
    //gets end if exists
    int count = 0;
    while(*cur != 0){
        *doc = *cur;
        doc++;
        cur++;
        count++;
    }
    *doc = '\0';
}
