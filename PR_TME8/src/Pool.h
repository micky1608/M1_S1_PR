//
// Created by root on 18/10/18.
//

#ifndef PR_TME4_POOL_H
#define PR_TME4_POOL_H


#include <thread>
#include <vector>
#include <algorithm>
#include "Queue.h"
#include "Job.h"

namespace pr {

    class Pool {

        Queue<Job> jobs;
        std::vector<std::thread> threads;

    public:

        Pool(size_t size_Queue);

        void start(int NBTHREAD);

        void submit(Job *job);

        void stop();

    };

    void thread_action(Queue<Job> *queue);
}

#endif //PR_TME4_POOL_H
