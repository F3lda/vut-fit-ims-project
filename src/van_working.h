#ifndef VAN_WORKING_H
#define VAN_WORKING_H

#include <iostream>
#include <simlib.h>



class VanWorking : public Process {
    private:
        Store *vans_working;
        int *state;
        void *delivery_timer;
        Stat *vanBoxRideTime;
        Stat *vanNonBoxRideTime;
        Stat *vanCanceledRemainingTime;
        Stat *vanReturnRideTime;

        double rideTime = 0;

    public:
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
