#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[])
{
        if(argc != 3){
                printf("Bitte Dateinamen und Buffersize wie folgt angeben!\n");
                printf("./io_copy dateiname buffersize\n");
                return (EXIT_FAILURE);
        }

        else {
                 ssize_t in, out;
                  int output, input;

                  //verbinden von strings

                char* s = "Kopierte-";
                char * connectednames;

                connectednames = malloc(strlen(argv[1])+ strlen(s));

                strcpy(connectednames, s);
                strcat(connectednames,argv[1]);

   //---------------

                //buffer zweiter parameter in argv
          int buffer = *argv[2];
          char buf[buffer];     // array of char mit groesse des buffers (argv[2])

          //Datei oeffnen
          if((input = open(argv[1], O_RDONLY))==-1){
                printf("Oeffnen der zu kopierenden Datei fehlgeschlagen\n");
                return (EXIT_FAILURE);
          }
          if((output = open(connectednames, O_CREAT | O_WRONLY, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH))==-1){
                printf("Oeffnen einer neuen Datei zum kopieren fehlgeschlagen\n");
                return (EXIT_FAILURE);
          }


          //kopieren
          while((in = read(input, &buf, buffer)) > 0){
                out = write(output, &buf, (ssize_t)in);
                        if(out != in){
                                printf("Datei konnte nicht vollstaendig kopiert werden\n");
                                return (EXIT_FAILURE);
                        }
          }
          printf("... Datei wurde kopiert.\n");

          close(input);
          close(output);
        }
  return (EXIT_SUCCESS);
}
