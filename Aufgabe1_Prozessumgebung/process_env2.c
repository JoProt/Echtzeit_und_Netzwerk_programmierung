#include <stdio.h>
#include <stdlib.h>

extern char **environ;

void printenv(){

        char *s = *environ;

        for (int i = 1; i <= s ; i++) {
                printf("%s\n", s);
                s = *(environ++);
        }

}


int main(int argc, char *argv[], char *envp[]){

        printenv();

        return EXIT_SUCCESS;
}
~
