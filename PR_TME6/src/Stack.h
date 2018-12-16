#pragma once

#include <cstring> // size_t,memset
#include <semaphore.h>
#include <iostream>

namespace pr {

#define STACKSIZE 100

template<typename T>
class Stack {
	T tab [STACKSIZE];
	size_t sz;

    sem_t sem_mutex , sem_empty , sem_full;
public :
	Stack () : sz(0) {
    memset(tab,0,sizeof tab) ;

    sem_init(&sem_mutex , 1 , 1);
    sem_init(&sem_empty , 1 , 0);
    sem_init(&sem_full , 1 , STACKSIZE);
}

    ~Stack() {
        sem_destroy(&sem_mutex);
        sem_destroy(&sem_empty);
        sem_destroy(&sem_full);
    }

	T pop () {
        sem_wait(&sem_empty);
        sem_wait(&sem_mutex);

		T toret = tab[--sz];

		sem_post(&sem_mutex);
		sem_post(&sem_full);

		return toret;
	}

	void push(T elt) {

        sem_wait(&sem_full);
        sem_wait(&sem_mutex);

		tab[sz++] = elt;

		sem_post(&sem_mutex);
		sem_post(&sem_empty);
	}
};

}
