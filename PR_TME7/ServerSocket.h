#ifndef SRC_SERVERSOCKET_H_
#define SRC_SERVERSOCKET_H_

#include "Socket.h"


namespace pr {

class ServerSocket {
	int socketfd;

public :

	int getFD() { return socketfd;}
	bool isOpen() const {return socketfd != -1;}

	// Demarre l'ecoute sur le port donne
	ServerSocket(int port) {

		struct sockaddr_in sin;

		socketfd = socket(AF_INET , SOCK_STREAM , 0);
		if(socketfd == -1) {
			perror("Error socket creation server");
			exit(EXIT_FAILURE);
		}

		sin.sin_family = AF_INET;
		sin.sin_port = htons((u_short)port);
		sin.sin_addr.s_addr = htonl(INADDR_ANY);

		if(bind(socketfd , (struct sockaddr *)&sin , sizeof(sin)) != 0) {
			perror("Error bind");
			exit(EXIT_FAILURE);
		}

		cout << "\t\t\t\t\t\t\t\tServer created socket on : " << &sin;

		if(listen(socketfd , 10) == -1) {
			perror("Error listen");
			exit(EXIT_FAILURE);
		}

	}


	Socket accept_connection() {
		struct sockaddr_in exp;
		socklen_t len_exp = sizeof(exp);

		struct sockaddr_in workingSocketAddr;
		socklen_t len_workingSocket = sizeof(workingSocketAddr);

		int workingSocket_fd = accept(socketfd , (struct sockaddr*) &exp , &len_exp);

		cout << "\t\t\t\t\t\t\t\tServer connexion accepted from : " << &exp;

		if(workingSocket_fd < 0) {
			perror("Error accept");
			exit(EXIT_FAILURE);
		}

		Socket workingSocket = Socket(workingSocket_fd);

		return workingSocket;
	}

	void close() {
		cout << "\t\t\t\t\t\t\t\tServer socket close" << endl;
		::close(socketfd);
	}
};

} // ns pr
#endif /* SRC_SERVERSOCKET_H_ */
