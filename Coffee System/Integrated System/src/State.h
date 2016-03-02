/*
 * State.h
 *
 *  Created on: Jan 27, 2016
 *      Author: aclangerak
 */

#ifndef SRC_STATE_H_
#define SRC_STATE_H_

#include "Order.h"

namespace coffee {

class State {
public:
	//virtual State(Order order);
	virtual ~State();

	virtual bool executeState()=0;
	virtual void addOrder(Order* order)=0;


};

} /* namespace coffee */

#endif /* SRC_STATE_H_ */
