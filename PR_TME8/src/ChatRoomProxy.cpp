//
// Created by root on 15/12/18.
//

#include "ChatRoomProxy.h"

namespace pr {

    ChatRoomProxy::ChatRoomProxy() {
        struct in_addr inaddr;
        inaddr.s_addr = inet_addr("127.0.0.1");
        s.connect_host(inet_ntoa(inaddr) , SERVER_PORT_LISTEN);
    }

    ChatRoomProxy::~ChatRoomProxy(){
        s.writeInt(QUIT);
        s.close();
    }


    std::string ChatRoomProxy::getSubject() const {
        string subject;
        s.writeInt(SUBJECT);
        s.readString(subject);
        return subject;
    }

    size_t ChatRoomProxy::nbParticipants() const {
        size_t nb_part;
        s.writeInt(NB_PART);
        s.readInt((int*)&nb_part);
        return nb_part;
    }

    std::vector<ChatMessage> ChatRoomProxy::getHistory() const {
        //TODO
        return {};
    }

    bool ChatRoomProxy::posterMessage(const ChatMessage & msg) {
        chatMessagePB messagePB;
        messagePB.set_author(msg.getAuthor());
        messagePB.set_mes(msg.getMessage());

        s.writeInt(POST_MESS);
        s.writeMessage(messagePB);
        return true;
    }

    bool ChatRoomProxy::joinChatRoom (IChatter * chatter) {
        //TODO
        return true;
    }

    bool ChatRoomProxy::leaveChatRoom (IChatter * chatter) {
        //TODO
        return true;
    }

    void ChatRoomProxy::showHistory() const {
        //TODO
    }
}