//
// Created by root on 12/10/18.
//

#ifndef PR_TME3_BANQUE_H
#define PR_TME3_BANQUE_H

#include <vector>
#include "Compte.h"

#define NB_COMPTE_BANQUE 20


namespace micky {

    class Banque {

        unsigned int nb_compte;
        std::vector<micky::Compte> comptes;

    public:

        unsigned int get_nbcompte();

        Banque(int N , int solde);

        bool tranfert(int indDebit , int indCredit , unsigned int montant);

        void createThreadTransfert(int N);

        void display();


    };

    void actionThreadTransfert(Banque *banque);


}


#endif //PR_TME3_BANQUE_H
