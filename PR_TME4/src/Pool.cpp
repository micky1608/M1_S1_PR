//
// Created by root on 18/10/18.
//

#include <algorithm>
#include "Pool.h"

namespace micky {

    Pool::Pool(size_t size_Queue) : jobs(size_Queue) {}

    void Pool::start(int NBTHREAD) {
        for(size_t i=0 ; i<NBTHREAD ; i++)
            threads.emplace_back(std::thread(thread_action , &jobs));
    }

    void Pool::submit(Job *job) {
        jobs.push(job);
    }

    void Pool::stop() {
        jobs.change_behaviour(NO_BLOCK);
        std::for_each(threads.begin() , threads.end() , [] (std::thread& t) {t.join();});

    }

    void thread_action(Queue<Job> *queue) {
        int nb_pop_null=0;

        while(nb_pop_null < 20) {
            Job *job = queue->pop();
            if(job != nullptr)
                job->run();
            else
                nb_pop_null++;
        }
    }


}