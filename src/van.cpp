#include "van.h"
using namespace std;

Van::Van(
	Store *vans_return, 
    Stat *vanBoxRideTime, 
    Stat *vanNonBoxRideTime, 
    Stat *vanLoadTime,
	int *state
	//vector<Van*> *vans_list
) :
	vans_return(vans_return),
	vanBoxRideTime(vanBoxRideTime),
	vanNonBoxRideTime(vanNonBoxRideTime),
	vanLoadTime(vanLoadTime),
	state(state)
	//vans_list(vans_list)
{
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
	/*int i = 0;
	for(Van *van : delivery->vans_list) {
        if(van == this) {
			//delivery->vans_list.erase(this);
			delivery->vans_list.erase(delivery->vans_list.begin() + i);
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