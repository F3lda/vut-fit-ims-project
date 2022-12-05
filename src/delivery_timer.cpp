#include <iostream>
#include "delivery_timer.h"
#include "van.h"

using namespace std;

DeliveryTimer::DeliveryTimer(Delivery *delivery, int *state)
{
    this->delivery = delivery;
    this->state = state;
	Activate(Time + DELIVERY_SHIFT_DURATION);
}

int DeliveryTimer::getState() {
    return status;
}

int DeliveryTimer::deleteVan(Van *van) {
    int i = 0;
    for(Van *vann : this->vans_list) {
        if(vann == van) {
			//delivery->vans_list.erase(this);
			//cout << i << "DELETE!" << this->vans_list.size() << endl;
			this->vans_list.erase(this->vans_list.begin() + i);
			break;
		}
		i++;
    }
    return 0;
}

int DeliveryTimer::addVan(Van *van) {
    vans_list.push_back(van);
    return 0;
}

void DeliveryTimer::Behavior()
{   
    cout << "It's 16:00, end of delivery shift because timer elapsed.\n\n";
    *state = 1;
    status = 1;
    for(Van *van : this->vans_list) {
        
        van->Cancel();        
        //delete van;
        //cout << delivery->vans_list.size() << " It's 16:00, end of delivery shift because timer elapsed.\n\n";
    }
    //delivery->cancelVans();
	//delete delivery;
    Cancel();
}