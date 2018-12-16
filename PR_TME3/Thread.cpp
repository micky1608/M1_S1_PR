//
// Created by root on 10/10/18.
//

#include "Thread.h"
#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>

namespace micky {

    /**
     * Show its ID, sleep during a random time between 0 and 1000 ms and print an ending message
     * @param id
     */
    void work(int id) {
        std::cout << "Thread " << id << " starting ..." << std::endl;

        srand(time(NULL));
        int time_to_sleep = rand() % 1001;

        std::cout << "Thread " << id << " going to sleep for " << time_to_sleep << " ms ..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(time_to_sleep));

        std::cout << "Thread " << id << " woken up ..." << std::endl;
    }


    /**
     * Create n threads to execute the function "work".
     * Each thread uses the index of the loop (0 -> n-1) as identifier.
     * This function wait for every thread to finish
     * @param n
     */
    void createAndWait(int n) {

        std::vector<std::thread> threads;
        threads.reserve(n);

        for(int i=0 ; i<n ; i++)
            threads.push_back(std::thread(micky::work , i));

        std::for_each(threads.begin() , threads.end() , [] (std::thread& t){t.join();});

        std::cout << "End of all threads !" << std::endl;


    }

}
