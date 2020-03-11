#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[], char *envp[])
{
        printf("Argument Counter: %d \n", argc-1);


        if(argc <= 1){
        printf("Keine Argumente uebergeben");
        }
        else{

                for(int i = 1; i < argc; i++){

                        printf("argv[%d]: %s\n", i, argv[i]); /*while using *argv[i] you'll get an Memory Access Error*/

                }
        }


        printf("---Environtment Variablen---");

        while (*envp != NULL){
                printf("%s\n", *(envp++));
        }


        return EXIT_SUCCESS;
}

