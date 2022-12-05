#include "depo.h"
#include "depo_timer.h"
//#include "van_working.h"
#include "worker.h"

using namespace std;

Depo::Depo(unsigned long van_count) {
    this->vans = new Store("Dodávky v Depu", van_count);
	this->workers = new Store("Zaměstnanci Depa", 26);
    this->packages = new Store("Balíky pro dodávku", 157);
}

void Depo::Behavior() {
    cout << "=======================================================================\n"
		<< "Depo shift started.\n"
		<< "\tStart time: " << Time << " minutes.\n"
		<< "\tNumber of vans: " << vans->Capacity() << ".\n"
		<< "\tNumber of workers: " << workers->Capacity() << ".\n"
		<< endl;
	//DepoTimer *depoTimer = new DepoTimer(this);
	// Next event
    unsigned long packages = this->vans->Capacity() * 157;//156;
    unsigned long unloading_packages = 0;
    unsigned long unloaded_packages = 0;
    cout << packages << endl;
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
            cout << unloading_vans <<" Van unloading" << endl;
            unloading_packages = 0;
            unloading_vans += 1;
            Enter(*vans, 1);
        }

        (new Worker(vans, workers, this))->Activate();

        unloaded_packages++;
        
        //cout << unloaded << endl;
        if (unloaded_packages == 157) {//Van::VAN_CAPACITY;
            cout << "Van fully unloaded" << endl;
            unloaded_packages = 0;
            empty_vans += 1;
        }

        if (empty_vans == (int)vans->Capacity()) {
            Passivate();
        }
    }
    
    cout << "Van Unloading end\n";
    if(vans->Full() && workers->Empty()) {
        cout << "DONE!\n";
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
}