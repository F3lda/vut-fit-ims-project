#include "worker.h"

using namespace std;

Worker::Worker(Store *vans, Store *workers) {
    this->vans = vans;
    this->workers = workers;
}


void Worker::Behavior() {
	Wait(0.45);
    Leave(*workers, 1);
}

Worker::~Worker(){
    delete vans;
    delete workers;
}