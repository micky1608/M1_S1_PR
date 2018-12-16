//
// Created by root on 17/10/18.
//


#include <thread>
#include "Queue.h"
#include "Thread.h"
#include "Pool.h"

#define SIZE_POOL 10
#define NB_JOB 10
#define NB_THREAD_IN_POOL 10
// NB_JOB <= SIZE_POOL

namespace micky {

    void test() {

        srand(time(NULL));

//        micky::Queue<int> queue(10);
//
//        queue.change_behaviour(NO_BLOCK);
//
//        std::thread consumer = std::thread(micky::thread_consommateur , &queue);
//        std::thread producer = std::thread(micky::thread_producteur , &queue);
//
//        producer.join();
//        consumer.join();

        Pool pool(SIZE_POOL);
        int *res[NB_JOB];

        for(int i=0 ; i<NB_JOB ; i++) {
                res[i] = new int;
                FirstJob *job = new FirstJob(i+1000,res[i]);
                pool.submit(job);
        }

        pool.start(NB_THREAD_IN_POOL);

        pool.stop();


        for(int i=0 ; i<10 ; i++) delete(res[i]);
    }

}

