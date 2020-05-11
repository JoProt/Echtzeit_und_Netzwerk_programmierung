
#include "daytimeUdp.h"

int main(int argc, char *argv[]) {
   
    if ((argc < 1) || (argc > 5)) {
        fprintf(stderr, "Aufruf: ./%s [-i IP] [-p PORT]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in cliaddr; 
    struct sockaddr_in srvaddr; 
    int ip;
    int port;
    int socketfd;
    char srvtime[DATE_SZ];
    ip = inet_addr(SRV_IP);
    port = SRV_PORT;

    int opt;
    const char *optstring;
    optstring = ":i:p:";
    while ((opt = getopt(argc, argv, optstring)) != -1) {
        switch (opt) {
            case 'i':
                ip = inet_addr(optarg);
                break;
            case 'p':
                port = atoi(optarg);
                break;
        }
    }

    if ((socketfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&cliaddr, 0, sizeof(cliaddr));
    memset(&srvaddr, 0, sizeof(srvaddr));

    cliaddr.sin_family = AF_INET;
    cliaddr.sin_port = 0;
    cliaddr.sin_addr.s_addr = INADDR_ANY;

    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(port);
    srvaddr.sin_addr.s_addr = ip;
    int srvaddr_sz;
    srvaddr_sz = sizeof(srvaddr);

    if (bind(socketfd, (struct sockaddr *)&cliaddr, sizeof(cliaddr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (sendto(socketfd, EXAMPLE, EXAMPLE_SZ, 0, (struct sockaddr *)&srvaddr, sizeof(srvaddr)) < 0) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }

    if (recvfrom(socketfd, srvtime, DATE_SZ, 0, (struct sockaddr *)&srvaddr, (socklen_t *)&srvaddr_sz) < 0) {
        perror("recvfrom");
        exit(EXIT_FAILURE);
    }

    close(socketfd);
    printf("%s", srvtime);

    return EXIT_SUCCESS;
}
