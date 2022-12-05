#include "worker.h"

using namespace std;

Worker::Worker(Store *vehicles, Store *workers, long unsigned int *packages, int unloading) {
    this->vehicles = vehicles;
    this->workers = workers;
    this->workerWorkTime = new Stat("Čas nakládání vozidla");
    this->packages = packages;
    this->unloading = unloading;
}


void Worker::Behavior() {
    double unloadTime = 0.45;
    double loadTime = 0.30;
    //(*workerWorkTime)(unloadTime);
	

    if (unloading == 1) {
        Wait(unloadTime);

        (*packages)++;

        // právě je jedna dodávka úplně vyložena
        if ((*packages) == 157) { //packagesPerVan
            (*packages) = 0;
            Leave(*vehicles, 1);

            cout << "Van fully unloaded" << endl;
        }
    } else {
        Wait(loadTime);

        (*packages)++;

        // právě je jedna dodávka úplně vyložena
        if ((*packages) == (6*157)) { //packagesPerTruck
            (*packages) = 0;
            Leave(*vehicles, 1);

            cout << "Truck fully loaded" << endl;
        }
    }


    Leave(*workers, 1);
}
