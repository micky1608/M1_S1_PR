#include <iostream>
#include <thread>
#include <vector>
#include "Thread.h"
#include "Compte.h"
#include "Banque.h"
#include <algorithm>

#define NB_THREAD 10
#define SOLDEINITIAL 1000

int main() {

    micky::createAndWait(3);

    micky::Compte compte(0);

    std::cout << "\n\n*******************************************************\n" << std::endl;

    std::cout << "Solde before jackpot : " << compte.getSolde() << std::endl;

    micky::jackpot(&compte);

    std::cout << "Solde after jackpot : " << compte.getSolde() << std::endl;



    std::vector<std::thread> threads;

    for(int i=0 ; i<NB_THREAD ; i++)
        threads.push_back(std::thread(micky::jackpot , &compte));

    std::for_each(threads.begin() , threads.end() , [](std::thread& t) {t.join();});

    std::cout << "Solde after jackpot multi-threads : " << compte.getSolde() << std::endl;


    std::cout << "\n\n*******************************************************\n" << std::endl;

    micky::losePot(&compte);

    std::cout << "Solde after losePot : " << compte.getSolde() << std::endl;

    std::vector<std::thread> threads2;

    for(int i=0 ; i< NB_THREAD ; i++)
        threads2.push_back(std::thread(micky::losePot , &compte));

    std::for_each(threads2.begin() , threads2.end() , [](std::thread& t) {t.join();});

    std::cout << "Solde after losePot multi-thread : " << compte.getSolde() << std::endl;

    std::cout << "\n\n*******************************************************\n" << std::endl;

    micky::Banque bank(5 , SOLDEINITIAL);

    std::cout << "\n\t***** Bank initial state *****\n" << std::endl;
    bank.display();

    bank.tranfert(0,1,500);
    std::cout << "\n\t***** Bank after first transfert *****\n" << std::endl;
    bank.display();


    bank.createThreadTransfert(10);
    std::cout << "\n\t***** Bank after multi_thread transfert *****\n" << std::endl;
    bank.display();


    return 0;
}