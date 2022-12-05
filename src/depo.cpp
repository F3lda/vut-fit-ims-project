#include "depo.h"
#include "depo_timer.h"
//#include "van_working.h"
#include "worker.h"

using namespace std;

Depo::Depo(unsigned long van_count, TruckWork *truckWork) {
    this->vans = new Store("Dodávky v Depu", van_count);
	this->workers = new Store("Zaměstnanci Depa", 26);
    this->packages = new Store("Balíky pro dodávku", 157);
    this->truckWork = truckWork;
}

void Depo::Behavior() {
    unsigned long packages = this->vans->Capacity() * 157;//156;
    unsigned long unloading_packages = 0;
    unsigned long unloaded_packages = 0;
    cout << "=======================================================================\n"
		<< "Depo shift started.\n"
		<< "\tStart time: " << Time << " minutes." << endl
		<< "\tNumber of vans: " << vans->Capacity() << endl
		<< "\tNumber of workers: " << workers->Capacity() << endl
        << "\tNumber of packages" << packages << endl
		<< endl;
	//DepoTimer *depoTimer = new DepoTimer(this);
	// Next event
    //Store empty_vans = new Store(13);
    int unloading_vans = 0;
    int empty_vans = 0;
    while(packages > 0) {
        Enter(*workers, 1);
        Enter(*vans, 1);
        Leave(*vans, 1);

        unloading_packages++;
        packages--;

        if (unloading_packages == 157) {//Van::VAN_CAPACITY;
            unloading_packages = 0;
            unloading_vans += 1;
            Enter(*vans, 1);
            cout << unloading_vans << ". Van unloading at time " << Time << endl;
        }

        (new Worker(vans, workers, this))->Activate();

        unloaded_packages++;
        
        //cout << unloaded << endl;
        if (unloaded_packages == 157) {//Van::VAN_CAPACITY;
            cout << unloading_vans << ". Van fully unloaded at time " << Time << endl;
            unloaded_packages = 0;
            empty_vans += 1;
        }

        if (empty_vans == (int)vans->Capacity()) {
            Passivate();
        }
    }
    
    if(vans->Full() && workers->Empty()) {
        cout << "DONE unloading! At time: " << Time << endl;
    }
    //Enter(*vans, vans->Capacity());
    //Leave(*vans, vans->Capacity());
    //Enter(*workers, workers->Capacity());
    //Leave(*workers, workers->Capacity());
    //delete depoTimer;
}

Depo::~Depo() {
    //delete vans;
    //delete workers;
    cout << "=======================================================================\n"
		<< "Van unloading at depo ended.\n"
		<< "\tEnd Time: " << Time << ".\n"
		<< endl;

    truckWork->Activate();
}