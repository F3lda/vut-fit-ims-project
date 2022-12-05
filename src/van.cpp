#include "van.h"

#include "delivery_timer.h"

using namespace std;

Van::Van(
	Store *vans_return, 
    Stat *vanBoxRideTime, 
    Stat *vanNonBoxRideTime, 
    Stat *vanLoadTime,
	int *state,
	void *delivery_timer
) :
	vans_return(vans_return),
	vanBoxRideTime(vanBoxRideTime),
	vanNonBoxRideTime(vanNonBoxRideTime),
	vanLoadTime(vanLoadTime),
	state(state),
	delivery_timer(delivery_timer)
{
	((DeliveryTimer *)delivery_timer)->addVan(this);
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
}

Van::~Van() {
	cout << "STATE: " << *state << endl;
	if (*state == 0) {
		((DeliveryTimer *)delivery_timer)->deleteVan(this);
	}

	if (*state == 1) {
		cout << "VAN GO HOME!" << Time  << endl;
		double rideTime = Uniform(15, 45);
		(*vanBoxRideTime)(rideTime);
		Wait(rideTime);
	} else {
		cout << "VAN DONE! At time: " << Time  << endl;
		double rideTime = Uniform(10, 15);
		(*vanBoxRideTime)(rideTime);
		Wait(rideTime);
	}
	cout << "VAN AT DEPO! At time: " << Time  << endl;

	Leave(*vans_return, 1);
}