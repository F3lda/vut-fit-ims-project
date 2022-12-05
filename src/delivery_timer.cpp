#include <iostream>
#include "delivery_timer.h"

using namespace std;

DeliveryTimer::DeliveryTimer(Delivery *delivery, int *state)
{
    this->delivery = delivery;
    this->state = state;
	Activate(Time + DELIVERY_SHIFT_DURATION);
}

void DeliveryTimer::Behavior()
{   
    cout << "It's 16:00, end of delivery shift because timer elapsed.\n\n";
    *state = 1;
    /*for(Van *van : delivery->vans_list) {
        van->Cancel();        
    }*/
    //delivery->cancelVans();
	//delete delivery;
    //Cancel();
}