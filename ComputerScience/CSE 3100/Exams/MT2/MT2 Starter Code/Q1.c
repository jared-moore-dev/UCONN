#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READEND 0
#define WRITEEND 1

int main(int argc,char* argv[]) {
    /* TODO: Q1
       Implement "ls /dev | xargs | cut -d ' ' -f<a>-<b>"
       where <a> and <b> are from the command line
       The use of system is prohibited.
    */
    if (argc < 3) {
        printf("Too many arguments given, this program expects 2 args");
        exit(1);
    }
    char *arg1 = argv[1];
    char *arg2 = argv[2];

    // format command
    char *command = (char *) malloc(6);
    command[0] = '-';
    command[1] = 'f';
    strcat(command, arg1);
    strcat(command, "-");
    strcat(command, arg2);
    // strcat(command, "/0");

    int p1[2], p2[2];
    if (pipe(p1) == -1) exit(-1);
    if (fork() == 0) {
        // First Child
        // Child makes their stdout p1's standard in
        close(p1[READEND]); // Close unused read// Close Write
        dup2(p1[WRITEEND], STDOUT_FILENO); // Write to the write end of pipe1
        close(p1[WRITEEND]); // Close P1's write end, as its no longer used

        int status = execlp("ls", "ls", "/dev", NULL);
        if (status == -1) {
            printf("Ya done fucked up again, check pipe 1");
            exit(-1);
        }
    } else {
        if (pipe(p2) == -1) exit(-1);
        if (fork() == 0) {
            // Second Child
            // Child takes from their read end of c2toP
            close(p1[WRITEEND]); // Close the write end of P1
            close(p2[READEND]); // Close the read end of P2

            dup2(p2[WRITEEND], STDOUT_FILENO); // make the stdout the write end of pipe 2
            dup2(p1[READEND], STDIN_FILENO); // make the stdin end the read end of pipe 1
            int status2 = execlp("xargs", "xargs", NULL); //
            if (status2 == -1) {
                printf("Ya done fucked up again, check pipe 2");
                exit(-1);
            }

        } else {
            //Parent
            //Parent makes their standard input C2->P's pipe read end
            //Parent displays this to their standard output
            close(p1[READEND]); // Close pipes for child 1
            close(p1[WRITEEND]); // Close pipe for child 1
            close(p2[WRITEEND]); // close write of pipe 2

            dup2(p2[READEND], STDIN_FILENO); // make The Read end of pipe2 to standard output
            close(p2[READEND]); //close the read end of pipe 2
            int status3 = execlp("cut", "cut", "-d ", command, NULL);
            if (status3 == -1) {
                printf("Ya done fucked up again, check your parent");
            }
        }
    }
    return 0;
}