//
// Created by root on 09/12/18.
//

#ifndef TME8_MICKY1608_CRCONNECTIONHANDLER_H
#define TME8_MICKY1608_CRCONNECTIONHANDLER_H

#include "ConnectionHandler.h"
#include "IChatRoom.h"
#include <chrono>
#include <thread>

#define SUBJECT 0
#define NB_PART 1
#define POST_MESS 2
#define QUIT -1

namespace pr {

class CRConnectionHandler : public ConnectionHandler {

    IChatRoom *cr;

    public:

        CRConnectionHandler(IChatRoom *ICR);

        void handleConnection(Socket *s);

        ConnectionHandler* clone() const;

    };
}

#endif //TME8_MICKY1608_CRCONNECTIONHANDLER_H
