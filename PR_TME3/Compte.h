//
// Created by root on 10/10/18.
//

#ifndef PR_TME3_COMPTE_H
#define PR_TME3_COMPTE_H

#include <atomic>
#include <mutex>

namespace micky {

    class Compte {

        int solde;

        mutable std::recursive_mutex mutex;

    public:

        Compte(int s);

        Compte(const Compte& c);

        void crediter(int montant);

        bool debiter(int montant);

        int getSolde() const;

        void lock() const;

        void unlock() const;

    };

    void jackpot(Compte *c);

    void losePot(Compte *c);
}

#endif //PR_TME3_COMPTE_H
