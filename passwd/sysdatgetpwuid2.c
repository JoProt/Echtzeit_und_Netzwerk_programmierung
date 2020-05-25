#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>

#include "print_passwd.c"

int main(int argc, char *argv[]) {
        struct passwd *ergebnis;
	
		if(argc != 2) {
			printf("Bitte geben sie nur die UID an.\n");
			exit(EXIT_FAILURE);
		}

		setpwent();
		while((ergebnis = getpwent()) != NULL) {
			if((long)ergebnis->pw_uid == atoi(argv[1])) {
				writePW(ergebnis);
			}
		}
		endpwent();
		
        exit(EXIT_SUCCESS);
}