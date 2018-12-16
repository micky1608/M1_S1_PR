#include "TextChatRoom.h"
#include "ChatRoomServer.h"
#include "MTChatRoom.h"
#include "ServerSocket.h"
#include <iostream>
#include <unistd.h>

using namespace pr;
using namespace std;

int main() {
	TextChatRoom textChatRoom("PR");
	MTChatRoom MTtextChatRoom(&textChatRoom);

	TextChatter adminChatter("Admin CR");
	MTtextChatRoom.joinChatRoom(&adminChatter);
	MTtextChatRoom.posterMessage({"Admin CR" , "Début CR"});

	ChatRoomServer chatRoomServer(&MTtextChatRoom , SERVER_PORT_LISTEN);

	cout << "Start Server ... Write something to stop !" << endl;

	string s ;
    cin >> s ;

    cout << "*** End Server ***" << endl;

	chatRoomServer.stopCRServer();

	cout << "Chat Room history : " << endl;
	MTtextChatRoom.showHistory();

}


//int main() {
//
//	pr::TextChatRoom tcr ("C++");
//	pr::MTChatRoom mcr (&tcr);
//	pr::TextChatter schat("Echo Server");
//	mcr.posterMessage({"serveur","début session"});
//	tcr.joinChatRoom(&schat);
//	{
//		pr::ChatRoomServer server(&mcr,1664);
//
//		// attend entree sur la console
//		std::string s ;
//		std::cin >> s ;
//
//		std::cout << "Début fin du serveur." << std::endl ;
//
//		// on quit = dtor du serveur
//	}
//	tcr.posterMessage({"serveur","fin session"});
//	std::cout << "Ok fin du serveur." << std::endl;
//	tcr.leaveChatRoom(&schat);
//
//	return 0;
//}


//#include <iostream>
//#include <signal.h>
//#include "CRConnectionHandler.h"
//#include "TCPServer.h"
//
//#define TIME_SERVER_TO_LIVE 60
//
//using namespace pr;
//using namespace std;
//
//void killServerTimer(TCPServer * tcpServer , unsigned int nbSec) {
//    cout << "Start timer for " << nbSec << "s" << endl;
//     this_thread::sleep_for(chrono::seconds(nbSec));
//     cout << "***Timeout***" << endl;
//     tcpServer->stopServer();
//}
//
//void launchServer(TCPServer *tcpServer) {
//    tcpServer->startServer(SERVER_PORT_LISTEN);
//}
//
///* ************************************************************************************************************* */
//
//int main() {
//
//	std::cout << "Server" << std::endl;
//
//    CRConnectionHandler connectionHandler;
//
//    TCPServer tcpServer(&connectionHandler);
//
//    thread launchServerThread(launchServer , &tcpServer);
//
//    thread stopServerThread(killServerTimer , &tcpServer , TIME_SERVER_TO_LIVE);
//
//    stopServerThread.join();
//    launchServerThread.join();
//}
