/*
 * Consumption.cpp
 *
 *  Created on: 24 jan. 2016
 *      Author: AC-Langerak
 */

#include "Consumption.h"

namespace coffee {

Consumption::Consumption() : location(-1), placed(false), filled(false){}

Consumption::~Consumption() {}

coffee::coffeeTypes Consumption::getCoffeeType()
{
	return type;
}

coffee::containerType Consumption::getContainerType()
{
	return container;
}

void Consumption::setCoffeeType(coffee::coffeeTypes flavour)
{
	type = flavour;
}

void Consumption::setContainerType(containerType holdingContainer)
{
	container = holdingContainer;
}

bool Consumption::isFilled()
{
	return filled;
}

void Consumption::setFilled(bool isFill)
{
	filled = isFill;
}

bool Consumption::isPlaced()
{
	return placed;
}

void Consumption::setPlaced(bool isPlaced)
{
	placed = isPlaced;
}

int Consumption::getLocation()
{
	return location;
}

void Consumption::setLocation(int setLocation)
{
	location = setLocation;
	placed = true;
}

}
