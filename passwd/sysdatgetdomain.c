#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   	char ergebnis[1024];
	size_t len = sizeof(ergebnis);
	//gleich wie bei gethostname
	if(getdomainname(ergebnis, len) == 0){
		printf("Domainname: %s\n", ergebnis);
	} else {
		perror("getdomainname()");
	    exit(EXIT_FAILURE);
	}
   	exit(EXIT_SUCCESS);
}
