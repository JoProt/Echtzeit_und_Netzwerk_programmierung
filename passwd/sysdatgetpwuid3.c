#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>

#include "print_passwd.c"

int main(int argc, char *argv[]) {
        struct passwd *ergebnis;
		struct _IO_FILE *pw;
	
		if(argc != 2) {
			printf("Bitte geben sie nur die UID an.\n");
			exit(EXIT_FAILURE);
		}

		
		pw = fopen ("/etc/passwd", "r");
		while((ergebnis = fgetpwent(pw)) != NULL) {
			if((long)ergebnis->pw_uid == atoi(argv[1])) {
				writePW(ergebnis);
			}
		}
		
		
        exit EXIT_SUCCESS;
}
