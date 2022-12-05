#ifndef TRUCKWORK_H
#define TRUCKWORK_H

#include <iostream>
#include <simlib.h>
#include "truck.h"
/*
* Třída reprezentující práci kamionů po výkladu balíků v jednotlivých depech (od 16:00 do 8:00)
*/
class TruckWork : public Process {
    private:
        Store *trucks;
    public:
        TruckWork();
        void Behavior();
        ~TruckWork();
};

#endif