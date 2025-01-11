#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strl(char* s){
    int len = 0;
    while(s[len] != '\0'){
        len++;
    }
    return len;
}
char* strreverse(char* s){
    int l = strl(s);
    int len = l;
    char* nstr = (char*)malloc(sizeof(char)*l);
    int i = 0;
    for(; l>0; l--){
        nstr[i] = s[l-1];
        i++;
    }
    nstr[len] = '\0';
    return nstr;
}
int main(){
    // 6 long
    char* bs = "Bingus";
    printf("%d\n",strl(bs));
    printf("%s\n",strreverse(bs));
    return 0;
}