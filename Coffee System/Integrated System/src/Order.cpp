/*
 * Order.cpp
 *
 *  Created on: 24 jan. 2016
 *      Author: AC-Langerak
 */

#include "Order.h"

namespace coffee {

Order::Order() :
		currentStatus(NOT_DONE),unfilledCups(0), unfilledMugs(0), unplacedCups(0), unplacedMugs(0), filledMugs(0), filledCups(0), amountOfCups(0), amountOfMugs(0) {

}

Order::~Order() {
}

void Order::setStatus(Status status){
	currentStatus = status;
}

Order::Status Order::getStatus(){
	return currentStatus;
}

void Order::addConsumption(coffee::containerType container,
		coffee::coffeeTypes type) {
	Consumption consumption;

	if (container == coffee::cup) {
		unplacedCups++;
		amountOfCups++;
		unfilledCups++;
		consumption.setContainerType(coffee::cup);
	} else if (container == coffee::mug) {
		unplacedMugs++;
		amountOfMugs++;
		unfilledMugs++;
		consumption.setContainerType(coffee::mug);
	}

	consumption.setCoffeeType(type);
	orderList.push_back(consumption);
}

void Order::removeAllConsumptions(){
	orderList.clear();

	unplacedCups = 0;
	amountOfCups = 0;
	unfilledCups = 0;

	unplacedMugs = 0;
	amountOfMugs = 0;
	unfilledMugs = 0;
}

Consumption* Order::getNextEmptyCup() {
	for (SimpleList<Consumption>::iterator itr = orderList.begin();
			itr != orderList.end();) {
		if ((itr->getContainerType() == coffee::cup) && !(itr->isFilled()) && (itr->isPlaced())) {
			unfilledCups--;
			return itr;
		}
		++itr;
	}

	return NULL;
}

Consumption* Order::getNextEmptyMug() {
	for (SimpleList<Consumption>::iterator itr = orderList.begin();
			itr != orderList.end();) {
		if ((itr->getContainerType() == coffee::mug) && !(itr->isFilled()) && (itr->isPlaced())) {
			unfilledMugs--;
			return itr;
		}
		++itr;
	}

	return NULL;
}

Consumption* Order::getNextUnplacedCup() {
	for (SimpleList<Consumption>::iterator itr = orderList.begin();
			itr != orderList.end();) {
		if ((itr->getContainerType() == coffee::cup) && !(itr->isPlaced())) {
			unplacedCups--;
			return itr;
		}
		++itr;
	}

	return NULL;
}

Consumption* Order::getNextUnplacedMug() {
	for (SimpleList<Consumption>::iterator itr = orderList.begin();
			itr != orderList.end();) {
		if ((itr->getContainerType() == coffee::mug) && !(itr->isPlaced())) {
			unplacedMugs--;
			return itr;
		}
		++itr;
	}

	return NULL;
}

Consumption* Order::getNextFilledCup() {
	for (SimpleList<Consumption>::iterator itr = orderList.begin();
			itr != orderList.end();) {
		if ((itr->getContainerType() == coffee::cup) && (itr->isFilled())) {
			filledCups++;
			return itr;
		}
		++itr;
	}

	return NULL;
}

Consumption* Order::getNextFilledMug() {
	for (SimpleList<Consumption>::iterator itr = orderList.begin();
			itr != orderList.end();) {
		if ((itr->getContainerType() == coffee::mug) && (itr->isFilled())) {
			filledMugs++;
			return itr;
		}
		++itr;
	}

	return NULL;
}

int Order::getAmountUnfilledCups() {
	return unfilledCups;
}
int Order::getAmountUnfilledMugs() {
	return unfilledMugs;
}
int Order::getAmountUnplacedCups() {
	return unplacedCups;
}
int Order::getAmountUnplacedMugs() {
	return unplacedMugs;
}

int Order::getAmountFilledCups() {
	return filledCups;
}
int Order::getAmountFilledMugs() {
	return filledMugs;
}

int Order::getTotalAmountOfCups() {
	return amountOfCups;
}

int Order::getTotalAmountOfMugs() {
	return amountOfMugs;
}

}
