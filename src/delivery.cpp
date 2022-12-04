#include "delivery.h"
#include "delivery_timer.h"
#include "van.h"
#include "depo.h"

using namespace std;

Delivery::Delivery(unsigned long vans, double packagesAverage, double packagesDeviation) {
    this->vans = new Store("Van store", vans);
    vanBoxRideTime = new Stat("Total van ride distance to Box");
    vanNonBoxRideTime = new Stat("Total van ride distance to Deli point");
    vanLoadToPointTime = new Stat("Package loading time");

    cout << "=======================================================================\n"
		<< "Delivery shift started.\n"
		<< "\tStart time: " << Time << ".\n"
		<< "\tNumber of vans: " << this->vans->Capacity() << ".\n"
		<< endl;
}

void Delivery::Behavior() {
    
    DeliveryTimer *deliveryTimer = new DeliveryTimer(this);
    
    // Next event
    while(this->vans->Capacity() != 0) {
        Enter(*vans, 1);

        (new Van(vans, vanBoxRideTime, vanNonBoxRideTime, vanLoadToPointTime))->Activate();
    }

    Enter(*vans, vans->Capacity());
    Leave(*vans, vans->Capacity());
    delete deliveryTimer;
    // Začátek směny u depa
}

Delivery::~Delivery() {
    cout << "=======================================================================\n"
		<< "Delivery DESTRUCTOR.\n"
		<< "\tEnd Time: " << Time << ".\n"
		<< "\tTotal van ride distance to Box: " << vanBoxRideTime->Sum() << " minutes.\n"
        << "\tTotal van ride distance to Deli Point: " << vanNonBoxRideTime->Sum() << " minutes.\n"
		<< endl;
    cout << "=======================================================================\n"
		<< "Statistics of ride to BOX\n" << endl;
    vanBoxRideTime->Output();
    cout << "=======================================================================\n"
		<< "Statistics of ride to Deli Point\n" << endl;
    vanNonBoxRideTime->Output();
    Depo *depo = new Depo(this->vans);
    depo->Activate();
}
