#include "van.h"

using namespace std;

Van::Van(
	Store *vans, 
    Stat *vanBoxRideTime, 
    Stat *vanNonBoxRideTime, 
    Stat *vanLoadTime
) :
	vans(vans),
	vanBoxRideTime(vanBoxRideTime),
	vanNonBoxRideTime(vanNonBoxRideTime),
	vanLoadTime(vanLoadTime)
{
}


void Van::Behavior()
{
	// Box nebo ne
	if( Random() < BOX_PROBABILITY ) {
		double rideTime = Uniform(392, 477);
		(*vanNonBoxRideTime)(rideTime);
		Wait(rideTime);
	} else {
		double rideTime = Uniform(389, 474);
		(*vanBoxRideTime)(rideTime);
		Wait(rideTime);
	}
	Leave(*vans, 1);
}