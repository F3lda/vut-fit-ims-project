#include "delivery.h"
#include "delivery_timer.h"
#include "van.h"

using namespace std;

Delivery::Delivery(unsigned long vans, double packagesAverage, double packagesDeviation) {  
    this->vans = new Store("Van store", vans);
    double deviationValue = packagesDeviation / 100.0 * packagesAverage;
	this->packages = new unsigned long(static_cast<unsigned long>(
        Uniform(packagesAverage - deviationValue, packagesAverage + deviationValue)
    ));
    //TODO: Remainder?
    vanBoxRideTime = new Stat("Total van ride distance to Box");
    vanNonBoxRideTime = new Stat("Total van ride distance to Deli point");
    vanLoadToPointTime = new Stat("Package loading time");

    cout << "===================================================\n"
		<< "Delivery shift started.\n"
		<< "\tStart time: " << Time << ".\n"
		<< "\tNumber of vans: " << this->vans->Capacity() << ".\n"
		<< "\tNumber of packages: " << this->packages << ".\n"
		<< endl;
}

void Delivery::Behavior() {
    auto *deliveryTimer = new DeliveryTimer(this);
    
    // Next event
    while(*packages > 0) {
        Enter(*vans, 1);

        if(*packages == 0) {
            Leave(*vans, 1);
            break;
        }

        *packages -= Van::VAN_CAPACITY;

        (new Van(vans, vanBoxRideTime, vanNonBoxRideTime, vanLoadToPointTime))->Activate();
    }
}


Delivery::~Delivery() {
    cout << "===================================================\n"
		<< "Delivery shift ended.\n"
		<< "\tNumber of packages left: " << this->packages << ".\n"
		<< "\tTotal van ride distance to Box: " << vanBoxRideTime->Sum() << ".\n"
        << "\tTotal van ride distance to Deli point: " << vanNonBoxRideTime->Sum() << ".\n"
		<< endl;
}
