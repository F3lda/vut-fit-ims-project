#include "depo.h"
#include "depo_timer.h"
#include "van.h"
#include "worker.h"

using namespace std;

Depo::Depo(Store *vans) {
    this->vans = vans;
	this->workers = new Store("Zaměstnanci Depa", 26);
}

void Depo::Behavior() {
    cout << "=======================================================================\n"
		<< "Depo shift started.\n"
		<< "\tStart time: " << Time << " minutes.\n"
		<< "\tNumber of vans: " << vans->Capacity() << ".\n"
		<< "\tNumber of workers: " << workers->Capacity() << ".\n"
		<< endl;
	
	DepoTimer *depoTimer = new DepoTimer(this);
	// Next event
    while(this->vans->Capacity() != 0 && this->workers->Capacity() != 0) {
        Enter(*workers, 1);
        (new Worker(vans, workers))->Activate();
    }
    Enter(*vans, vans->Capacity());
    Leave(*vans, vans->Capacity());
    delete depoTimer;
}

Depo::~Depo() {
    delete vans;
    delete workers;
}