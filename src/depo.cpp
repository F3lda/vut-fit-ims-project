#include "depo.h"
#include "depo_timer.h"
//#include "van_working.h"
#include "worker.h"

using namespace std;

Depo::Depo(unsigned long van_count, TruckWork *truckWork) {
    this->vans = new Store("Dodávky v Depu", van_count);
	this->workers = new Store("Zaměstnanci Depa", 26);
    this->trucks = new Store("Kamiony", 157);
    this->truckWork = truckWork;

    this->unloaded_packages = new long unsigned int();
    this->loaded_packages = new long unsigned int();
}

void Depo::Behavior() {
    cout << "=======================================================================\n"
		<< "Depo shift started.\n"
		<< "\tStart time: " << Time << " minutes.\n"
		<< "\tNumber of vans: " << vans->Capacity() << ".\n"
		<< "\tNumber of workers: " << workers->Capacity() << ".\n"
		<< endl;



    unsigned long packages = this->vans->Capacity() * 157;//156;//Van::VAN_CAPACITY;
    unsigned long packagesPerVan = 157;//156;//Van::VAN_CAPACITY;

    unsigned long unloading_packages = 0;
    (*unloaded_packages) = 0;
    cout << packages << endl;
    int unloading_vans = 0;


    // pokud nejsou všechny dodávky prázdné
    while(unloading_vans != (int)vans->Capacity()) {

        // z dodávky je vykládán jeden balík jedním zaměstnancem
        Enter(*workers, 1);
        Enter(*vans, 1);
        //---
        Leave(*vans, 1);
        unloading_packages++;
        (new Worker(vans, workers, unloaded_packages, 1))->Activate();

        

        // právě je vykládána a vyložena jedna dodávka
        if (unloading_packages == packagesPerVan) {
            Enter(*vans, 1);
            unloading_packages = 0;
            //---
            unloading_vans += 1;


            cout << unloading_vans <<" Van unloading" << endl;
        }


        packages--;

    }
    
    // čekání na vyložení všech dodávek a na všechny zaměstnance
    cout << "DEPO DONE: " << packages << endl;
    Enter(*vans, vans->Capacity());
    Leave(*vans, vans->Capacity());
    Enter(*workers, workers->Capacity());
    Leave(*workers, workers->Capacity());
    
    cout << "DEPO DONE: " << *unloaded_packages << endl;
    cout << "DEPO DONE: " << Time << endl;


    cout << "=======================================================================\n"
		<< "Van unloading at depo ended.\n"
		<< "\tEnd Time: " << Time << ".\n"
		<< endl;
    cout << "=======================================================================\n"
		<< "Truck loading at depo started.\n"
		<< "\tEnd Time: " << Time << ".\n"
		<< endl;






    unsigned long packagesPerTruck = packagesPerVan*6;//156;//Van::VAN_CAPACITY;

    unsigned long loading_packages = 0;
    (*loaded_packages) = 0;
    cout << packages << endl;
    int loading_trucks = 0;


    // pokud nejsou všechny dodávky prázdné
    while(loading_trucks != 4) {// počet kamionů

        // do kamionu je právě nakládán jeden balík jedním zaměstnancem
        Enter(*workers, 1);
        Enter(*trucks, 1);
        //---
        Leave(*trucks, 1);
        loading_packages++;
        (new Worker(trucks, workers, loaded_packages, 0))->Activate();

        

        // právě je nakládán a naložen jeden kamion
        if (loading_packages == packagesPerTruck) {
            Enter(*trucks, 1);
            loading_packages = 0;
            //---
            loading_trucks += 1;


            cout << loading_trucks <<" Van unloading" << endl;
        }


        packages++;

    }
    
    // čekání na vyložení všech dodávek a na všechny zaměstnance
    cout << "DEPO DONE: " << packages << endl;
    Enter(*vans, vans->Capacity());
    Leave(*vans, vans->Capacity());
    Enter(*workers, workers->Capacity());
    Leave(*workers, workers->Capacity());
    cout << "DEPO DONE: " << *loaded_packages << endl;
    cout << "DEPO DONE: " << Time << endl;



    cout << "=======================================================================\n"
		<< "Truck loading at depo ended.\n"
		<< "\tEnd Time: " << Time << ".\n"
		<< endl;
}

Depo::~Depo() {
    delete unloaded_packages;
    delete loaded_packages;
    //delete vans;
    //delete workers;
    //delete trucks;



    cout << "=======================================================================\n"
		<< "Depo shift ended ended.\n"
		<< "\tEnd Time: " << Time << ".\n"
		<< endl;

    truckWork->Activate();
}
