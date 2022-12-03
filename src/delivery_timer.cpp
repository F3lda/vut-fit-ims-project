#include <iostream>
#include "delivery_timer.h"

using namespace std;

DeliveryTimer::DeliveryTimer(Delivery *delivery)
{
    this->delivery = delivery;
	Activate(Time + DELIVERY_SHIFT_DURATION);
}

void DeliveryTimer::Behavior()
{
    cout << "End of delivery shift because timer elapsed.\n\n";
	delete delivery;
}