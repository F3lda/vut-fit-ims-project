#include "delivery_timer.h"
#ifndef DELIVERY_H
#define DELIVERY_H

#include <simlib.h>
#include <iostream>
#include <vector>
#include "depo.h"

using namespace std;
/*
* Třída reprezentující směnu dodávek od 8 do 16
*/

class Van;

class Delivery : public Process
{
    private:
        /*
        * Sklad dodávek
        */
        Store *vans;


        Store *vans_return;

        Store *vans_cancel;
        
        Store *vans_done;

        /*
        * Statistika určující čas cesty na box
        */
        Stat *vanBoxRideTime;

        /*
        * Statistika určující čas cesty na klasickou výdejnu
        */
        Stat *vanNonBoxRideTime;

        /*
        * Statistika určující čas výkládání zásilky na výdejně/boxu
        */
        Stat *vanLoadToPointTime;

        Depo *depo;

        //DeliveryTimer *deliveryTimer;

        int *state;
        
    public:
        /*
        * Kontruktor
        */
        Delivery(unsigned long vans, double averagePackages, double packagesDeviation, Depo *depo);

        /*
        * Desktruktor
        */
        ~Delivery();

        /*
        * behavior metoda
        */
        void Behavior() override;

        /*
        * Tisk informací na konci rozvážecí směny
        */
        void printDeliveryEnd();

        vector<Van*> vans_list;

        int removeVan(Van van);
};

#endif