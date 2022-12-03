#include "depo.h"
//#include "depo_timer.h"
#include "van.h"

using namespace std;

DepoWork::DepoWork(Store *vans) {
    //this->vans = vans;
    cout << "Hello" << endl;
}

void DepoWork::Behavior() {
    cout << "=======================================================================\n"
		<< "Depo shift started.\n"
		<< "\tStart time: " << Time << ".\n"
		<< "\tNumber of vans: " << this->vans->Capacity() << ".\n"
		<< endl;
}

DepoWork::~DepoWork() {
	cout << "Desktruktor" << endl;
}