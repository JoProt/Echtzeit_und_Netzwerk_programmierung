#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main (int argc, char * argv[]){

        char *argumente[argc];


        for (int i = 0; i <= argc; i++){

                argumente[i] = argv[i+1];
                if(i == argc-1) argumente[i] = NULL;

        }

        switch (argc){

        case 1:
                printf("kein Aufrufargument\n");
                break;
        default:
                printf("execute ...\n");
                execvp(argumente[0], argumente);
                break;
        }

        return EXIT_SUCCESS;
}
