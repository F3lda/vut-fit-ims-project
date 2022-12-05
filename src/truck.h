#ifndef TRUCK_H
#define TRUCH_H

#include <iostream>
#include <simlib.h>

// TODO: trucks
class Truck : public Process {
    private:
        Store *trucks;
        Stat *TRUCK_TRAVEL_BETWEEN_DEPOS_TIME;
        Stat *TRUCK_WORK_BETWEEN_DEPOS_TIME;
        Stat *TRUCK_WORK_AT_LAST_DEPO_TIME;

    public:
        Truck(Store *trucks);

        void Behavior();

};

#endif