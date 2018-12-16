//
// Created by root on 15/12/18.
//

#ifndef TME8_MICKY1608_CHATROOMPROXY_H
#define TME8_MICKY1608_CHATROOMPROXY_H

#include "IChatRoom.h"
#include "Socket.h"
#include "ServerSocket.h"
#include "CRConnectionHandler.h"

#include "chat.pb.h"

namespace pr {

    class ChatRoomProxy : public IChatRoom {

        mutable Socket s;

    public:

        ChatRoomProxy();
        ~ChatRoomProxy();

        std::string getSubject() const;
        size_t nbParticipants() const;

        std::vector<ChatMessage> getHistory() const ;
        bool posterMessage(const ChatMessage & msg);
        bool joinChatRoom (IChatter * chatter);
        bool leaveChatRoom (IChatter * chatter);
        void showHistory() const;
    };

}



#endif //TME8_MICKY1608_CHATROOMPROXY_H
