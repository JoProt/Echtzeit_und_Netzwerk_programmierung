#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   	char ergebnis[1024];
	// len = leange von ergebnis-array
	size_t len = sizeof(ergebnis);
	//gethostname liefert hostname
	if(gethostname(ergebnis, len) == 0){
		printf("Hostname: %s\n", ergebnis);
	} else {
		perror("gethostname()");
	    exit(EXIT_FAILURE);
	}
   	exit(EXIT_SUCCESS);
}
