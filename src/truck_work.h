#ifndef TRUCKWORK_H
#define TRUCKWORK_H

#include <iostream>
#include <simlib.h>
#include "truck.h"
#include "van_load.h"
/*
* Třída reprezentující práci kamionů po výkladu balíků v jednotlivých depech (od 16:00 do 8:00)
*/
class TruckWork : public Process {
    private:
        Store *trucks;
        VanLoad *vanLoad;
    public:
        TruckWork(VanLoad *vanLoad);
        void Behavior();
        ~TruckWork();
};

#endif