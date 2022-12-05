
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
	int *shiftState;

	std::vector<void*> vansList;
};

#endif
