//
// Created by root on 19/10/18.
//

#ifndef PR_TME4_BARRIER_H
#define PR_TME4_BARRIER_H

#include <mutex>
#include <condition_variable>

namespace micky {

    class Barrier {

        mutable std::mutex mutex;
        std::condition_variable cond;
        int nb_jobs_done;
        int nb_total_jobs;

    public:

        Barrier(int N);

        void done();

        void waitFor();


    };

}




#endif //PR_TME4_BARRIER_H
