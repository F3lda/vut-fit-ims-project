#ifndef TRUCK_H
#define TRUCH_H
#include <iostream>
#include <simlib.h>


class Van : public Process {
    private:
        const double VAN_LOADING_TIME_AVERAGE = 30;
        const double VAN_UNLOADING_TIME_AVERAGE = 45;
        const double TRUCK_JOURNEY_TIME_BETWEEN_DROP_POINTS = 12.5; // 10-15 minut?
        const double BOX_PROBABILITY = 0.695;

        /*
        * Počet zásilek v dodávce
        */
        unsigned long *packages;

        Store *vans_return;

        Stat *vanBoxRideTime;
        Stat *vanNonBoxRideTime;
        Stat *vanLoadTime;
        int *state;
        void *delivery_timer;

    public:
        static const long VAN_CAPACITY = 157; //viz zadani
        Van(
            Store *vans_return, 
            Stat *vanBoxRideTime, 
            Stat *vanNonBoxRideTime,
            Stat *vanLoadTime,
            int *state,
            void *delivery_timer
        );

        void Behavior() override;

        double averageUniformDistribution(double average, double deviation);

        ~Van();

};

#endif
