/*
 * CupMugCheckState.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: aclangerak
 */

#include "CupMugCheckState.h"

namespace coffee {


CupMugCheckState::CupMugCheckState() {

}

CupMugCheckState::~CupMugCheckState() {
	// TODO Auto-generated destructor stub
}

void CupMugCheckState::addOrder(Order* order)
{
	currentOrder = order;
}

bool CupMugCheckState::executeState()
{
	if(!checkCupAmount())
	{
		return false;
	}
	else if(!checkMugAmount())
	{
		return false;
	}
	else{
		return true;
	}
}

bool CupMugCheckState::checkCupAmount()
{

	CupDispenser &cupDispenser = CupDispenser::getInstance();
	Turntable &turntable = Turntable::getInstance();

	if(currentOrder->getAmountUnplacedCups() > 0)
	{
		if (cupDispenser.getCupsLeft() <= 0) {
			return false;
		}

		Consumption* consumption = currentOrder->getNextUnplacedCup();
		consumption->setLocation(turntable.getEmptyCupLocation());

		if(turntable.turnToDispenser(consumption->getLocation())) {
			CupDispenser::Status response = cupDispenser.dispenseCup();
			if(response != CupDispenser::SUCCESS) {
				while(1); //Not sure about this, requires more logic to do automated revival
			}
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

bool CupMugCheckState::checkMugAmount()
{
	if(currentOrder->getAmountUnplacedMugs() > 0)
	{
		Turntable &turntable = Turntable::getInstance();
		Consumption* consumption = currentOrder->getNextUnplacedMug();
		consumption->setLocation(turntable.getEmptyMugLocation());
		if(turntable.turnToDispenser(consumption->getLocation())) {
			MugOrNot &sensor = MugOrNot::getInstance();
			bool response = sensor.hasMug();
			while(!response);
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
