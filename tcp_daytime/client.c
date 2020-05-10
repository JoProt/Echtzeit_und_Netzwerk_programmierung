// parameters:
// IP       - optional; Flag '-i'; IP-Adresse des TCP-Daytime-Servers
// Port     - optional; Flag '-p'; Port des Zielsystems

// use POSIX version 2001
#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define BUFLEN  1024    // maximum response size

int main(int argc, char *argv[]) {
    // check arguments
    if ((argc < 1) || (argc > 5)) {
        fprintf(stderr, "Aufruf: ./%s [-i IP] [-p PORT]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // IP & PORT for srv
    int ipadresse;
    int port;


    struct sockaddr_in srvaddr;
    int socketfd;                 
    char cBuffer[BUFLEN+1];     
    char* pc;                   


    // setze ip und port
    ipadresse = inet_addr("127.0.0.1");
    port = 10013;

    // map arguments
    int opt;
    const char *optstring;
    optstring = ":i:p:";
    while ((opt = getopt(argc, argv, optstring)) != -1) {
        switch (opt) {
            case 'i':
                ipadresse = inet_addr(optarg);
                break;
            case 'p':
                port = atoi(optarg);
                break;
        }
    }

    // socket oeffnen
    socketfd = socket(AF_INET, SOCK_STREAM, 0);

   
    memset(&srvaddr, 0, sizeof(srvaddr));

    // server konfig
    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(port);
    srvaddr.sin_addr.s_addr = ipadresse;

    if (connect(socketfd, (struct sockaddr *)&srvaddr, sizeof(srvaddr)) < 0) {
        perror("connect, checken ob server laeuft!");
        exit(EXIT_FAILURE);
    }

    // zeiger pc auf cBuffer setzten
    pc = cBuffer;

    // hlesen des buffers bis read = 0
    int buff;
    while ( buff = read(socketfd, pc, BUFLEN - ( pc - cBuffer))) {
        pc += buff;
    }

    // close the FileDescriptor to avoid errors
    close(socketfd);
    *pc = '\0'; //\0 terminierung

    // ausgabe der zeit aus cBuffer
    printf("%s", cBuffer);

    return EXIT_SUCCESS;
}
