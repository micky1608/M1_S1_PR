//
// Created by root on 23/10/18.
//

#include "Battle.h"


namespace micky {

    /**
     * Install a handler for the SIGINT signal -> decrement the life points and display the points remaining. If 0 is reached, the the process ends returning 1.
     * Then, send a SIGINT signal to the opponent. If error, we suppose that the opponent has already lost, the process ends returning 0.
     * Sleep for a random time.
     * @param pid_opponent
     */
    void attack(pid_t pid_opponent) {

    	std::cout << (father ? "" : "\t\t\t\t\t\t") << "ATTACK" << std::endl;

        // install handler for SIGINT
        struct sigaction action;
        action.sa_handler = handler_SIGINT;
        sigaction(SIGINT , &action , nullptr);

        // send SIGINT to the opponent
        if(kill(pid_opponent , SIGINT) == -1) {
        	std::cout << (father ? "" : "\t\t\t\t\t\t") << "WIN !!!" << std::endl;
        	exit(0);
        }

        else
        	std::cout << (father ? "" : "\t\t\t\t\t\t") << "Kill success to " << pid_opponent << std::endl;


        // sleep for a random time
        randsleep();
    }

    /**
     * Ignore SIGINT and sleep for a random time
     */
    void defense() {

    	std::cout << (father ? "" : "\t\t\t\t\t\t") << "DEFENSE" << std::endl;

        // ignore the signal SIGINT
        struct sigaction action_ignore;
        action_ignore.sa_handler = SIG_IGN;
        sigaction(SIGINT , &action_ignore , nullptr);

        randsleep();
    }

    /**
     * indefinite loop on attack/defense
     * @param pid_opponent
     */
    void fight(pid_t pid_opponent) {
    	signal_begin_fight(pid_opponent);
    	wait_begin_fight();
    	if(father)
    		std::cout << "\t\t\t***** BEGIN FIGHT *****" << std::endl;

        while(true) {
            attack(pid_opponent);
            defense();
        }
    }

    /**
     * Action performed when SIGINT is received.
     * Life points are decremented and the points remaining are displayed.
     * If 0 is reached, end of the process returning 0
     */
    void handler_SIGINT(int nsig) {
        life_points--;

        std::cout << (father ? "" : "\t\t\t\t\t\t") << "Life points : " << life_points << std::endl;

        if(!life_points) {
            std::cout << (father ? "" : "\t\t\t\t\t\t") << "LOSE !!!" << std::endl;

            if(!father) {
            	if(kill(getppid() , SIGCHLD) == -1) {
            		perror("Error send SIGCHILD");
            		exit(-3);
            	}
            }
            exit(1);
        }

    }

    /**
     * The SIGUSR1 signal is sent by a process to his opponent inform that it is ready to fight
     */
    void handler_SIGUSR1(int nsig) {
    	std::cout << (father ? "" : "\t\t\t\t\t\t") << "Opponent ready" << std::endl;
    }


    /**
     * Wait until SIGUSR1 is received
     */
    void wait_begin_fight() {

    	sigset_t sigpend , sigset, mask;

       	sigfillset(&sigset);
       	sigdelset(&sigset , SIGUSR1);

       	sigfillset(&mask);
       	sigaddset(&mask , SIGUSR1);

       	sigemptyset(&sigpend);
       	sigpending(&sigpend);


       	if(!sigismember(&sigpend , SIGUSR1)) {
       		sigsuspend(&sigset);
       	}


		sigprocmask(SIG_UNBLOCK , &mask , nullptr);
    }

    /**
     * Send SIGUSR1 to the opponent
     */
    void signal_begin_fight(pid_t pid_opponent) {
    	if(kill(pid_opponent , SIGUSR1) == -1) {
    		perror("Error sending SIGUSR1");
    		exit(-2);
    	}
    }

    /**
     *	If the son loses, the process sends SIGCHLD to his father. Then, the father uses wait() to not have a zombie process.
     */
    void handler_sigchild(int nsig) {
    	wait(nullptr);
    }


}

