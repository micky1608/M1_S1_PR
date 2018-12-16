//
// Created by root on 09/12/18.
//

#include "CRConnectionHandler.h"

namespace pr {

    CRConnectionHandler::CRConnectionHandler(IChatRoom *ICR) : cr(ICR) {}

    ConnectionHandler* CRConnectionHandler::clone() const {
        return new CRConnectionHandler(cr);
    }

    void CRConnectionHandler::handleConnection(Socket *s) {
        cout << "\t\t\t\tHandling connexion ..." << endl;
        while(true) {
            int code;
            s->readInt(&code);
            switch (code) {

                case SUBJECT : {
                    string subject = cr->getSubject();
                    s->writeString(subject);
                    break;
                }

                case NB_PART : {
                    size_t nb_participant = cr->nbParticipants();
                    s->writeInt((int)nb_participant);
                    break;
                }

                case POST_MESS : {
                    chatMessagePB messagePB;
                    s->readMessage(&messagePB);
                    ChatMessage message(messagePB.author() , messagePB.mes());
                    cr->posterMessage({messagePB.author() , messagePB.mes()});
                    break;
                }

                case QUIT : {
                    cout << "\t\t\t\tQuit connection" << endl;
                    s->close();
                    return;
                }

                // unknown : do nothing
                default: break;
            }
        }
    }


}
