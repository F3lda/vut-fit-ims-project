#ifndef DEPOTIMER_H
#define DEPOTIMER_H


#include <simlib.h>
#include "depo_timer.h"
#include "depo.h"


class DepoTimer : public Event
{
public:
	DepoTimer(Depo *depo);

	void Behavior() override;

private:
	/**
	 * Směna rozvozu (16 hodin).
	 */
	const double DEPO_SHIFT_DURATION = 8.0 * 60.0;

	/**
	 * pracovní doba na depu od 16 do 8, bude zabit pokud uběhne DEPO_SHIFT_DURATION
	 */
	Depo *depo;
};


#endif