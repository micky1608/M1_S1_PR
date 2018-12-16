#include "Stack.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <sys/mman.h>
#include <fcntl.h>


using namespace std;
using namespace pr;

pid_t pp,pc;

void producteur (Stack<char> * stack) {
	char c ;
	while (cin.get(c)) {
		stack->push(c);
	}
}

void consomateur (Stack<char> * stack) {
	while (true) {
		char c = stack->pop();
		cout << c << endl << flush ;
	}
}

int main () {

	int shm_fd;

	do {
		shm_fd = shm_open("/shm" , O_RDWR | O_CREAT | O_EXCL , 0600);

		if(shm_fd == -1) {
			if(errno == EEXIST) {
				shm_unlink("/shm");
			}
			else {
				perror("Error shm_open");
				exit(EXIT_FAILURE);
			}

		}
	} while(shm_fd == -1);


    if(ftruncate(shm_fd , sizeof(Stack<char>)) == -1) {
        perror("Error ftruncate");
        exit(EXIT_FAILURE);
    }

    void *physical_seg = mmap(nullptr , sizeof(Stack<char>) , PROT_READ | PROT_WRITE , MAP_SHARED , shm_fd , 0);

    if(physical_seg == MAP_FAILED) {
        perror("Error mmap");
        exit(EXIT_FAILURE);
    }

    auto *s = new(physical_seg)Stack<char>();


	pp = fork();
	if (pp==0) {
		signal(SIGINT , [] (int nsig) {exit(0);});
		producteur(s);
		return 0;
	}

	pc = fork();
	if (pc==0) {
		signal(SIGINT , [] (int nsig) {exit(0);});
		consomateur(s);
		return 0;
	}

	signal(SIGINT , [] (int nsig) {
		kill(pp , SIGINT);
		kill(pc , SIGINT);
		exit(0);
	});


	wait(nullptr);
	wait(nullptr);

	s->~Stack();

	if(close(shm_fd) == -1) {
		perror("Error close");
		exit(EXIT_FAILURE);
	}

	if(munmap(physical_seg , sizeof(Stack<char>)) == -1) {
	    perror("Error munmap");
	    exit(EXIT_FAILURE);
	}

	if(shm_unlink("/shm") == -1) {
		perror("Error shm unlink");
		exit(EXIT_FAILURE);
	}

	return 0;
}

