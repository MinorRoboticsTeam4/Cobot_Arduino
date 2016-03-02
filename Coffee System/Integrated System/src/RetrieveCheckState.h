/*
 * RetrieveCheckState.h
 *
 *  Created on: Jan 27, 2016
 *      Author: Emil Flach
 */

#ifndef SRC_RETRIEVECHECKSTATE_H_
#define SRC_RETRIEVECHECKSTATE_H_

#include "State.h"
#include "Consumption.h"
#include "Turntable.h"
#include "MugOrNot.h"

namespace coffee {

class RetrieveCheckState: public State {
public:
	RetrieveCheckState();
	~RetrieveCheckState();

	bool executeState();

	void addOrder(Order* order);

	bool checkCupRetrieve();
	bool checkMugRetrieve();

	Order* currentOrder;
};

} /* namespace coffee */

#endif /* SRC_RETRIEVECHECKSTATE_H_ */
