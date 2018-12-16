//
// Created by root on 29/11/18.
//

#include "Socket.h"

namespace pr {


    Socket::Socket():fd(-1){}

    Socket::Socket(int fd):fd(fd){}

    bool Socket::isOpen() const {return fd != -1;}
    int Socket::getFD() { return fd ;}

    /**
     * @param host : string representing an ipv4 address
     * @param port
     */
    void Socket::connect_host(const std::string &host, int port) {
        if(fd == -1) {
            fd = socket(AF_INET , SOCK_STREAM , 0);
            if(fd == -1) {
                perror("Error socket creation");
                exit(EXIT_FAILURE);
            }
        }

        struct sockaddr_in dest;
        dest.sin_family = AF_INET;
        dest.sin_port = htons((u_short)port);
        dest.sin_addr.s_addr = inet_addr(host.c_str());

        if(connect(fd, (struct sockaddr *) &dest, sizeof(dest)) != 0) {
            perror("Error connect_host");
            exit(EXIT_FAILURE);
        }

    }

    void Socket::connect_host(in_addr ipv4, int port) {
        string ipv4_str(inet_ntoa(ipv4));
        connect_host(ipv4_str, port);
    }


    void Socket::close() {
        shutdown(fd , 0);
        ::close(fd);
    }



    std::ostream & operator<< (std::ostream & os, struct sockaddr_in * addr) {

        if(addr->sin_family != AF_INET) {
            perror("Family must be AF_INET in operator<<");
            exit(EXIT_FAILURE);
        }
        char host[64];

        if(int ret = getnameinfo((struct sockaddr*) addr , sizeof(*addr) , host , sizeof(host) , nullptr , 0, 0) != 0) {
            fprintf(stderr,"Error getnameinfo in operator<< -> error code = %d\n", ret);
            exit(EXIT_FAILURE);
        }

        os << "Host name : " << host << "\t\t";
        os << "IP address : " << inet_ntoa(addr->sin_addr) << "\t\t";
        os << "Port : " << ntohs(addr->sin_port) << "\n";

        return os;
    }

}

