//
// Created by root on 29/11/18.
//

#include "server.h"

namespace pr {

    void handler_stopServer(int nsig) {
        cout << "\t\t\t\t\t\t\t\t*** End Server ***" << endl;
        exit(EXIT_SUCCESS);
    }

    /**
     * Create a new process as server
     * @return
     */
    void startServer() {

        pid_t pid;

        if((pid = fork()) == -1) {
            perror("Fork server error");
            exit(EXIT_FAILURE);
        }

        if(pid == 0) {

            bool keepworking = true;

            cout << "\t\t\t\t\t\t\t\tServer process created" << endl;

            struct sigaction action;
            action.sa_handler = handler_stopServer;
            if(sigaction(SIGALRM, &action , nullptr) == -1) {
                perror("Error sigaction server");
                exit(EXIT_FAILURE);
            }

            alarm(LIVE);

            cout << "\t\t\t\t\t\t\t\tServer process will be alive for at most" << LIVE << " s" << endl;

            pr::ServerSocket serverSocket(PORTSERV);


            while (keepworking) {

                cout << "\t\t\t\t\t\t\t\tServer waiting for connections..." << endl;
                pr::Socket sc = serverSocket.accept_connection();
                cout << "\t\t\t\t\t\t\t\tConnexion from client accepted" << endl;

                int fd = sc.getFD();

                size_t msz = sizeof(int);
                while (true) {
                    int lu;
                    auto nblu = read(fd, &lu, msz);
                    if (nblu == 0) {
                        std::cout << "\t\t\t\t\t\t\t\tServer process end client connexion" << std::endl;
                        break;
                    } else if (nblu < msz) {
                        perror("read");
                        break;
                    }
                    std::cout << "\t\t\t\t\t\t\t\tServer receive =" << lu << std::endl;

                    if (lu == 0) {
                        keepworking = false;
                    }
                    lu++;
                    if (write(fd, &lu, msz) < msz) {
                        perror("write");
                        break;
                    }
                    std::cout << "\t\t\t\t\t\t\t\tServer send =" << lu << std::endl;
                }
                sc.close();
            }
            serverSocket.close();
            cout << "\t\t\t\t\t\t\t\t*** End Server ***" << endl;
            exit(EXIT_SUCCESS);
        }
    }



}
