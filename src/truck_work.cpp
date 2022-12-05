#include "truck_work.h"

using namespace std;

TruckWork::TruckWork(VanLoad *vanLoad) {
    this->trucks = new Store("Sklad kamionů", 4);
	this->vanLoad = vanLoad;
}

void TruckWork::Behavior() {
    cout << "=======================================================================\n"
		<< "Truck shift started.\n"
		<< "\tStart time: " << Time/60 << " hours.\n"
		<< "\tNumber of trucks: " << this->trucks->Capacity() << ".\n"
		<< endl;
    Enter(*trucks, 1);
    (new Truck(trucks))->Activate();
    Enter(*trucks, trucks->Capacity());
    Leave(*trucks, trucks->Capacity());
}

TruckWork::~TruckWork() {
    cout << "\n"
		<< "Truck shift ended.\n"
		<< "\tEnd time: " << Time/60 << " hours.\n"
		<< endl;
	vanLoad->Activate();
}