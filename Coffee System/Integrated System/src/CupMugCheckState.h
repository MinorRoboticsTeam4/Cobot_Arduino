/*
 * CupMugCheckState.h
 *
 *  Created on: Jan 27, 2016
 *      Author: aclangerak
 */

#ifndef SRC_CUPMUGCHECKSTATE_H_
#define SRC_CUPMUGCHECKSTATE_H_

#include "State.h"
#include "CupDispenser.h"
#include "Consumption.h"
#include "MugOrNot.h"
#include "Turntable.h"

namespace coffee {

class CupMugCheckState: public State {
public:
	CupMugCheckState();
	~CupMugCheckState();

	bool executeState();

	void addOrder(Order* order);

	bool checkCupAmount();
	bool checkMugAmount();

	Order* currentOrder;
};

} /* namespace coffee */

#endif /* SRC_CUPMUGCHECKSTATE_H_ */
