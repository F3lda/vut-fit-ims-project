#include "depo.h"

#include "worker.h"
#include "common.h"



using namespace std;

Depo::Depo(TruckWork *truckWork) {
    this->vans = new Store("Dodávky v Depu", CONST_VANS);
	this->workers = new Store("Zaměstnanci Depa", CONST_EMPLOYEES);
    this->trucks = new Store("Kamiony", CONST_TRUCKS);
    
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
		<< "\tNumber of trucks: " << trucks->Capacity() << ".\n"
		<< endl;



    unsigned long packages = this->vans->Capacity() * CONST_VAN_CAPACITY;
    cout << packages << endl;


    unsigned long unloading_packages = 0;
    (*unloaded_packages) = 0;
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
        if (unloading_packages == CONST_VAN_CAPACITY) {
            Enter(*vans, 1);
            unloading_packages = 0;
            //---
            unloading_vans++;

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
    cout << packages << endl;




    unsigned long loading_packages = 0;
    (*loaded_packages) = 0;
    int loading_trucks = 0;


    // pokud nejsou všechny dodávky prázdné
    while(loading_trucks != CONST_TRUCKS) {// počet kamionů

        // do kamionu je právě nakládán jeden balík jedním zaměstnancem
        Enter(*workers, 1);
        Enter(*trucks, 1);
        //---
        Leave(*trucks, 1);
        loading_packages++;
        (new Worker(trucks, workers, loaded_packages, 0))->Activate();

        

        // právě je nakládán a naložen jeden kamion
        if (loading_packages == CONST_TRUCK_CAPACITY) {
            Enter(*trucks, 1);
            loading_packages = 0;
            //---
            loading_trucks++;

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
    
    delete vans;
    delete workers;
    delete trucks;



    cout << "=======================================================================\n"
		<< "Depo shift ended ended.\n"
		<< "\tEnd Time: " << Time << ".\n"
		<< endl;



    truckWork->Activate();
}
