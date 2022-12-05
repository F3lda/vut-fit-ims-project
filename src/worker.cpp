#include "worker.h"

using namespace std;

Worker::Worker(Store *vans, Store *workers, Depo *depo) {
    this->depo = depo;
    this->vans = vans;
    this->workers = workers;
    this->workerWorkTime = new Stat("Čas nakládání vozidla");
}


void Worker::Behavior() {
    double unloadTime = 0.45;
    //(*workerWorkTime)(unloadTime);
	Wait(unloadTime);
    Leave(*workers, 1);
    if(workers->Empty()) {
        depo->Activate();
    }
}