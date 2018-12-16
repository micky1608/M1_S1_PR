#ifndef SRC_SOCKET_H_
#define SRC_SOCKET_H_

#include <netinet/ip.h>
#include <string>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstring>
#include <unistd.h>

using namespace std;

namespace pr {

class Socket {
	int fd;

public :

	Socket();
	Socket(int fd);

	bool isOpen() const;
	int getFD();

	void connect_host(const std::string &host, int port);

	void connect_host(in_addr ipv4, int port);

	void close();

};

std::ostream & operator<< (std::ostream & os, struct sockaddr_in * addr);

}

#endif /* SRC_SOCKET_H_ */
