//
// Created by root on 26/10/18.
//

#include "Wait.h"


namespace micky {

    int wait_till_pid(pid_t pid) {
        if(pid < 0) return -1;

        pid_t pid_son;

        do {
            pid_son = wait(nullptr);
        } while ((pid_son != pid) && (pid_son != -1));

        return pid_son;
    }


    int wait_pid_timer(pid_t pid , unsigned int sec) {

        sonPid = pid;

        // install handler SIGCHLD
        struct sigaction action_sigchld;
        action_sigchld.sa_flags = SA_SIGINFO;
        action_sigchld.sa_sigaction = handler_sigchld;
        sigaction(SIGCHLD , &action_sigchld , nullptr);

        // install handler SIGALRM
        struct sigaction action_sigalrm;
        action_sigalrm.sa_handler = handler_sigalrm;
        sigaction(SIGALRM , &action_sigalrm , nullptr);

        alarm(sec);

        while(!sonEnd && !timerEnd) sleep(1);

        if(sonEnd)
            alarm(0);
        else {
            timerEnd = false;
            return 0;
        }

        sonEnd = false;
        timerEnd = false;

        return sonPid;

    }

    void handler_sigalrm(int nsig) {
        timerEnd = true;
    }

    void handler_sigchld(int nsig , siginfo_t *info , void *option) {
        if(info->si_pid == sonPid)
            sonEnd = true;
    }


}