//
// Created by root on 17/10/18.
//

#include <thread>
#include "Thread.h"

#define N 10

namespace micky {

    /**
     * Thread to perform N push of random int between 0 and 10000
     * @param q
     */
    void thread_producteur(micky::Queue<int> *q) {

        for(int i=0 ; i<2*N ; i++) {
            int *random = new int;
            *random = rand() % 10001;
            std::cout << "Going to write " << *random <<  std::endl;
            q->push(random);
        }

    }

    /**
     * Thread to perform N reading
     * @param q
     */
    void thread_consommateur(micky::Queue<int> *q) {

        for(int i=0 ; i<N ; i++) {
            int *val = q->pop();
            if(val != nullptr)
                std::cout << "Read " << *val << std::endl;
            else
                std::cout << "Read nullptr" << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

    }


}
