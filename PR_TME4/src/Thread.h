//
// Created by root on 17/10/18.
//

#ifndef PR_TME4_THREAD_H
#define PR_TME4_THREAD_H

#include "Queue.h"

namespace micky {

    void thread_producteur(micky::Queue<int> *q);

    void thread_consommateur(micky::Queue<int> *q);
}

#endif //PR_TME4_THREAD_H
