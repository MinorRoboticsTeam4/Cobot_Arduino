/*
 * CupMugCheckState.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: aclangerak
 */

#include "FillCheckState.h"

namespace coffee {


FillCheckState::FillCheckState() {

}

FillCheckState::~FillCheckState() {
	// TODO Auto-generated destructor stub
}

void FillCheckState::addOrder(Order* order)
{
	currentOrder = order;
}

bool FillCheckState::executeState()
{
	if(!checkCupFill())
	{
		return false;
	}
	else if(!checkMugFill())
	{
		return false;
	}
	else{
		return true;
	}
}

bool FillCheckState::checkCupFill()
{
	if(currentOrder->getAmountUnfilledCups() > 0)
	{
		CoffeeMachine &coffeeMachine = CoffeeMachine::getInstance();
		Turntable &turntable = Turntable::getInstance();
		Consumption* consumption = currentOrder->getNextEmptyCup();
		if(turntable.turnToMachine(consumption->getLocation())) {
			CoffeeMachine::Status response = coffeeMachine.fill(consumption->getCoffeeType());
			if(response != CoffeeMachine::SUCCESS) {
				while(1);
			}
		} else {
			while(1); //Not sure about this, requires more logic to do automated revival
		}

		consumption->setFilled(true);
		return false;
	}
	else
	{
		return true;
	}
}

bool FillCheckState::checkMugFill()
{
	if(currentOrder->getAmountUnfilledMugs() > 0)
	{
		CoffeeMachine &coffeeMachine = CoffeeMachine::getInstance();
		Turntable &turntable = Turntable::getInstance();
		Consumption* consumption = currentOrder->getNextEmptyMug();
		if(turntable.turnToMachine(consumption->getLocation())) {
			CoffeeMachine::Status response = coffeeMachine.fill(consumption->getCoffeeType());
			if(response != CoffeeMachine::SUCCESS) {
				while(1); //No cup or no water
			}
		} else {
			while(1); //Not sure about this, requires more logic to do automated revival
		}

		consumption->setFilled(true);

		return false;
	}
	else
	{
		return true;
	}
}


} /* namespace coffee */
