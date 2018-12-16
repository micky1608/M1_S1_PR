//
// Created by root on 30/11/18.
//

#include "client.h"

namespace pr {

    void start_client() {

        pr::Socket sock;

        struct in_addr inaddr;
        inaddr.s_addr = inet_addr("127.0.0.1");

        sock.connect_host(inet_ntoa(inaddr), PORTSERV);

        cout << "Client create socket : localhost port " << PORTSERV << endl;

        if (sock.isOpen()) {
            int fd = sock.getFD();

            size_t msz = sizeof(int);
            for (int i = 10; i >= 0; i--) {
                if (write(fd, &i, msz) < msz) {
                    perror("write");
                    break;
                }
                std::cout << "Client send =" << i << std::endl;

                int lu;
                auto nblu = read(fd, &lu, msz);
                if (nblu == 0) {
                    std::cout << "End connexion by server" << std::endl;
                    break;
                } else if (nblu < msz) {
                    perror("read");
                    break;
                }
                std::cout << "Client receive =" << lu << std::endl;
            }

            sock.close();
            cout << "*** End client ***" << endl;
        }

    }
}