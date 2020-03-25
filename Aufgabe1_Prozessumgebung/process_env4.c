#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[], char *envp[])
{
        /*functions to manipulate environment: getenv(); putenv(); setenv(); unsetenv(); clearenv()*/


        /*getenv()*/
        printf("getenv(HOME): %s\n", getenv("HOME"));

        /*putenv()*/
        putenv("env1=ich habe hallo gesetzt");
        printf("putenv(Hallo): %s\n", getenv("env1"));
        /*setenv()*/
        setenv("home", ":~/Echtzeit_und_Netzwerk_Programmierung/process_env$",1);
        printf("setenv(home,:~/Echtzeit_und_Netzwerk_Programmierung/process_env$,1): %s \n ",getenv("home"));

        /*unsetenv()*/
        unsetenv("home");
        printf("unsetenv(home) -> home = %s\n",getenv("home"));

        /*clearenv()*/
        clearenv();
           printf("clearenv()am Beispiel getenv(HOME) = %s \n",getenv("HOME"));
           printf("clearenv()am Beispiel getenv(LANG) = %s \n",getenv("LANG"));
           printf("clearenv()am Beispiel getenv(PWD) = %s \n",getenv("PWD"));




        return EXIT_SUCCESS;
}
