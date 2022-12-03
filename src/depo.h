#ifndef DEPO_H
#define DEPO_H

#include <simlib.h>

/*
* Třída reprezentující práci v Depu od 16:00 do 8:00
*/
class DepoWork : public Process {
    private:
        /*
        * Sklad dodávek
        */
        Store *vans;

        
    public:
        /*
        * Kontruktor
        */
        DepoWork(Store *vans);

        /*
        * Desktruktor
        */
        ~DepoWork();

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