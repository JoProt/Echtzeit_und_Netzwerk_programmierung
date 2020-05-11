#include "daytimeUdp.h"

int main(int argc, char *argv[]) {
    struct sockaddr_in srvaddr;
    struct sockaddr_in cliaddr;
    int cliaddr_sz;
    int sockfd;
    int opt = 1;
    time_t zeit;

    char example[EXAMPLE_SZ];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    memset(&srvaddr, 0, sizeof(srvaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(SRV_PORT);
    srvaddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&srvaddr, sizeof(srvaddr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    cliaddr_sz = sizeof(cliaddr);

    //fprintf(stdout, "Daytime-Server aktiv!\nIP:\t%s\nPort:\t%d\n", inet_ntoa(srvaddr.sin_addr), ntohs(srvaddr.sin_port));

    for(;;) {
        if (recvfrom(sockfd, example, EXAMPLE_SZ, 0, (struct sockaddr *)&cliaddr, (socklen_t *)&cliaddr_sz) < 0) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        zeit = time(NULL);

        if (sendto(sockfd, ctime(&zeit), DATE_SZ, 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr)) < 0) {
            perror("sendto");
            exit(EXIT_FAILURE);
        }
    }

    close(sockfd);

    return EXIT_SUCCESS;
}
