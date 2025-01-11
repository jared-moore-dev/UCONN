#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include "guess-mt.h"

gmn_t* gmn_init(int val)
{
    gmn_t* pg = malloc(sizeof(gmn_t));
    pg->value = val;
    pg->guess = 0;     /* number guessed by the parent */
    pg->result = 2;    /* -1, 0 or 1 depending on the guess; initialized to arbitrary value of 2*/
    pg->status = 0;    /* Predicate to check if a guess is made */
    snprintf(pg->message, MSG_BUF_SIZE, "Guess a number between 1 and %d.\n", MAX_VALUE); 
    return pg;
}  

int gmn_check(gmn_t *pg)
{
    /* TODO
     * Implement a checker.
     * If the guess is correct, send message "Congrats! You guessed the number %d.\n". 
     * If the guess is smaller than the value, send the message "Your guess is smaller than the value\n".
     * If the guess is larger than the value, send the message "Your guess is greater than the value\n".
     * Return the appropriate int value.
    */
    int checknum = -400;
    if (pg->value == pg->guess) {
        // guess is correct
        sprintf(pg->message,"Congrats! You guessed the number %d.\n", pg->guess);
        checknum = 0;
    }
    else if (pg->value < pg->guess) {
        // value below guess, guess is too high
        sprintf(pg->message, "Your guess is greater than the value\n");
        checknum = -1;
    }
    else if (pg->value > pg->guess){
        sprintf(pg->message, "Your guess is smaller than the value\n");
        checknum = 1;
    }
    return checknum; /* Fix me */
}

