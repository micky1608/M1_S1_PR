

#ifndef PR_TME4_JOB_H
#define PR_TME4_JOB_H


namespace pr {

    class Job {

    public:

        virtual void run() = 0;
        virtual ~Job() = default;

    };
}


#endif
