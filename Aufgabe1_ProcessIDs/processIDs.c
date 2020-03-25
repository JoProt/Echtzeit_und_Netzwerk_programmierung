#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main (int argc, char* argv[], char* envp[]){
 printf("--------------------------------------------\n");

//process id
        if(getpid()< 0){
                printf("Error Prozess ID");
        }
        else{
        printf("Prozess ID: %d\n", getpid());
        }
//parent process id
         if(getppid()< 0){
                printf("Error Parent Prozess ID");
        }
        else{
        printf("Parent Prozess ID: %d\n", getppid());
        }
// user id
        if(getuid()< 0){
                printf("Error Real User ID");
        }
        else{
        printf("Real User ID: %d\n", getuid());
        }

//group id
        if(getgid()< 0){
                printf("Error Real Group ID");
        }
        else{
        printf("Real Group ID: %d\n", getgid());
        }

//effektive user id
        if(geteuid()< 0){
                printf("Error Effektive UID");
        }
        else{
        printf("Effektive User ID: %d\n", geteuid());
        }
//effektive group id
        if(getegid()< 0){
                printf("Error Effektive Group ID");
        }
        else{
        printf("Effektive Group ID: %d\n", getegid());
        }

        printf("--------------------------------------------\n");
        return EXIT_SUCCESS;
}
