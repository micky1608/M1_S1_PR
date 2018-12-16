//
// Created by root on 19/10/18.
//

#include "Barrier.h"

namespace micky {

    Barrier::Barrier(int N) : nb_total_jobs(N) , nb_jobs_done(0) {}

    void Barrier::done() {
        std::unique_lock<std::mutex> lk(mutex);
        nb_jobs_done++;

        if(nb_jobs_done == nb_total_jobs) cond.notify_all();

        lk.unlock();
    }

    void Barrier::waitFor() {
        std::unique_lock<std::mutex> lk(mutex);
        while(nb_jobs_done < nb_total_jobs)
            cond.wait(lk);

    }



}