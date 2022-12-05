#include "delivery.h"
#include "van.h"

Delivery::Delivery(unsigned long vans, double packagesAverage, double packagesDeviation, Depo *depo) {
    this->vans = new Store("Van store", vans);
    this->depo = depo;
    vanBoxRideTime = new Stat("Total van ride distance to Box");
    vanNonBoxRideTime = new Stat("Total van ride distance to Deli point");
    vanLoadToPointTime = new Stat("Package loading time");
    //this->deliveryTimer = new DeliveryTimer(this);

    this->vans_return = new Store("Vans return", vans);

    cout << "=======================================================================\n"
		<< "Delivery shift started.\n"
		<< "\tStart time: " << Time << ".\n"
		<< "\tNumber of vans: " << this->vans->Capacity() << ".\n"
		<< endl;

    this->state = new int();
}

void Delivery::Behavior() {

    DeliveryTimer *deliveryTimer = new DeliveryTimer(this, state);
    // Next event
    int vans_started = vans->Capacity();
    while(vans_started > 0) {
        Enter(*vans, 1);
        vans_started--;
        cout << "Van Start" << endl;
        Van *van = new Van(vans, vanBoxRideTime, vanNonBoxRideTime, vanLoadToPointTime, state);
        vans_list.push_back(van);
        van->Activate();
    }
    cout << "While DONE" << endl;
    Enter(*vans, vans->Capacity());
    Leave(*vans, vans->Capacity());
    cout << "WAIT DONE" << endl;
    //
    // Začátek směny u depa
    delete deliveryTimer;
}

Delivery::~Delivery() {
    //delete deliveryTimer;

    //delete vans;
    delete vans_return;

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
    depo->Activate();
}

