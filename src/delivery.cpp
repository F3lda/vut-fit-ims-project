#include "delivery.h"
#include "delivery_timer.h"


Delivery::Delivery(unsigned long vans, double packagesAverage, double packagesDeviation, Depo *depo) {
    this->depo = depo;

    this->shiftState = new int();
    
    this->vans_working = new Store("Van store", vans);
    this->vans_return = new Store("Vans return", vans);
    this->vans_cancel = new Store("Vans cancel", vans);
    this->vans_done = new Store("Vans done", vans);


    vanBoxRideTime = new Stat("Total van ride distance to Box");
    vanNonBoxRideTime = new Stat("Total van ride distance to Deli point");
    vanLoadToPointTime = new Stat("Package loading time");
  

    cout << "=======================================================================\n"
		<< "Delivery shift started.\n"
		<< "\tStart time: " << Time << ".\n"
		<< "\tNumber of vans: " << this->vans_working->Capacity() << ".\n"
		<< endl;
}

void Delivery::Behavior() {

    DeliveryTimer *deliveryTimer = new DeliveryTimer(shiftState);
   
    // Next event
    int vans_started = vans_working->Capacity();
    while(vans_started > 0) {
        vans_started--;
        
        Enter(*vans_working, 1);
        cout << "Van Start" << endl;

        (new Van(vans_working, vanBoxRideTime, vanNonBoxRideTime, vanLoadToPointTime, shiftState, deliveryTimer))->Activate();
        
    }

    cout << "While DONE" << endl;
    Enter(*vans_working, vans_working->Capacity());
    Leave(*vans_working, vans_working->Capacity());
    cout << "WAIT DONE" << endl;
    //
    // Začátek směny u depa
    delete deliveryTimer;
}

Delivery::~Delivery() {

    delete shiftState;
    delete vans_working;
    delete vans_return;
    delete vans_cancel;
    delete vans_done;


    cout << "=======================================================================\n"
		<< "Delivery DESTRUCTOR.\n"
		<< "\tEnd Time: " << Time << ".\n"
		<< "\tTotal van ride distance to Box: " << vanBoxRideTime->Sum() << " minutes.\n"
        << "\tTotal van ride distance to Deli Point: " << vanNonBoxRideTime->Sum() << " minutes.\n"
		<< endl;
    /*
    cout << "=======================================================================\n"
		<< "Statistics of ride to BOX\n" << endl;
    vanBoxRideTime->Output();
    cout << "=======================================================================\n"
		<< "Statistics of ride to Deli Point\n" << endl;
    vanNonBoxRideTime->Output();
    delete vanBoxRideTime;
    delete vanNonBoxRideTime;
    delete vanLoadToPointTime;
    */
    /*
    for(Van *van : vans_list) {
      delete van;
    }*/

    
    //depo->Activate();
}

