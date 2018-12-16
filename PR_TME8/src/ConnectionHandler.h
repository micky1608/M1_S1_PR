//
// Created by root on 09/12/18.
//

#ifndef TME8_MICKY1608_CONNECTIONHANDLER_H
#define TME8_MICKY1608_CONNECTIONHANDLER_H

#include "Socket.h"

namespace pr {

    class ConnectionHandler {

    public:

        virtual void handleConnection(Socket *s) = 0;

        virtual ConnectionHandler* clone() const = 0;

        virtual ~ConnectionHandler() = default;

    };
}




#endif //TME8_MICKY1608_CONNECTIONHANDLER_H
