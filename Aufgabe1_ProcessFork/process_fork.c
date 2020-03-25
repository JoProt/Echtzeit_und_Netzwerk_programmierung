#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[], char* envp[]){
        pid_t childpid;
        int vater, kind;
        for(int i = 1; i < argc; i++){
                printf("Auftrag: %s\n",argv[i]);
                childpid = fork();

                if(childpid < 0) printf("!Fehler beim Fork()!\n");

                if(childpid == 0){
                        // im Kind Prozess

                        kind = getpid();

                }
                else{
                        //im Vater

                        vater = getpid();

                }

                printf("---------------------------------------------------------------------\n");
                printf("Top-Server %d: Auftrag: %s an Sub-Server: %d weitergegeben.\n", vater, argv[i], kind);
                printf("Sub-Server %d: Auftrag: %s von Top-Server: %d erhalten.\n", kind, argv[i], vater);
                printf("---------------------------------------------------------------------\n");

        }
        return EXIT_SUCCESS;
}
