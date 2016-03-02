/*
 * CoffeeMachine.h
 *
 *  Created on: 24 jan. 2016
 *      Author: AC-Langerak
 */

#ifndef SRC_COFFEEMACHINE_H_
#define SRC_COFFEEMACHINE_H_

#include "Arduino.h"
#include "Servo.h"

namespace coffee {

/**
 * All Coffee types, the value is the pin that is used for the relais
 */
enum coffeeTypes {
	coffee_black = 44,
	cappuchino = 47,
	espresso = 49,
	cafe_au_lait = 43,
	wiener_melange = 41,
	double_espresso = 46,
	cafe_mocca = 42,
	cafe_macchiato = 48,
	espreschoc = 45,
	hot_chocolate = 39,
	Unkown_type = -1
};


/**
 * This class is responsible for controlling the Coffee Machine
 */
class CoffeeMachine {

public:

	enum Status{
		SUCCESS = 0,
		NOT_ENOUGH_WATER = 1,
		NO_CUP_MUG = 2
	};



	//Call this method now instead of a constructor
	static CoffeeMachine& getInstance() {
		static CoffeeMachine instance;
		return instance;
	}

	void setConsumptions(int consumptionAmount);
	int getConsumptionsLeft();

	Status fill(coffeeTypes type);

private:
	CoffeeMachine();
	CoffeeMachine(CoffeeMachine const&); //Dont implement
	void operator=(CoffeeMachine const&); //Dont implement

	bool isSomethingUnderMachine();

	bool closeDropCatcher();
	bool openDropCatcher();

	void make_COFFEE_BLACK();
	void make_CAFE_AU_LAIT();
	void make_ESPRESCHOC();
	void make_CAPPUCHINO();
	void make_ESPRESSO();
	void make_DOUBLE_ESPRESSO();
	void make_WIENER_MELANGE();
	void make_CAFE_MAGIATO();
	void make_HOT_CHOCLATE();
	void make_CAFE_MOCCA();

	/**
	 * Call the make coffee based on the type given.
	 *
	 * @param types type of coffee to make
	 */
	void makeCoffeeType(coffeeTypes types) {
		switch (types) {
		case coffee_black:
			make_COFFEE_BLACK();
			break;
		case cafe_au_lait:
			make_CAFE_AU_LAIT();
			break;
		case espreschoc:
			make_ESPRESCHOC();
			break;
		case cappuchino:
			make_CAPPUCHINO();
			break;
		case espresso:
			make_ESPRESSO();
			break;
		case double_espresso:
			make_DOUBLE_ESPRESSO();
			break;
		case wiener_melange:
			make_WIENER_MELANGE();
			break;
		case cafe_macchiato:
			make_CAFE_MAGIATO();
			break;
		case hot_chocolate:
			make_HOT_CHOCLATE();
			break;
		case cafe_mocca:
			make_CAFE_MOCCA();
			break;
		case Unkown_type:
			break;
		}
	}
	Servo dropCatcherServo;

	static const int lightThreshold = 750;
	static const int timeSettingCoffee = 500;
	int consumptionsLeft;

};

}

#endif /* SRC_COFFEEMACHINE_H_ */
