
#ifndef DELIVERYTIMER_H
#define DELIVERYTIMER_H

#include <simlib.h>
#include "delivery.h"

class Van;

class DeliveryTimer : public Event
{
public:
	DeliveryTimer(Delivery *delivery, int *state);

	void Behavior() override;

	int getState();

	
	int deleteVan(Van *van);
	int addVan(Van *van);

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

	int status = 0;

	vector<Van*> vans_list;

};


#endif