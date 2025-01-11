#include "token.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int readToken(Token* t) {
/* Q3.1 Implement the read Token function 
    * TODO parse the token t to assign values to t->type and t->value fields
    * return a boolean value to indicate EOF */
    // if token is whitespace, skip to next
    char c = getchar();
    if (c =='+'|| c=='-'|| c=='*'||c=='/'||c=='p'||c=='q'||c==EOF){
        t->type = c;
    } else {
        t->type = LIT;
        t->value = (int)c;
    }
   return (c == EOF); /* fix me */
}
