#ifndef DEPO_H
#define DEPO_H

#include <simlib.h>

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
        
    public:
        /*
        * Kontruktor
        */
        Depo(Store *vans);

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