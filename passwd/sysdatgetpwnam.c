#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>

#include "print_passwd.c"

int main(int argc, char *argv[]) {
        struct passwd *ergebnis;
		
		if(argc != 2) {
			printf("Nur einen User angeben\n");
			exit(EXIT_FAILURE);
		}

        if((ergebnis = getpwnam(argv[1])) != NULL) {
			printf("Write gets called...\n");
            writePW(ergebnis);
        } else {
            perror("getpwnam()");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
}
