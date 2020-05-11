// use POSIX version 2001
#define _POSIX_C_SOURCE 200112L
#define HAVE_SOCK_OPTS

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#ifndef SRV_PORT
#define SRV_PORT 13
#endif

#ifndef SRV_IP
#define SRV_IP "127.0.0.1"
#endif

#define DATE_SZ 26

#define EXAMPLE "exampleString"
#define EXAMPLE_SZ sizeof(EXAMPLE)
