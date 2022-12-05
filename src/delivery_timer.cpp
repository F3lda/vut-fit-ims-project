
#include "delivery_timer.h"

#include "van_working.h"



using namespace std;

DeliveryTimer::DeliveryTimer(int *shiftState)
{
    this->shiftState = shiftState;
	Activate(Time + DELIVERY_SHIFT_DURATION);
}

int DeliveryTimer::getShiftState() {
    return *shiftState;
}

int DeliveryTimer::deleteVan(void *van) {
    int i = 0;
    for(void *vann : this->vansList) {
        if(vann == van) {
			this->vansList.erase(this->vansList.begin() + i);
			//break;
		}
		i++;
    }
    return 0;
}

int DeliveryTimer::addVan(void *van) {
    vansList.push_back(van);
    return 0;
}

void DeliveryTimer::Behavior()
{   
    cout << "It's 16:00, end of delivery shift because timer elapsed.\n\n";
    
    *shiftState = 1;
    for(void *van : this->vansList) {
        ((VanWorking*)van)->Cancel();
    }
    Cancel();
}
