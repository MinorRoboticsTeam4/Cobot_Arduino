/*
 * NullCheckState.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: Emil Flach
 */

#include "NullCheckState.h"

namespace coffee {

NullCheckState::NullCheckState() {}
NullCheckState::~NullCheckState() {}

void NullCheckState::addOrder(Order* order)
{
	currentOrder = order;
}

bool NullCheckState::executeState()
{
	if(!checkOrder())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool NullCheckState::checkOrder()
{
	if(currentOrder->getStatus() == Order::COMPLETED)
	{
		return false;
	}
	else
	{
		return true;
	}
}


} /* namespace coffee */
