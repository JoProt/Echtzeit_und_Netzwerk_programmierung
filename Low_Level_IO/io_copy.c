#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv){

        ssize_t ret_in, ret_out;
        int buffer = *argv[1];
        int fd_oeffnen;
        int fd_kopiert;

        char* charBuf[buffer];
        if((fd_oeffnen = open("./dummy", O_RDONLY))==-1){
                  printf("Oeffnen der zu kopierenden Datei fehlgeschlagen\n");
                  return (EXIT_FAILURE);
         }
         if((fd_kopiert = open("./kopiert_dummy", O_CREAT | O_WRONLY))==-1){
           printf("Oeffnen einer neuen Datei zum kopieren fehlgeschlagen\n");
           return (EXIT_FAILURE);
         }
        else{
                while((ret_in = read (fd_oeffnen, &charBuf, buffer)) > 0){
                       ret_out = write(fd_kopiert, &charBuf, (ssize_t) ret_in);
                         if(ret_out != ret_in){  //Write error
                             printf("write error\n");
                             return (EXIT_FAILURE);
                         }
                }
                printf("... kopiert.\n");

        }




        close(fd_oeffnen);
        close(fd_kopiert);
        return EXIT_SUCCESS;
}
~
~
~
