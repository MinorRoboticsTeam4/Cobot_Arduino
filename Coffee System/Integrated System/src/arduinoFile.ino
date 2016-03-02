/*
 * arduinoFile.cpp
 *
 *  Created on: Jan 28, 2016
 *      Author: aclangerak
 */

#include "ros.h"

#include <cobot_navigation/ArduinoOrder.h>
#include <cobot_navigation/ArduinoOrderStatus.h>

#include "Arduino.h"

#include "Order.h"
#include "Consumption.h"

#include "CoffeeMachine.h"
#include "CupDispenser.h"

#include "State.h"
#include "CupMugCheckState.h"
#include "FillCheckState.h"
#include "RetrieveCheckState.h"
#include "NullCheckState.h"

ros::NodeHandle nh;

coffee::NullCheckState nullCheckState;
coffee::CupMugCheckState cupMugCheckState;
coffee::FillCheckState fillCheckState;
coffee::RetrieveCheckState retrieveCheckState;

coffee::Order order;

int stateNumber = 0;
const int numOfStates = 4;

coffee::State *ptrStates[numOfStates] = { &nullCheckState, &cupMugCheckState,
		&fillCheckState, &retrieveCheckState };

cobot_navigation::ArduinoOrderStatus arduinoOrderStatusMsg;

coffee::coffeeTypes convertToCoffeeType(int type) {
	coffee::coffeeTypes convertType = coffee::Unkown_type;
	switch (type) {
	case 0:
		convertType = coffee::coffee_black;
		break;
	case 1:
		convertType = coffee::cappuchino;
		break;
	case 2:
		convertType = coffee::espresso;
		break;
	case 3:
		convertType = coffee::cafe_au_lait;
		break;
	case 4:
		convertType = coffee::wiener_melange;
		break;
	case 5:
		convertType = coffee::double_espresso;
		break;
	case 6:
		convertType = coffee::cafe_mocca;
		break;
	case 7:
		convertType = coffee::cafe_macchiato;
		break;
	case 8:
		convertType = coffee::espreschoc;
		break;
	case 9:
		convertType = coffee::hot_chocolate;
		break;
	}
	return convertType;
}

void clearOrder(){
	order.removeAllConsumptions();
}

void arduinoOrderCb(const cobot_navigation::ArduinoOrder& arduinoOrder) {

	for (int i = 0; i < arduinoOrder.orderAmount; ++i) {
		bool isMug = false;
		int orderNumber = arduinoOrder.coffeeTypes[i];
		if (arduinoOrder.isMug[i] == true) {
			order.addConsumption(coffee::mug,
					convertToCoffeeType(orderNumber));
		} else {
			order.addConsumption(coffee::cup,
					convertToCoffeeType(orderNumber));
		}

	}

	coffee::CupDispenser &dispenser = coffee::CupDispenser::getInstance();

	if(dispenser.getCupsLeft() >= order.getTotalAmountOfCups()){
		order.setStatus(coffee::Order::NOT_DONE);
	}else{
		clearOrder();
		//TODO Error message indicating not enough cups
	}

}

ros::Publisher pub("arduino_send",&arduinoOrderStatusMsg);
ros::Subscriber<cobot_navigation::ArduinoOrder> sub("arduino_receive",&arduinoOrderCb);


void setup() {

	order.setStatus(coffee::Order::COMPLETED);
	ptrStates[0]->addOrder(&order);
	ptrStates[1]->addOrder(&order);
	ptrStates[2]->addOrder(&order);
	ptrStates[3]->addOrder(&order);

	nh.initNode();
	nh.subscribe(sub);
	nh.advertise(pub);

}

void loop() {

	nh.spinOnce();
	delay(1);

	if (ptrStates[stateNumber]->executeState()) {
		//All states are completed
		if (stateNumber == (numOfStates - 1)) {
			stateNumber = 0;
			clearOrder();
			arduinoOrderStatusMsg.isCompleted = true;
			pub.publish(&arduinoOrderStatusMsg);
		} else {
			stateNumber++;
		}
	}

}


