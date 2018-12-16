#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <netdb.h>
#include "server.h"
#include "client.h"

using namespace std;
using namespace pr;


int main() {

    struct sockaddr_in sin_lip6;
    string ip("132.227.104.6");

    sin_lip6.sin_family = AF_INET;
    sin_lip6.sin_addr.s_addr = inet_addr(ip.c_str());

    cout << &sin_lip6;



    /* ************************************************************************************ */

    pr::startServer();

    // sleep for the server init
    sleep(1);

    pr::start_client();









    return 0;
}