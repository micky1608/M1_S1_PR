//
// Created by root on 18/10/18.
//

#ifndef PR_TME4_JOB_H
#define PR_TME4_JOB_H

#include <iostream>
#include <chrono>
#include <thread>
#include "Job.h"
#include "Vec3D.h"
#include "Rayon.h"
#include "Scene.h"
#include "Barrier.h"


namespace micky {

    class Job {

    public:

        virtual void run() = 0;
        ~Job();

    };


    class FirstJob : public Job {

        int arg;
        int *res;

    public:

        FirstJob(int a , int *r);
        void run();

    };

    class PixelJob : public Job {

        const int x;
        const int y;
        const pr::Scene::screen_t& screen;
        pr::Scene& scene;
        std::vector<pr::Vec3D>& lights;
        pr::Color *pixels;

        micky::Barrier& barrier;


    public:
        PixelJob(micky::Barrier& b, int x , int y , const pr::Scene::screen_t& s , pr::Scene& sc , std::vector<pr::Vec3D>& l , pr::Color *p);
        void run();
    };

}




#endif //PR_TME4_JOB_H
