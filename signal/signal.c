#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signal) {
        if(signal == SIGINT) {
                printf("SIGINT nummer: %d\n", signal);
                exit(EXIT_SUCCESS);
        } else {
                printf(stderr, "Falsches Signal: %d\n", signal);
        }
}

int main() {
        struct sigaction saction;
        saction.sa_handler = handler; //action handler

        sigfillset(&saction.sa_mask);
        printf("!!! endlos schleife ... \n");

        while(1){
                if(sigaction(SIGINT, &saction, NULL) == -1) {
                        perror("Error: SIGINT handle error\n");
                }
        }
}