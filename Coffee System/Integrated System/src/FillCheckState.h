/*
 * FillCheckState.h
 *
 *  Created on: Jan 27, 2016
 *      Author: Emil Flach
 */

#ifndef SRC_FILLCHECKSTATE_H_
#define SRC_FILLCHECKSTATE_H_

#include "State.h"
#include "Consumption.h"
#include "Turntable.h"

namespace coffee {

class FillCheckState: public State {
public:
	FillCheckState();
	~FillCheckState();

	bool executeState();

	void addOrder(Order* order);

	bool checkCupFill();
	bool checkMugFill();

	Order* currentOrder;
};

} /* namespace coffee */

#endif /* SRC_FILLCHECKSTATE_H_ */
