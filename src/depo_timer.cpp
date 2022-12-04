#include <iostream>
#include "depo_timer.h"

using namespace std;

DepoTimer::DepoTimer(Depo *depo)
{
    this->depo = depo;
	Activate(Time + DEPO_SHIFT_DURATION);
}

void DepoTimer::Behavior()
{
    cout << "Je 8 hodin ráno. Takže se nestihla práce v Depu\n\n";
	delete depo;
}