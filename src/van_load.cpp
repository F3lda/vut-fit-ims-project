#include "van_load.h"

#include "common.h"



using namespace std;

VanLoad::VanLoad() {
    this->vans = new Store("Sklad dodávek", CONST_VANS);
    this->loadTime = new Stat("Čas nakládání");
}

void VanLoad::Behavior() {
    cout << "=======================================================================\n"
		<< "Van load at depo shift started.\n"
		<< "\tStart time: " << Time/60 << " hours\n"
		<< "\tNumber of vans: " << this->vans->Capacity() << ".\n"
		<< endl;
    Enter(*vans, 1);
    double depoLoadTime = Uniform(CONST_VAN_LOAD_TIME_MIN, CONST_VAN_LOAD_TIME_MAX);
    (*loadTime)(depoLoadTime);
    Wait(depoLoadTime);

    Leave(*vans, 1);
}

VanLoad::~VanLoad() {
    cout << "=======================================================================\n"
		<< "Van load at depo shift ended.\n"
		<< "\tEnd time: " << Time/60 << " hours.\n"
		<< endl;



    if (Time < CONST_WORKING_SHIFT_LENGTH) {
        cout << "LOAD SHIFT done on time (<8:00)" << endl;
    } else {
        cout << "LOAD SHIFT not done on time (<8:00)" << endl;
    }
}
