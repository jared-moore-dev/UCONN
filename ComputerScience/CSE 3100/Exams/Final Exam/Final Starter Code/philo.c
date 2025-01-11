#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

#define MICROSEC 5.0
#define THINK 0
#define HUNGRY 1
#define EAT 2

/* TODO: Complete the ADT Table and functions makeTable, clearTable, muse and main for Q3 */

typedef struct Table {
   int nump; // number of philosiphers
   pthread_mutex_t lock; // lock a fork
   pthread_cond_t* cond; // cond for letting phil know fork is available
   int* forkstatus; // status of the fork
} Table;

/* This is the ADT to store information for each philosopher */
typedef struct PhiloTag {
   int pid; //ID
   int state; //activity state
   int ate; //number of times eaten
   int cycle; //number of cycles left
   Table* t; //shared Table ADT
} Philosopher;

Table* makeTable(int n)
{
   Table* t = (Table*)malloc(sizeof(Table));
   /* TODO
    * Initialize an instance of the Table ADT that seats n philosophers
    */
   t->nump = n;
   t->cond = (pthread_cond_t*)malloc(n*sizeof(pthread_cond_t));
   t->forkstatus = (int*)calloc(n, sizeof(int));
   pthread_mutex_init(&t->lock, NULL);
   for(int i = 0; i < n; i++){
       pthread_cond_init(&t->cond[i], NULL);
   }
   return t;
}

void clearTable(Table* t)
{
   pthread_mutex_destroy(&t->lock);
    for(int i = 0; i < t->nump; i++){
        pthread_cond_destroy(&t->cond[i]);
    }
}

void doActivity(int activity,Philosopher* p,unsigned* seed)
{
   if (activity == THINK)
      if (p->state != EAT) exit(1);
   if (activity == HUNGRY)
      if (p->state != THINK) exit(2);
   if (activity == EAT)
      if (p->state != HUNGRY) exit(3);
   p->state = activity;
   if (p->state ==  HUNGRY)
      return;
   else {
      char* actName[2] = {"thinking", "eating"};
      double v = ((double)rand_r(seed)) / RAND_MAX * MICROSEC;
      p->ate += p->state == EAT;
      printf("philo [%d] is %s...\n",p->pid, actName[p->state==EAT]);
      // usleep(v);
   } 
}

void* muse(Philosopher* p)
{
   unsigned seed = (unsigned)pthread_self(); //seed used to put each philosopher to sleep for a random period of time if the state is thinking or eatingcofactor
   for(int i=0; i<p->cycle; i++){
       int left = p->pid -1;
       int right = p->pid;
       if(p->pid == 0){
           left = p->t->nump-1;
       }
       if(p->state == THINK){ // LDM is thinking
           doActivity(HUNGRY, p, &seed);
           p->state = HUNGRY;
       }
       if(p->state == HUNGRY){ // LDM is thinking
           doActivity(EAT, p, &seed);
           p->state = EAT;
       }
       pthread_mutex_lock(&p->t->lock);
       // critical Section
       // Grab left fork
       while(p->t->forkstatus[left] != 0){ // while you cannot grab a fork
           pthread_cond_wait(&p->t->cond[left], &p->t->lock); // wait for your fork
       }
       p->t->forkstatus[left] = 1;

       // Grab Right Fork
       while(p->t->forkstatus[right] != 0){ // while you cannot grab a fork
           pthread_cond_wait(&p->t->cond[right], &p->t->lock); // wait for your fork
       }
       p->t->forkstatus[right] = 1;

       // if you're ready to eat, eat
       if(p->state == EAT){
           doActivity(THINK, p, &seed); // Run func
           p->state = THINK; // You're now full, start thinking
       }
       p->t->forkstatus[right] = 0;
       p->t->forkstatus[left] = 0;
       pthread_cond_signal(&p->t->cond[left]);
       pthread_cond_signal(&p->t->cond[right]);
       pthread_mutex_unlock(&p->t->lock);
   }

   return NULL;
}

int main(int argc,char* argv[])
{
   int n = atoi(argv[1]); // number of philosophers
   int c = atoi(argv[2]); //number of cycles to be completed by each philosopher
   /* TODO
    * This function sets up the multi-threaded computation of the dining philosopher's problem
    * Each thread calls the function muse to perform the prescribed cycles
    */
   Table* table = makeTable(n);
   Philosopher* LDM = (Philosopher*)malloc(sizeof(Philosopher)*n);
    pthread_t threads[n];
    // Initialize your Philisophical LDM's
   for(int i = 0; i < n; i++){
       LDM[i].t = table;
       LDM[i].ate = 0;
       LDM[i].cycle = c;
       LDM[i].state = THINK;
       LDM[i].pid = i;
       pthread_create(&threads[i], NULL, (void*) muse, &LDM[i]);
   }
   // Join your threads
    for(int i = 0; i < n; i++){
        pthread_join(threads[i], NULL);
    }
    // Print the results/runs
    for(int i = 0; i < n; i++){[=]
        printf("%d ate %d times\n", i, LDM[i].ate);
        // lel
    }
    // clear and free
    clearTable(table);
    free(LDM);
    return 0;
}
