#include "van.h"


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
	/*
	* TODO: nějaké výpočty. Zeptat se Karla
	*/
	Leave(*vans, 1);
}