#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
   	struct utsname Myutsnamedata;

	if(uname(&Myutsnamedata) == 0){
		printf("Name: %s | Nodename: %s | Release: %s\nVersion: %s | Machine: %s\n", Myutsnamedata.sysname, Myutsnamedata.nodename, Myutsnamedata.release, Myutsnamedata.version, Myutsnamedata.machine);
	}
	else {
		perror("Myutsnamedata failure");
		exit(EXIT_FAILURE);
	}

   	exit(EXIT_SUCCESS);
}
