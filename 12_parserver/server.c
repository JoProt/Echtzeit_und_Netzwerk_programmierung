#include "echo.h"

void child_handler(int signo); 

int main(int argc, char *argv[]) {
    struct sockaddr_in srvaddr;
    int socket_fd;
    int connfd;
    int opt = 1;
    char string[MAXLEN];
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    //SO_REUSEADDR:  erneutes verwenden der lokalen adresse
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("!!- Fehler beim Setzen des Sockets");
        exit(EXIT_FAILURE);
    }

    memset(&srvaddr, 0, sizeof(srvaddr));

    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(SRV_PORT);
    srvaddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(socket_fd, (struct sockaddr *) &srvaddr, sizeof(srvaddr)) < 0) {
        perror("!!- Fehler beim binden");
        exit(EXIT_FAILURE);
    }
	
    if (listen(socket_fd, 5) < 0) {
        perror("!!- Fehler beim horchen");
        exit(EXIT_FAILURE);
    }


    for(;;) {   //while(true)
	//signal(SIGCHLD, child_handler);
    signal(SIGCHLD, SIG_IGN);   // System V
        if((connfd = accept(socket_fd, (struct sockaddr *) NULL, NULL)) < 0) {
             perror("Client Disconnect");
            exit(EXIT_FAILURE);
        }
        printf("Client Connectn\n");

        pid_t childpid = fork();
        if ( childpid < 0 ) {
           return(EXIT_FAILURE);
        }
        if ( childpid == 0 ) {
            //im kind
            while (read(connfd, string, MAXLEN) != 0) {
                if (write(connfd, string, MAXLEN) != sizeof(string)) {
                    perror("write");
                    exit(EXIT_FAILURE);
                }
            }
            exit(0);
        } else {
            //TODO: im vater verbindung schliessen!!
            if (close(connfd) < 0) {
                perror("!!- Fehler beim schließen");
                exit(EXIT_FAILURE);
            }
        }
    }

    return EXIT_SUCCESS;
}

void child_handler(int signo){
    wait(NULL);
    return;
}

