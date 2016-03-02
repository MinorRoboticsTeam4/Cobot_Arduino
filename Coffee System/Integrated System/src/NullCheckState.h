/*
 * NullCheckState.h
 *
 *  Created on: Jan 27, 2016
 *      Author: Emil Flach
 */

#ifndef SRC_NULLCHECKSTATE_H_
#define SRC_NULLCHECKSTATE_H_

#include "State.h"
#include "Order.h"

namespace coffee {

class NullCheckState: public State {
public:
	NullCheckState();
	~NullCheckState();

	bool executeState();

	void addOrder(Order* order);

	bool checkOrder();

	Order* currentOrder;
};

} /* namespace coffee */

#endif /* SRC_NULLCHECKSTATE_H_ */
