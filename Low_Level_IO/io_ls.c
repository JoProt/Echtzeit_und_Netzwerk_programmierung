#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
        struct stat st;

        stat("./dummy", &st);
        printf("filesize (byte): %ld\nblocksize (byte): %ld\nblocks: %ld\n", st.st_size, st.st_blksize, st.st_blocks);


        return (EXIT_SUCCESS);
}
~
~
~
