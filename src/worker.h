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
        Store *vehicles;

        Store *workers;

        long unsigned int *packages;

        int unloading;

    public:
        Worker(Store *vehicles, Store *workers, long unsigned int *packages, int unloading);

        void Behavior() override;

        double averageUniformDistribution(double average, double deviation);
};

#endif
