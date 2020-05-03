#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
        if(argc != 2){
                printf("Usage: Uebergabeparameter ist der Filename \n");
                return EXIT_FAILURE;
        }
        else{
        struct stat st;
        char *name = argv[1];
        int fd;

        if( fd = open(argv[1], O_WRONLY)!=-1) {
                        stat(name, &st);
                        printf("filesize (byte): %ld\nblocksize (byte): %ld\nblocks: %ld\n", st.st_size, st.st_blksize, st.st_blocks);
                }
        else {
                        printf("Datei nicht gefunden\n");
                        return (EXIT_FAILURE);
                }


        return (EXIT_SUCCESS);
        }
}
