#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[], char* envp[]){
        pid_t childpid;
        int vater = getpid();

        for(int i = 1; i < argc; i++){
                childpid = fork();

                if(childpid < 0){
                        printf("Fork() Fehler!");
                }
                if(childpid == 0){
                        printf("Sub-Server %d: Auftrag: %s von  Top-Server %d erhalten. \n \n", getpid(),argv[i], vater);

                        break;
                }
                else{
                        printf("Top-Server %d: Auftrag: %s  an  Sub-Server %d weitergeleitet. \n", vater,argv[i], childpid);

                        childpid = wait(NULL);
                }

        }
        return EXIT_SUCCESS;
}
