/*
 * RetrieveCheckState.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: Emil Flach
 */

#include "RetrieveCheckState.h"

namespace coffee {

RetrieveCheckState::RetrieveCheckState() {}
RetrieveCheckState::~RetrieveCheckState() {}

void RetrieveCheckState::addOrder(Order* order)
{
	currentOrder = order;
}

bool RetrieveCheckState::executeState()
{
	if(!checkCupRetrieve())
	{
		return false;
	}
	else if(!checkMugRetrieve())
	{
		return false;
	}
	else{
		currentOrder->setStatus(Order::COMPLETED);
		return true;
	}
}

bool RetrieveCheckState::checkCupRetrieve()
{
	if(currentOrder->getAmountFilledCups() != currentOrder->getTotalAmountOfCups())
	{
		Turntable &turntable = Turntable::getInstance();
		Consumption* consumption = currentOrder->getNextFilledCup();
		if(turntable.turnToTake(consumption->getLocation())) {
			MugOrNot &sensor = MugOrNot::getInstance();

			bool response = sensor.hasMug();
			while(!response){};
		} else {
			while(1); //Not sure about this, requires more logic to do automated revival
		}

		return false;
	}
	else
	{
		return true;
	}
}

bool RetrieveCheckState::checkMugRetrieve()
{
	if(currentOrder->getAmountFilledMugs() != currentOrder->getTotalAmountOfMugs())
	{
		Turntable &turntable = Turntable::getInstance();
		Consumption* consumption = currentOrder->getNextFilledMug();
		if(turntable.turnToTake(consumption->getLocation())) {
			MugOrNot &sensor = MugOrNot::getInstance();

			bool response = sensor.hasMug();
			while(!response){};
		} else {
			while(1); //Not sure about this, requires more logic to do automated revival
		}
		return false;
	}
	else
	{
		return true;
	}
}


} /* namespace coffee */
