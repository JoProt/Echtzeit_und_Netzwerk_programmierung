#include "echo.h"

int main(int argc, char *argv[]) {
    
    struct sockaddr_in serveradresse;
    int socketfd;
    int connection;
    int opt = 1;
    char string[MAXLEN];

    socketfd = socket(AF_INET, SOCK_STREAM, 0);


    if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    
    memset(&serveradresse, 0, sizeof(serveradresse));
   
    serveradresse.sin_family = AF_INET;
    serveradresse.sin_port = htons(SRV_PORT);
    serveradresse.sin_addr.s_addr = INADDR_ANY;

    if (bind(socketfd, (struct serveradresse*) &serveradresse, sizeof(serveradresse)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    //passiv markieren
    if (listen(socketfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    for(;;) { // while(true)
       
        if((connection = accept(socketfd, (struct sockaddr *) NULL, NULL)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        //lesen des client inputs und zurueck senden ->  echo 
        while (read(connection, string, MAXLEN) != 0) {
            
            if (write(connection, string, MAXLEN) != sizeof(string)) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        // socket freigeben! wichtig!
        if (close(connection) < 0) {
            perror("close");
            exit(EXIT_FAILURE);
        }
    }
    return EXIT_SUCCESS;
}
