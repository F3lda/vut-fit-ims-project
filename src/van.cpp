#include "van.h"
#include "delivery.h"
#include "delivery_timer.h"
using namespace std;

Van::Van(
	Store *vans_return, 
    Stat *vanBoxRideTime, 
    Stat *vanNonBoxRideTime, 
    Stat *vanLoadTime,
	int *state,
	Delivery *delivery,
	DeliveryTimer *delivery_timer
	//vector<Van*> *vans_list
) :
	vans_return(vans_return),
	vanBoxRideTime(vanBoxRideTime),
	vanNonBoxRideTime(vanNonBoxRideTime),
	vanLoadTime(vanLoadTime),
	state(state),
	delivery(delivery),
	delivery_timer(delivery_timer)
	//vans_list(vans_list)
{
	delivery_timer->addVan(this);
}


void Van::Behavior()
{
	// Box nebo ne
	if( Random() < BOX_PROBABILITY ) {
		double rideTime = Uniform(452, 537);
		(*vanNonBoxRideTime)(rideTime);
		Wait(rideTime);
	} else {
		double rideTime = Uniform(447, 532);
		(*vanBoxRideTime)(rideTime);
		Wait(rideTime);
	}
	//while (delivery_timer->getState() == 1) {
	//	Wait(1000);
	//}
}

Van::~Van() {
	if (*state == 0) {
		delivery_timer->deleteVan(this);

		//cout << "STATE: " << delivery_timer->getState()  << endl;
	}
	/*int i = 0;
	for(Van *van : delivery->vans_list) {
        if(van == this) {
			//delivery->vans_list.erase(this);
			cout << i << "DELETE!" << delivery->vans_list.size() << endl;
			//delivery->vans_list.erase(delivery->vans_list.begin() + i);
			break;
		}
		i++;
    }*/
	Leave(*vans_return, 1);
	if (*state == 1) {
		cout << "VAN GO HOME!" << Time  << endl;
	} else {
		cout << "VAN DONE! At time: " << Time  << endl;
		
	}
	
}