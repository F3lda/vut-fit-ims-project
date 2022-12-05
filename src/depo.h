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
        Store *packages;

        TruckWork *truckWork;
        
    public:
        /*
        * Kontruktor
        */
        Depo(unsigned long van_count, TruckWork *truckWork);

        /*
        * Desktruktor
        */
        ~Depo();

        /*
        * behavior metoda
        */
        void Behavior() override;

        /*
        * Tisk informací na konci rozvážecí směny
        */
        void printDepoEnd();
};

#endif