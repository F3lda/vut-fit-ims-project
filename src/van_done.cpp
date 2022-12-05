#include "van_done.h"



using namespace std;

VanDone::VanDone(
	Store *vans_working,
    int shiftCanceled,
    Stat *vanReturnRideTime
) :
	vans_working(vans_working),
	shiftCanceled(shiftCanceled),
    vanReturnRideTime(vanReturnRideTime)
{
}

void VanDone::Behavior()
{
    // návrat ze z normální nebo zrušené směny
    if(shiftCanceled == 0) {
        double rideTime = Uniform(10, 15);
		(*vanReturnRideTime)(rideTime);
		Wait(rideTime);
    } else {
        double rideTime = Uniform(15, 45);
		(*vanReturnRideTime)(rideTime);
		Wait(rideTime);
    }
    cout << "Van on way home!"  << endl;
}

VanDone::~VanDone() {
	cout << "VAN AT DEPO! At time: " << Time  << endl;
	Leave(*vans_working, 1);
}