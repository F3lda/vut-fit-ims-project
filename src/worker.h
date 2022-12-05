#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <simlib.h>
#include "depo.h"


class Worker : public Process {
    private:
        /*
        * Počet zásilek v dodávce
        */
        Store *vans;

        Store *workers;

        Stat *workerWorkTime;

        Depo *depo;

    public:

        Worker(Store *vans,Store *workers, Depo *depo);

        void Behavior() override;

        double averageUniformDistribution(double average, double deviation);

};

#endif