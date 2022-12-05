
#ifndef DELIVERYTIMER_H
#define DELIVERYTIMER_H

#include <iostream>
#include <simlib.h>
#include <vector>



class DeliveryTimer : public Event
{
public:
	DeliveryTimer(int *state);

	void Behavior() override;

	int getShiftState();
	int deleteVan(void *van);
	int addVan(void *van);

private:
	/**
	 * Směna rozvozu (8 hodin).
	 */
	const double DELIVERY_SHIFT_DURATION = 8.0 * 60.0;

	/**
	 * Work shift process which will be killed
	 * after work shift duration.
	 */

	int *shiftState;

	std::vector<void*> vansList;

};

#endif
