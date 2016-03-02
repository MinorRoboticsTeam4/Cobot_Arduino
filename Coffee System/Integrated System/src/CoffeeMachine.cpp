/*
 * CoffeeMachine.cpp
 *
 *  Created on: 24 jan. 2016
 *      Author: AC-Langerak
 */

#include "CoffeeMachine.h"

namespace coffee {

/**
 * Constructor, (put setup stuff in here)
 *
 *
 * It sets the pins the output
 */
CoffeeMachine::CoffeeMachine() :
		consumptionsLeft(5) //Set amount of cups/mugs that can be filled
{
	pinMode(coffee_black, OUTPUT);
	pinMode(cafe_au_lait, OUTPUT);
	pinMode(espreschoc, OUTPUT);
	pinMode(cappuchino, OUTPUT);
	pinMode(espresso, OUTPUT);
	pinMode(double_espresso, OUTPUT);
	pinMode(wiener_melange, OUTPUT);
	pinMode(cafe_macchiato, OUTPUT);
	pinMode(hot_chocolate, OUTPUT);
	pinMode(cafe_mocca, OUTPUT);

	dropCatcherServo.attach(12);

	//Reset all pins to low (just to be sure)
	digitalWrite(coffee_black, HIGH);
	digitalWrite(cafe_au_lait, HIGH);
	digitalWrite(espreschoc, HIGH);
	digitalWrite(cappuchino, HIGH);
	digitalWrite(espresso, HIGH);
	digitalWrite(double_espresso, HIGH);
	digitalWrite(wiener_melange, HIGH);
	digitalWrite(cafe_macchiato, HIGH);
	digitalWrite(hot_chocolate, HIGH);
	digitalWrite(cafe_mocca, HIGH);

}

void CoffeeMachine::setConsumptions(int consumptionAmount) {
	consumptionsLeft = consumptionAmount;
}

int CoffeeMachine::getConsumptionsLeft() {
	return consumptionsLeft;
}

/**
 * Check if there is something under the coffee machine. It uses the lightsensor
 * underneath the coffee machine.
 *
 * @return True if there is something placed(cup,mug or hole not aligned properly)
 * 		   False if there is not something detected
 */
bool CoffeeMachine::isSomethingUnderMachine() {
	// ### Copied from OpticSensor 3pc ###
	analogRead(A0);
	delay(5);
	int lightSensorValue = analogRead(A0);
	delay(5);

	//Check if the light is below a certain value
	if (lightSensorValue <= lightThreshold) {
		//Something is detected((cup,mug or hole not aligned properly)
		return true;
	} else {
		//Nothing detected
		return false;
	}
}

/**
 * Fill a cup/mug with the given type
 *
 * @param type type of coffee to set (see the coffee::coffeeTypes)
 *
 * @return Status
 */
CoffeeMachine::Status CoffeeMachine::fill(coffeeTypes type) {
	if (consumptionsLeft < 1) {
		//Not enough water
		return NOT_ENOUGH_WATER;
	}
	//Check if there is a cup or mug under the machine (hopefully)
	else if (isSomethingUnderMachine()) {
		//open drop catcher
		openDropCatcher();
		//Make the Coffee
		makeCoffeeType(type);
		//Subtract one of available consumptions
		this->setConsumptions(this->getConsumptionsLeft() - 1);
		//close drop catcher
		closeDropCatcher();
		//Successful filled
		return SUCCESS;
	} else {
		//No cup/mug:
		return NO_CUP_MUG;
	}
}

bool CoffeeMachine::closeDropCatcher() {
	dropCatcherServo.write(40);     // sets the servo position to start position
	delay(100);                         	// waits for the servo to get there
	return true;
}

bool CoffeeMachine::openDropCatcher() {
	dropCatcherServo.write(40);     // sets the servo position to start position
	delay(100);                          	// waits for the servo to get there
	dropCatcherServo.write(140);      // sets the servo position to end position
	delay(100);                          	// waits for the servo to get there
	return true;
}

void CoffeeMachine::make_COFFEE_BLACK() {
	// ### Copied from CoffeeMachine.ino ###
	digitalWrite(coffee_black, LOW);
	delay(timeSettingCoffee);
	digitalWrite(coffee_black, HIGH);
}
void CoffeeMachine::make_CAFE_AU_LAIT() {
	// ### Copied from CoffeeMachine.ino ###
	digitalWrite(cafe_au_lait, LOW);
	delay(timeSettingCoffee);
	digitalWrite(cafe_au_lait, HIGH);
}
void CoffeeMachine::make_ESPRESCHOC() {
	// ### Copied from CoffeeMachine.ino ###
	digitalWrite(espreschoc, LOW);
	delay(timeSettingCoffee);
	digitalWrite(espreschoc, HIGH);
}
void CoffeeMachine::make_CAPPUCHINO() {
	// ### Copied from CoffeeMachine.ino ###
	digitalWrite(cappuchino, LOW);
	delay(timeSettingCoffee);
	digitalWrite(cappuchino, HIGH);
}
void CoffeeMachine::make_ESPRESSO() {
	// ### Copied from CoffeeMachine.ino ###
	digitalWrite(espresso, LOW);
	delay(timeSettingCoffee);
	digitalWrite(espresso, HIGH);
}
void CoffeeMachine::make_DOUBLE_ESPRESSO() {
	// ### Copied from CoffeeMachine.ino ###
	digitalWrite(double_espresso, LOW);
	delay(timeSettingCoffee);
	digitalWrite(double_espresso, HIGH);
}
void CoffeeMachine::make_WIENER_MELANGE() {
	// ### Copied from CoffeeMachine.ino ###
	digitalWrite(wiener_melange, LOW);
	delay(timeSettingCoffee);
	digitalWrite(wiener_melange, HIGH);
}
void CoffeeMachine::make_CAFE_MAGIATO() {
	// ### Copied from CoffeeMachine.ino ###
	digitalWrite(cafe_macchiato, LOW);
	delay(timeSettingCoffee);
	digitalWrite(cafe_macchiato, HIGH);
}
void CoffeeMachine::make_HOT_CHOCLATE() {
	// ### Copied from CoffeeMachine.ino ###
	digitalWrite(hot_chocolate, LOW);
	delay(timeSettingCoffee);
	digitalWrite(hot_chocolate, HIGH);
}
void CoffeeMachine::make_CAFE_MOCCA() {
	// ### Copied from CoffeeMachine.ino ###
	digitalWrite(cafe_mocca, LOW);
	delay(timeSettingCoffee);
	digitalWrite(cafe_mocca, HIGH);
}

} /* namespace coffee */
