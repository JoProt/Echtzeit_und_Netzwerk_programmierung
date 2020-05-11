#include "daytimeUdp.h"

int main(int argc, char *argv[]) {
    if ((argc < 1) || (argc > 5))
    {
        fprintf(stderr, "Aufruf: ./%s [-i IP] [-p PORT]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in srvaddr; 

    int IP;
    int PORT;
    int sockfd;
    char zeit[DATE_SZ];

    IP = inet_addr(SRV_IP);
    PORT = SRV_PORT;

    int opt;
    const char *optstring;
    optstring = ":i:p:";
    while ((opt = getopt(argc, argv, optstring)) != -1) {
        switch (opt) {
            case 'i':
                IP = inet_addr(optarg);
                break;
            case 'p':
                PORT = atoi(optarg);
                break;
        }
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&srvaddr, 0, sizeof(srvaddr));

    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(PORT);
    srvaddr.sin_addr.s_addr = IP;
    int srvaddr_sz;
    srvaddr_sz = sizeof(srvaddr);

    if (sendto(sockfd, EXAMPLE, EXAMPLE_SZ, 0, (struct sockaddr *)&srvaddr, sizeof(srvaddr)) < 0) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }

    if (recvfrom(sockfd, zeit, DATE_SZ, 0, (struct sockaddr *)&srvaddr, (socklen_t *)&srvaddr_sz) < 0) {
        perror("recvfrom");
        exit(EXIT_FAILURE);
    }

    close(sockfd);

    printf("%s", zeit);

    return EXIT_SUCCESS;
}
