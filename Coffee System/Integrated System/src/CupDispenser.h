/*
 * dispenser.h
 *
 *  Created on: 24 jan. 2016
 *      Author: AC-Langerak
 */

#ifndef SRC_CUPDISPENSER_H_
#define SRC_CUPDISPENSER_H_


#include "Arduino.h"
#include "Servo.h"

namespace coffee
{

	/**
	 * This class is responsible for controlling the Dispenser
	 */
	class CupDispenser
	{
	public:

		enum Status{
			SUCCESS = 0,
			NO_CUPS_LEFT = 1,
			CUP_NOT_DISPENSED = 2,
			SPACE_UNDERNEATH_ALREADY_FILLED = 3
		};

		static CupDispenser& getInstance() {
			static CupDispenser instance;
			return instance;
		}


		Status dispenseCup();
		void setCupAmount(int cupAmount);
		int getCupsLeft();


	private:
		CupDispenser();
		CupDispenser(CupDispenser const&); //Dont implement
		void operator=(CupDispenser const&); //Dont implement

		bool isSomethingUnderDispenser();
		bool dropCup();

		Servo dispenserServo;

		static const int lightThreshold = 900;

		//TODO Store this variable in EEPROM ?
		int cupsLeft;

	};


}


#endif /* SRC_CUPDISPENSER_H_ */
