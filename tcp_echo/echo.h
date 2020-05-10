// auslagern der includes und konstanten

#define _POSIX_C_SOURCE 200112L
#define HAVE_SOCK_OPTS

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define MAXLEN  2048

#define SRV_PORT    10007
#define SRV_IP      "127.0.0.1"
