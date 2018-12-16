//
// Created by root on 09/12/18.
//

#ifndef TME8_MICKY1608_TCPSERVER_H
#define TME8_MICKY1608_TCPSERVER_H

#include "ServerSocket.h"
#include <thread>
#include <unistd.h>
#include <algorithm>
#include "ConnectionHandler.h"
#include "Job.h"
#include "Pool.h"

#define SIZE_QUEUE_TCP_SERVER 10
#define NB_THREADS_TCP_SERVER 1

namespace pr {

    class TCPServer {

        int pipeFD[2];
        ConnectionHandler *handler;
        Pool pool;
        thread listenThread;

    public:

        TCPServer(ConnectionHandler *handler);

        void startServer(int port);

        void stopServer();

    };

    void listenThreadJob(int port, ConnectionHandler *handler , Pool *pool , int fdRead);

    class TCPJob : public Job {
        ConnectionHandler *handler;
        Socket *socket;

    public:
        TCPJob(ConnectionHandler *handler, Socket *s);
        void run();
    };
}

#endif //TME8_MICKY1608_TCPSERVER_H
