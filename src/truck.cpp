#include "truck.h"

using namespace std;

Truck::Truck(Store *trucks) {
    this->trucks = trucks;
    TRUCK_TRAVEL_BETWEEN_DEPOS_TIME = new Stat("Cesta kamionů přes další depa");
    TRUCK_WORK_BETWEEN_DEPOS_TIME = new Stat("Překlad na depech na trase");
    TRUCK_WORK_AT_LAST_DEPO_TIME = new Stat("Vykládání na posledním Depu");
}

void Truck::Behavior() {
    double truckTravelTime = Uniform(45, 480);
    (*TRUCK_TRAVEL_BETWEEN_DEPOS_TIME)(truckTravelTime);
    Wait(truckTravelTime);
    double truckWorkBetween = Uniform(0, 562);
    (*TRUCK_WORK_BETWEEN_DEPOS_TIME)(truckWorkBetween);
    Wait(truckWorkBetween);
    double truckWorkLast = Uniform(107, 117);
    (*TRUCK_WORK_AT_LAST_DEPO_TIME)(truckWorkLast);
    Wait(truckWorkLast);

    Leave(*trucks, 1);
}