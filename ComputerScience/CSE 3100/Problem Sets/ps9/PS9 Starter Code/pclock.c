#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include "guess-mt.h"

typedef struct thread_arg_tag {
    gmn_t* sb;
    /* TODO
     * Add mutexes and condition variables required
    */
    pthread_mutex_t lock;
    pthread_cond_t cond_p;
    pthread_cond_t cond_c;
} thread_arg_t;

void *thread_c(void* consumer_thread_data);
void *thread_p(void* producer_thread_data);

int main(int argc,char* argv[])
{
    /* TODO
     * Create an instance of thread_arg_t and initialize it. The value to be guessed is taken as input from the command line arguments.
     * Create two threads - one each for the parent and child
     * Reap the thread resources and destroy the mutexes and condition variables used.
    */
    // Init the Parent and Child, and lock, values, and instance
    int val = atoi(argv[1]);
    thread_arg_t* inst;
    inst->sb = gmn_init(val);
    pthread_mutex_init(&inst->lock, NULL);
    pthread_cond_init(&inst->cond_p, NULL);
    pthread_cond_init(&inst->cond_c, NULL);

    // Create the workers
    pthread_t pthread;
    pthread_t cthread;
    pthread_create(&pthread, NULL, thread_p, inst);
    pthread_create(&cthread, NULL, thread_c, inst);
    // Join the workers
    pthread_join(pthread, NULL);
    pthread_join(cthread, NULL);
    // reap the children
    pthread_mutex_destroy(&inst->lock);
    pthread_cond_destroy(&inst->cond_p);
    pthread_cond_destroy(&inst->cond_c);
    return 0;
}

void* thread_p(void *producer_thread_data) {
   /* TODO
    * This is a parent thread.
    * repeat the following until guess is correct
        guess a number between min and max. initially max is set to MAX_VALUE
        send the guess to the child and wait for a result (thread_c)
        if result is 0 i.e. you guessed the number correctly, end the thread
        if result is -1 or 1, update the search interval
   */
   // cast void pointer
   thread_arg_t* threads = (thread_arg_t*)producer_thread_data;

   int min = 0;
   int max = MAX_VALUE;
   // Lock the thread
    pthread_mutex_lock(&threads->lock);
    // calculate median for first guess
    int median = (max - min) / 2;
    threads->sb->guess = median;
    threads->sb->status = 1;
    pthread_cond_signal(&threads->cond_c);
    printf("My guess is %d.\n", threads->sb->guess);

   while(threads->sb->result != 0){
       while(threads->sb->status != 0){
           pthread_cond_wait(&threads->cond_p, &threads->lock);
       }
       if(threads->sb->result==0){
           pthread_cond_signal(&threads->cond_c);
           pthread_mutex_unlock(&threads->lock);
           pthread_exit(0);
       }
       if (threads->sb->result == 1){
           // printf("%s", threads->sb->message);
           min = threads->sb->guess + 1;
           // median Calculation
           median = min + (max - min) / 2;
           threads->sb->guess = median;
           threads->sb->status = 1;
           // Make Guess
           printf("My guess is %d.\n", median);

       }
       else if (threads->sb->result == -1){
           // printf("%s", threads->sb->message);
           max = threads->sb->guess;
           // median calculation
           median = min + (max - min) / 2;
           threads->sb->guess = median;
           threads->sb->status = 1;
           // Make Guess
           printf("My guess is %d.\n", median);

       }
       pthread_cond_signal(&threads->cond_c);
       pthread_mutex_unlock(&threads->lock);
   }
   pthread_exit(0);
   return NULL;
}

void* thread_c(void * consumer_thread_data)
{
    /* TODO
     * This is a child thread.
     * repeat the following until guess is correct 
     *      wait for a guess from the parent (thread_p) 
     *      call gmn_check() to compare the guess with the user input value
     *      send the result to thread_p
     */
    thread_arg_t* threads = (thread_arg_t*)consumer_thread_data;
    pthread_mutex_lock(&threads->lock);
    while(threads->sb->result != 0){

        while(threads->sb->status != 1){
            pthread_cond_wait(&threads->cond_c, &threads->lock);
        }
        if(threads->sb->result==0){
            pthread_cond_signal(&threads->cond_p);
            pthread_mutex_unlock(&threads->lock);
            pthread_exit(0);
        }
        threads->sb->result = gmn_check(threads->sb);
        printf("%s\n", threads->sb->message);
        threads->sb->status = 0;
        pthread_cond_signal(&threads->cond_p);
        pthread_mutex_unlock(&threads->lock);

    }
    pthread_exit(0);
    return NULL;
}