#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[], char *envp[]){

        if(getenv("PATH")!= NULL)       printf("PATH : %s\n", getenv("PATH"));
        else printf("Environment Variable PATH ist nicht installiert\n");

        if(getenv("HOME")!= NULL)       printf("HOME : %s\n", getenv("HOME"));
        else printf("Environment Variable HOME ist nicht installiert\n");

        if(getenv("LANG")!= NULL)       printf("LANG : %s\n", getenv("LANG"));
        else printf("Environment Variable LANG ist nicht installiert\n");

        if(getenv("LOGNAME")!= NULL)    printf("LOGNAME : %s\n", getenv("LOGNAME"));
        else printf("Environment Variable LOGNAME ist nicht installiert\n");

        if(getenv("TERM")!= NULL)       printf("TERM : %s\n", getenv("TERM"));
        else printf("Environment Variable TERM ist nicht installiert\n");

        if(getenv("TZ")!= NULL)         printf("TZ : %s\n", getenv("TZ"));
        else printf("Environment Variable TZ ist nicht installiert\n");



        return EXIT_SUCCESS;
}
