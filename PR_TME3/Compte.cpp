//
// Created by root on 10/10/18.
//

#include "Compte.h"
#define JACKPOT 10000
#define LOSEPOT 1000

namespace micky {

    Compte::Compte(int s) : solde(s) {}

    void Compte::crediter(int montant) {
        std::lock_guard<std::recursive_mutex> lock(mutex);
        solde+= montant;
    }

    Compte::Compte(const micky::Compte &c) {
        std::lock_guard<std::recursive_mutex> lock(c.mutex);
        solde = c.solde;
    }

    int Compte::getSolde() const {
        std::lock_guard<std::recursive_mutex> lock(mutex);
        return solde;
    }

    bool Compte::debiter(int montant) {
        std::lock_guard<std::recursive_mutex> lock(mutex);
        if(montant <= solde) {
            solde -= montant;
            return true;
        }
        return false;
    }

    void jackpot(Compte *c) {
        int money = JACKPOT;
        while (money > 0) {
            c->crediter(1);
            money--;
        }
    }

    void losePot(Compte *c) {
        int money = LOSEPOT;
        while(money > 0) {
            c->debiter(10);
            money -= 10;
        }
    }


    void Compte::lock() const {mutex.lock();}

    void Compte::unlock() const {mutex.unlock();}





}
