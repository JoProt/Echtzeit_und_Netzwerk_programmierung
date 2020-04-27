#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
int main(int argc, char **argv){

        if(argc != 2){
                printf("Usage: Uebergabeparameter == Buffergroeße");
        }
        else{
                int filesize = atoi(argv[1]);
                if(isdigit(*argv[1]) == 0) printf("keine Zahl uebergeben\n");
                else{
                        int fd;
                        int buffer = 1;

                        fd = open("dummy",O_CREAT | O_WRONLY,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);

                        lseek(fd, filesize -1, SEEK_END);
                        write(fd, &buffer, 1);

                        printf("\n \n!!! --- Beachte, Open() ueberschreibt NICHT!. Loeschen der alten Dummy-Datei ist noetig \n \n \n");
                }
        }

        return EXIT_SUCCESS;
}
~
~
~
