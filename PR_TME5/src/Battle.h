//
// Created by root on 23/10/18.
//

#ifndef PR_TME5_BATTLE_H
#define PR_TME5_BATTLE_H

#include <sys/types.h>
#include "signal.h"
#include "rsleep.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

#define INITIAL_LIFE_POINTS 5



namespace micky {

	extern size_t life_points;
	extern bool father;

    void attack(pid_t pid_opponent);

    void defense();

    void fight(pid_t pid_opponent);

    void handler_SIGINT(int nsig);

    void handler_SIGUSR1(int nsig);

    void handler_sigchild(int nsig);

    void wait_begin_fight();

    void signal_begin_fight(pid_t pid_opponent);


}

#endif //PR_TME5_BATTLE_H
