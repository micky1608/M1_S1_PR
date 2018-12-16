//
// Created by root on 12/10/18.
//

#include <thread>
#include <algorithm>
#include <iostream>
#include "Banque.h"

namespace micky {

    Banque::Banque(int N, int solde) {
        nb_compte = N;
        for(int i=0 ; i<nb_compte ; i++)
            comptes.push_back(micky::Compte(solde));
    }

    unsigned int Banque::get_nbcompte() { return nb_compte;}

    /**
     * Perform a transaction between two accounts in the bank
     * @param indDebit index of the account debited
     * @param indCredit index of the account credited
     * @param montant value of the transaction
     * @return
     */
    bool Banque::tranfert(int indDebit, int indCredit, unsigned int montant) {
        if(indDebit < 0 || indDebit >= nb_compte || indCredit < 0 || indCredit >= nb_compte) {
            std::cerr << "Transfert failed : invalid index" << std::endl;
            return false;
        }

        comptes[std::min(indDebit,indCredit)].lock();
        comptes[std::max(indDebit,indCredit)].lock();

        if(comptes[indDebit].debiter(montant)) {
            comptes[indCredit].crediter(montant);

            comptes[indDebit].unlock();
            comptes[indCredit].unlock();

            return true;
        }

        comptes[indDebit].unlock();
        comptes[indCredit].unlock();
        return false;
    }


    /**
     * Create N threads to execute the function "actionThreadTransfert"
     * @param N
     */
    void Banque::createThreadTransfert(int N) {

        std::cout << "\n\nCreation of " << N << " threads executing 1000 transactions ... Please wait until they finish" << std::endl;
        std::vector<std::thread> threads;
        threads.reserve(N);

        for(int i=0 ; i<N ; i++)
            threads.push_back(std::thread(actionThreadTransfert , this));

        std::for_each(threads.begin() , threads.end() , [](std::thread& t){ t.join();});
    }


    /**
     * Display the amount of money on each account and the total
     */
    void Banque::display() {
        int sum = 0;
        for(int i=0 ; i<nb_compte ; i++) {
            std::cout << "Compte " << i+1 << " : " << comptes[i].getSolde() << " € " << std::endl;
            sum += comptes[i].getSolde();
        }

        std::cout << "Total : " << sum << " € " << std::endl;
    }


    /**
     * A thread executing this function will perform 1000 random transactions in the bank.
     * It sleeps a random times (between 0 and 20 ms) after each transaction
     * @param banque
     */
    void actionThreadTransfert(Banque *banque) {
        srand(time(NULL));
        int nb_compte = banque->get_nbcompte();

        for(int k=0 ; k<1000 ; k++) {
            int indDebit = rand() % nb_compte;
            int indCredit;
            do {
                indCredit = rand() % nb_compte;
            } while(indDebit == indCredit);

            int montant = rand() % 101;

            banque->tranfert(indDebit,indCredit,montant);

            int time_to_sleep = rand() % 21;
            std::this_thread::sleep_for(std::chrono::milliseconds(time_to_sleep));
        }
    }
}
