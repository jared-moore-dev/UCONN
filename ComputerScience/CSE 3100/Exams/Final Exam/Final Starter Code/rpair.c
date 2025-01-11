#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <string.h>
#include <errno.h>
#include <math.h>

/* TODO: Complete the main and createSamples functions for Q1 */
//
long createSamples(unsigned wID,long nbSamples,double d)
{
    long ttl = 0; // Number of events detected by a process
    unsigned seed = wID; //seed for random number generation

    /* TODO
     * This function is called by all processes to perform nbSamples number of trials
     * You may use rand_r() from stdlib.h to generate random numbers between 0 and RAND_MAX. Seed value for rand_r() is given above.
     * The usage of rand_r() can be found in the manual page: man -S2 rand.
     * The random numbers can be normalized to an interval [0, 1) by dividing them by RAND_MAX.
     * The function returns the number of events occurred in nbSamples trials.
     */
    for (int i = 0; i < nbSamples; i++)
    {
        double x = ((double) rand_r(&seed)) / RAND_MAX;
        double y = ((double) rand_r(&seed)) / RAND_MAX;
        if (fabs(x - y) < d)
        {
            ttl++;
        }
    }
    return ttl;
}

int main(int argc,char* argv[])
{
    if (argc < 4) {
        printf("usage: rpair <d> <samples> <workers>\n");
        exit(1);
    }
    float d = atof(argv[1]);
    long s  = atol(argv[2]); // total number of trials to be executed
    int nbW = atoi(argv[3]); // number of worker processes

    long ttl = 0; //total number of events
    double p = 0; //Probability of the occurence of events

    const char* zone = "/memzone1";
    int md = shm_open(zone, O_RDWR|O_CREAT,S_IRWXU);
     int uni = ftruncate(md, 4096);
    int* t = mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_SHARED, md, 0);
    memset(t,0,4096);

    // initialize starting values
    long nbsamples = s / nbW; // passed as nbsamples to createsamples
    long remainder = s % nbW; // calculates remainder to add to process nbw-1 (the last process)
    int pid = 0;
    int pids[nbW];

    for (int i = 0; i < nbW; i++)
    {
        // printf("<parent> looping and forking \n");
        pid = fork();
        if (pid == 0) {
            // This is the child, or the first run
            if (i == nbW - 1) { nbsamples += remainder; }
            // printf("<Child %ld> im a child with id %d and doing %ld iterations!\n", (long)getpid(), i, nbSamples);
            t[i] = createSamples(i, nbsamples, d);
            exit(0);
        } else {
            // This is the parent
            pids[i] = pid;
        }


    }
    // Only the parent will get here

    for (int i = 0; i < nbW; i++)
    {
        int status;
        waitpid(pids[i], &status, 0);
        ttl += t[i];
    }

    p = (double)ttl/s;
    printf("Total trials = %ld \t Total events = %ld \t Probability = %lf\n",s,ttl,p);
    munmap(t, 4096);
    shm_unlink(zone);
    close(md);
    return 0;
}