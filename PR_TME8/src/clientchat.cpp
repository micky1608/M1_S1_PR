//#include "ChatRoomProxy.h"
//#include <iostream>
//#include <unistd.h>
//#include <string>
//
//
//int main() {
//  struct in_addr inaddr;
//  inaddr.s_addr = inet_addr("127.0.0.1");
//	pr::ChatRoomProxy cr(inet_ntoa(inaddr), 1664);

//	std::cout << "Sujet =" << cr.getSubject();
//	std::cout << "NbParticipants =" << cr.nbParticipants() << std::endl;
//	std::cout << "History =" ;
//	for (auto & h : cr.getHistory()) {
//		std::cout << h.getAuthor() << "> " << h.getMessage() << std::endl;
//	}
//
//	return 0;
//}
//

#include <iostream>
#include <thread>
#include "Socket.h"
#include "ServerSocket.h"
#include "ChatRoomProxy.h"

using namespace pr;

int main() {

    ChatRoomProxy CRProxy;

    string subject = CRProxy.getSubject();
    size_t nb_part = CRProxy.nbParticipants();

    cout << "Subject : " << subject << endl;
    cout << "Nb participants : " << nb_part << endl;

    CRProxy.posterMessage({"Proxy user" , "Message from proxy user"});

    cout << "Message posted on proxy" << endl;

    cout << "End client" << endl;

}