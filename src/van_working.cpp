#include "van_working.h"

#include "delivery_timer.h"
#include "van_done.h"



using namespace std;

VanWorking::VanWorking(
	Store *vans_working,
	int *state,
	void *delivery_timer,
    Stat *vanBoxRideTime,
    Stat *vanNonBoxRideTime,
    Stat *vanCanceledRemainingTime,
    Stat *vanReturnRideTime
) :
	vans_working(vans_working),
	state(state),
	delivery_timer(delivery_timer),
	vanBoxRideTime(vanBoxRideTime),
	vanNonBoxRideTime(vanNonBoxRideTime),
	vanCanceledRemainingTime(vanCanceledRemainingTime),
	vanReturnRideTime(vanReturnRideTime)
{
	((DeliveryTimer *)delivery_timer)->addVan(this);
}


void VanWorking::Behavior()
{
	// Box nebo ne
	if( Random() < BOX_PROBABILITY ) {
		rideTime = Uniform(452, 537);
		(*vanNonBoxRideTime)(rideTime);
		Wait(rideTime);
	} else {
		rideTime = Uniform(447, 532);
		(*vanBoxRideTime)(rideTime);
		Wait(rideTime);
	}
}

VanWorking::~VanWorking() {
	cout << "STATE: " << *state << endl;
	if (*state == 0) {
		((DeliveryTimer *)delivery_timer)->deleteVan(this);
	}

	if (*state == 1) {
		(*vanCanceledRemainingTime)(rideTime-Time);

		cout << "VAN GO HOME! At time: " << Time  << endl;
		(new VanDone(vans_working, 1, vanReturnRideTime))->Activate();
	} else {
		cout << "VAN DONE! At time: " << Time  << endl;
		(new VanDone(vans_working, 0, vanReturnRideTime))->Activate();
	}
}
