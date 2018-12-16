//
// Created by root on 26/10/18.
//

#ifndef TME5_MICKY1608_WAIT_H
#define TME5_MICKY1608_WAIT_H

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <chrono>
#include <thread>



namespace micky {

    bool sonEnd = false;

    bool timerEnd = false;

    pid_t sonPid;

    int wait_till_pid(pid_t pid);

    int wait_pid_timer(pid_t pid , unsigned int sec);

    void handler_sigalrm(int nsig);

    void handler_sigchld(int nsig, siginfo_t *info , void *option);
}

#endif //TME5_MICKY1608_WAIT_H
