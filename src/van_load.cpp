#include "van_load.h"

using namespace std;

VanLoad::VanLoad(unsigned long van_count) {
    this->vans = new Store("Sklad dodávek", van_count);
    this->loadTime = new Stat("Čas nakládání");

}

void VanLoad::Behavior() {
    cout << "=======================================================================\n"
		<< "Van load at depo shift started.\n"
		<< "\tStart time: " << Time/60 << " hours\n"
		<< "\tNumber of vans: " << this->vans->Capacity() << ".\n"
		<< endl;
    Enter(*vans, 1);
    double depoLoadTime = Uniform(74, 84);
    (*loadTime)(depoLoadTime);
    Wait(depoLoadTime);

    Leave(*vans, 1);
}

VanLoad::~VanLoad() {
    cout << "=======================================================================\n"
		<< "Van load at depo shift started.\n"
		<< "\tEnd time: " << Time/60 << " hours.\n"
		<< endl;
    if (Time < 24*60) {
        cout << "LOAD SHIFT done on time (<8:00)" << endl;
    } else {
        cout << "LOAD SHIFT not done on time (<8:00)" << endl;
    }
}