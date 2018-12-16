//
// Created by root on 29/11/18.
//

#ifndef PR_TME7_SERVER_H
#define PR_TME7_SERVER_H


#include <unistd.h>
#include <signal.h>
#include "ServerSocket.h"

#define PORTSERV 1664
#define LIVE 45

namespace pr {

    void startServer();

    void handler_stopServer(int nsig);

}

#endif //PR_TME7_SERVER_H
