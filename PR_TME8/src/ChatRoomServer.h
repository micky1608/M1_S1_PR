//
// Created by root on 15/12/18.
//

#ifndef TME8_MICKY1608_CHATROOMSERVER_H
#define TME8_MICKY1608_CHATROOMSERVER_H

#include "TCPServer.h"
#include "IChatRoom.h"

namespace pr {

    class ChatRoomServer {

        IChatRoom *cr;
        TCPServer *tcpServer;
        ConnectionHandler *handler;

    public:

        ChatRoomServer(IChatRoom *ICR , int port);

        ~ChatRoomServer();

        void stopCRServer();

    };
}



#endif //TME8_MICKY1608_CHATROOMSERVER_H
