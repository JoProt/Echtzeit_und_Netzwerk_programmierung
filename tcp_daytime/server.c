// use POSIX version 2001
#define _POSIX_C_SOURCE 200112L
#define HAVE_SOCK_OPTS

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

// Port chosen to avoid "nonroot" problem in android
#define SRV_PORT    10013

int main(int argc, char *argv[]) {
    // srv address strct
    struct sockaddr_in srvaddr;
    int sockfd, connection;

    // optionen fuer den socket
    int opt = 1;

    
    time_t zeit;

    //socket oeffnen
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    
    memset(&srvaddr, 0, sizeof(srvaddr));

    // server struktur fuellen
    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(SRV_PORT);
    srvaddr.sin_addr.s_addr = INADDR_ANY;


    if (bind(sockfd, (struct sockaddr *) &srvaddr, sizeof(srvaddr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // socket als passiven socket makieren
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    for(;;) {       //while(true)
        
        if((connection = accept(sockfd, (struct sockaddr *) NULL, NULL)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("Client connected\n");

        time(&zeit);

        if (write(connection, ctime(&zeit), 26) != 26) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        printf("lokale systemzeit an client gesendet\n");

        // verbindungsabbau
        if (close(connection) < 0) {
            perror("close");
            exit(EXIT_FAILURE);
        }
        printf("connection closed\n\n");
    }

    return EXIT_SUCCESS; //ueberfluessing, da Endlosschleife und dieser punkt niemals erreich wird
}
