//
// Created by root on 17/10/18.
//

#ifndef PR_TME4_QUEUE_H
#define PR_TME4_QUEUE_H


#include <cstddef>
#include <cstring>
#include <mutex>
#include <condition_variable>
#include <iostream>



namespace micky {

enum Behaviour { BLOCK , NO_BLOCK};


    template<typename T>
    class Queue {

        T **tab;
        const size_t alloc_size;
        size_t begin, size;


        mutable std::mutex mutex;
        std::condition_variable cond;

        Behaviour behaviour;

        bool empty() { return (size == 0); }

        bool full() { return (size == alloc_size); }

    public:

        Queue(size_t maxsize) : alloc_size(maxsize), begin(0), size(0), behaviour(BLOCK) {
            tab = new T *[alloc_size];
            memset(tab, 0, sizeof(T *) * alloc_size);
        }

        size_t getSize() const {
            std::lock_guard<std::mutex> lk(mutex);
            return size;
        }

        void change_behaviour(Behaviour new_behaviour) {
            std::unique_lock<std::mutex> lk(mutex);
            if(behaviour == BLOCK && new_behaviour == NO_BLOCK)
                cond.notify_all();

            behaviour = new_behaviour;
            lk.unlock();
        }


        T *pop() {

            std::unique_lock<std::mutex> lk(mutex);

            while(empty() && behaviour == BLOCK) {
                std::cout << "Waiting for pop ..." << std::endl;
                cond.wait(lk);
            }

            if(empty() && behaviour == NO_BLOCK) {
                std::cout << "Pop not possible !!!!!!" << std::endl;
                lk.unlock();
                return nullptr;
            }

            std::cout << "Pop possible" << std::endl;

            auto element = tab[begin];
            tab[begin] = nullptr;
            begin = (begin + 1) % alloc_size;
            size--;

            if (size == alloc_size - 1) cond.notify_all();

            lk.unlock();
            return element;
        }

        bool push(T *element) {

            std::unique_lock<std::mutex> lk(mutex);

            while(full() && behaviour == BLOCK) {
                std::cout << "Waiting for push ..." << std::endl;
                cond.wait(lk);
            }

            if(full() && behaviour == NO_BLOCK) {
                std::cout << "Push not possible !!!!!!" << std::endl;
                lk.unlock();
                return false;
            }

            std::cout << "Push possible" << std::endl;

            tab[(begin + size) % alloc_size] = element;
            size++;

            if (size == 1) cond.notify_all();

            lk.unlock();

            return true;

        }

        ~Queue() {
            for (size_t i = 0; i < size; i++) {
                delete tab[(begin + i) % alloc_size];
            }
            delete[] tab;
        }

    };

}

#endif //PR_TME4_QUEUE_H
