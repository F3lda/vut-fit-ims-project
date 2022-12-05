#ifndef DEPO_H
#define DEPO_H

#include <simlib.h>
#include "truck_work.h"



/*
* Třída reprezentující práci v Depu od 16:00 do 8:00
*/
class Depo : public Process {
    private:
        /*
        * Sklad dodávek
        */
        Store *vans;

        /*
        * Sklad zaměstnanců
        */
        Store *workers;

        /*
        * Sklad balíků
        */
        Store *trucks;

        TruckWork *truckWork;

        unsigned long *unloaded_packages;
        unsigned long *loaded_packages;
        
    public:
        /*
        * Kontruktor
        */
        Depo(TruckWork *truckWork);

        /*
        * Desktruktor
        */
        ~Depo();

        /*
        * behavior metoda
        */
        void Behavior() override;
};

#endif
