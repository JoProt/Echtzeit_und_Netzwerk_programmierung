#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
        /*functions to manipulate environment: getenv(); putenv(); setenv(); unsetenv(); clearenv()*/


        /*getenv()*/
        printf("getenv(HOME): %s", getenv("HOME"));

        /*the other functions cant be called, because it's not allowed in posic standart and ANSI-C*/



        return EXIT_SUCCESS;
