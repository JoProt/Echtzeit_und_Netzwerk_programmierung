#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int main(){

        pid_t childpid;
        int exitcode = 5;
        char *c = "Hello";              // mein string fuer segmentation fault
        childpid = fork();
        if(childpid < 0) printf("\n \n ! --- Error Fork() --- ! \n \n");

        if(childpid == 0){
                //kind
                        int eingabe = 1;

                        printf("\n \n --- Gebe Werte 1 - 5 ein, fuer jeweilige Terminierung. --- \n \n");

                        printf("1: normale Terminierung mit EXIT_SUCCESS.\n");
                        printf("2: normale Terminierung mit EXIT_FAILURE.\n");
                        printf("3: normale Terminierung mit frei wahelbaren Exit-Code (Random).\n");
                        printf("4: abnormale Terminierung mit Division durch 0 (Integer).\n");
                        printf("5: normale Terminierung durch unzulaessigen Speicherbereich.\n");
                        printf("0: beenden.\n");
                        printf("Eingabe: ");

                        printf("%d\n",eingabe);

                switch(eingabe){

                        case 1:
                                printf("EXIT_SUCCESS ... \n");
                                return EXIT_SUCCESS;
                        case 2:
                                printf("EXIT_Failure ... \n");
                                return EXIT_FAILURE;
                        case 3:
                                printf("EXIT Code: %d  ... \n", exitcode);
                                return exitcode;
                        case 4:
                                printf("Divison durch 0 ... \n");
                                return (eingabe/0);
                        case 5:
                                printf("unzulaessiger Speicherbereich ... \n");
                                return(c[10] = 'x'); 
			case 0:
                                printf("Beende ... \n");
                                break;

                }

        }
        else{
                //vater
                 // status kind prozess
                 int status;

                if ( waitpid(childpid, &status, 0) == -1 ) {
                        printf("waitpid() failed");
                        exit(EXIT_FAILURE);
                }

                if ( WIFEXITED(status) ) {
                        int es = WEXITSTATUS(status);
                        printf("Normale Terminierung mit Exit Status: %d\n", es);
                }
                else if(WIFSIGNALED(status)){
                        int signo;
                        signo = WTERMSIG(status);
                        printf("Abnormale Terminierung mit Exit Status: %d\n", signo);

                }

        }


        return EXIT_SUCCESS;

}

