
#ifndef DELIVERYTIMER_H
#define DELIVERYTIMER_H

#include <simlib.h>
#include "delivery.h"

class DeliveryTimer : public Event
{
public:
	DeliveryTimer(Delivery *delivery, int *state);

	void Behavior() override;

private:
	/**
	 * Směna rozvozu (8 hodin).
	 */
	const double DELIVERY_SHIFT_DURATION = 8.0 * 60.0;

	/**
	 * Work shift process which will be killed
	 * after work shift duration.
	 */
	Delivery *delivery;

	int *state;

};


#endif