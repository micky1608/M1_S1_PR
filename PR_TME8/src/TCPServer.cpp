//
// Created by root on 09/12/18.
//

#include "TCPServer.h"

namespace pr {

    TCPServer::TCPServer(ConnectionHandler *handler) : handler(handler) , pool(SIZE_QUEUE_TCP_SERVER) {
        // create a pipe to handle "stop server"
        if(pipe(pipeFD) == -1) {
            perror("Error creating pipe TCPServer");
            exit(EXIT_FAILURE);
        }

        pool.start(NB_THREADS_TCP_SERVER);
    }

    void listenThreadJob(int port , ConnectionHandler *handler, Pool *pool, int fdRead) {

        ServerSocket serverSocket(port);

        while(true) {

            fd_set fd_wait;
            FD_ZERO(&fd_wait);
            FD_SET(serverSocket.getFD() , &fd_wait);
            FD_SET(fdRead , &fd_wait);

            cout << "\tServer waiting on port " << port << " ..." << endl;

            if(select(max(fdRead , serverSocket.getFD()) + 1 , &fd_wait , nullptr , nullptr , nullptr) == -1) {
                perror("Error select");
                exit(EXIT_FAILURE);
            }

            if(FD_ISSET(fdRead , &fd_wait)) break;

            Socket workingSocket = serverSocket.accept_connection();
            auto tcpJob = new TCPJob(handler->clone() , &workingSocket);
            pool->submit(tcpJob);
        }

        serverSocket.close();
        pool->stop();
    }


    void TCPServer::startServer(int port) {
        listenThread = thread(listenThreadJob , port , this->handler , &pool , pipeFD[0]);
    }

    void TCPServer::stopServer() {
        char buf = '0';
        if(write(pipeFD[1] , &buf , 1) != 1) {
            perror("Error write stopServer");
            exit(EXIT_FAILURE);
        }
        listenThread.join();
    }

    TCPJob::TCPJob(ConnectionHandler *handler, Socket *s) : handler(handler) , socket(s) {}

    void TCPJob::run() {
        handler->handleConnection(socket);
        delete handler;
        socket->close();
    }

}