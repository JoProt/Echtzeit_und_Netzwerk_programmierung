
#include "daytimeUdp.h"

int main(int argc, char *argv[]) {
    if ((argc < 1) || (argc > 5)) {
        fprintf(stderr, "Aufruf: ./%s [-i IP] [-p PORT]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in srvaddr; 
    int ip;
    int port;
    int socketfd;
    char zeit[DATE_SZ];

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

    memset(&srvaddr, 0, sizeof(srvaddr));

    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(port);
    srvaddr.sin_addr.s_addr = ip;

    if (connect(socketfd, (struct sockaddr *)&srvaddr, sizeof(srvaddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    if (send(socketfd, EXAMPLE, EXAMPLE_SZ, 0) < 0)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }

    if (recv(socketfd, zeit, DATE_SZ, 0) < 0)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    close(socketfd);
    printf("%s", zeit);

    return EXIT_SUCCESS;
}
