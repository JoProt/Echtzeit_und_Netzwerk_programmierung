
#include "echo.h"    //eigener header -> ausgelagert

int main(int argc, char *argv[]) {
    // check arguments
    if ((argc < 1) || (argc > 5)) {
        fprintf(stderr, "Aufruf: ./%s [-i IP] [-p PORT]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in srvaddr;
    int sockfd;                 


    // input und output 
    char in[MAXLEN];
    char out[MAXLEN];
    int opt;
    const char *optstring;

    
    int ip, port;
    ip = inet_addr(SRV_IP);
    port = SRV_PORT;

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

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&srvaddr, 0, sizeof(srvaddr));
    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(port);
    srvaddr.sin_addr.s_addr = ip;
    if (connect(sockfd, (struct sockaddr *) &srvaddr, sizeof(srvaddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    while (fgets(in, MAXLEN, stdin) != 0) {
        if (write(sockfd, in, MAXLEN) != sizeof(in)) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        if (read(sockfd, out, MAXLEN) < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        fputs(out, stdout);
    }

    return EXIT_SUCCESS;
}
