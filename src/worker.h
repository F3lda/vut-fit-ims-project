#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <simlib.h>


class Worker : public Process {
    private:
        /*
        * Počet zásilek v dodávce
        */
        Store *vans;

        Store *workers;

    public:

        Worker(Store *vans,Store *workers);

        void Behavior() override;

        double averageUniformDistribution(double average, double deviation);

        ~Worker();

};

#endif