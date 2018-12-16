//
// Created by root on 15/12/18.
//

#include "ChatRoomServer.h"
#include "CRConnectionHandler.h"

namespace pr {

    ChatRoomServer::ChatRoomServer(IChatRoom *ICR , int port) : cr(ICR) {
        handler = new CRConnectionHandler(cr);
        tcpServer = new TCPServer(handler);
        tcpServer->startServer(port);
    }


    ChatRoomServer::~ChatRoomServer() {
        delete handler;
        delete tcpServer;
    }

    void ChatRoomServer::stopCRServer() {
        tcpServer->stopServer();
    }

}