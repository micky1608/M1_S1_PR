
#include <unistd.h>
#include <sys/types.h>
#include <thread>
#include <signal.h>
#include "Battle.h"

bool micky::father;
size_t micky::life_points = INITIAL_LIFE_POINTS;

int main() {

	pid_t pid_father = getpid();
	pid_t pid_son;

	micky::father = true;

	// install handler SIGUSR1
	struct sigaction action_sigusr1;
	action_sigusr1.sa_handler = micky::handler_SIGUSR1;
	sigaction(SIGUSR1 , &action_sigusr1 , nullptr);

	// mask SIGUSR1
	sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask , SIGUSR1);
	sigprocmask(SIG_BLOCK , &mask , nullptr);

	// ignore the signal SIGINT
	struct sigaction action_ignore;
	action_ignore.sa_handler = SIG_IGN;
	sigaction(SIGINT , &action_ignore , nullptr);


	if((pid_son = fork()) == 0) {
		micky::father = false;
		srand(time(nullptr));
		std::cout << "\t\t\t\t\t\tI'm the son : " << getpid() << std::endl;
		std::cout << "\t\t\t\t\t\tMy father is : " << pid_father << std::endl;
		micky::fight(pid_father);
	}


	if(pid_son) {
		srand(time(nullptr));
		std::cout << "I'm the father : " << getpid() << std::endl;
		std::cout << "My son is : " << pid_son << std::endl;

		// install handler SIGCHLD
		struct sigaction action_sigchld;
		action_sigchld.sa_handler = micky::handler_sigchild;
		sigaction(SIGCHLD , &action_sigchld , nullptr);

		micky::fight(pid_son);

	}






}



