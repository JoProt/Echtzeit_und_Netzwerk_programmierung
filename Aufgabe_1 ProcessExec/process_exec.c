#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (int argc, char * argv[]){
        char *argumente[] = {argv[1], NULL};

        switch (argc){

        case 1:
                printf("kein Aufrufargument\n");
                break;
        case 2:
                printf("argument = %s \n", argumente[0]);
                printf("execute ...\n");
                execvp(argumente[0], argumente);
                break;
        default:
                printf("nur 1 Aufrufargument\n");
                break;

        }

        return EXIT_SUCCESS;
}
