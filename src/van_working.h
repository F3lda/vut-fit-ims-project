#ifndef VAN_WORKING_H
#define VAN_WORKING_H

#include <iostream>
#include <simlib.h>



class VanWorking : public Process {
    private:
        const double VAN_LOADING_TIME_AVERAGE = 30;
        const double VAN_UNLOADING_TIME_AVERAGE = 45;
        const double TRUCK_JOURNEY_TIME_BETWEEN_DROP_POINTS = 12.5; // 10-15 minut?
        const double BOX_PROBABILITY = 0.695;


        Store *vans_working;
        int *state;
        void *delivery_timer;
        Stat *vanBoxRideTime;
        Stat *vanNonBoxRideTime;
        Stat *vanCanceledRemainingTime;
        Stat *vanReturnRideTime;

        double rideTime = 0;

    public:
        static const long VAN_CAPACITY = 157; //viz zadani
        VanWorking(
            Store *vans_working,
            int *state,
            void *delivery_timer,
            Stat *vanBoxRideTime,
            Stat *vanNonBoxRideTime,
            Stat *vanCanceledRemainingTime,
            Stat *vanReturnRideTime
        );

        void Behavior() override;

        ~VanWorking();

};

#endif
