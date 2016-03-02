/*
 * dispenser.cpp
 *
 *  Created on: 24 jan. 2016
 *      Author: AC-Langerak
 */

#include "CupDispenser.h"

namespace coffee
{

	/**
	 * Constructor, (put setup stuff in here)
	 *
	 *
	 * It attaches the servo to the right pin
	 */
	CupDispenser::CupDispenser() : cupsLeft(10) //Set amount of cups
	{
		dispenserServo.attach(10);
	}


	/**
	 * Set a new amount of cups that is left in the system.
	 *
	 * @param cupAmount new amount of cups
	 */
	void CupDispenser::setCupAmount(int cupAmount)
	{
		cupsLeft = cupAmount;
	}

	/**
	 * Get the amount of cups left in the system
	 */
	int CupDispenser::getCupsLeft()
	{
		return cupsLeft;
	}

	CupDispenser::Status CupDispenser::dispenseCup()
	{
		//Check if there are cups left in the system
		if(cupsLeft < 1)
		{
			//No cups left
			return NO_CUPS_LEFT;
		}
		//Check if there is a something under the dispenser already
		if(!isSomethingUnderDispenser())
		{
			//drop the Cup
			if(dropCup())
			{
				//Successful dispensed
				return SUCCESS;
			}
			else
			{
				//Cup not dispensed
				return CUP_NOT_DISPENSED;
			}
		}
		else
		{
			//Something under dispenser (Cup / Mug or the hole is not aligned properly)
			return SPACE_UNDERNEATH_ALREADY_FILLED;

		}
	}

	/**
	 * Check if there is something under the dispenser. It uses the lightsensor
	 * underneath the dispenser.
	 *
	 * @return True if there is something placed(cup,mug or hole not aligned properly)
	 * 		   False if there is not something detected
	 */
	bool CupDispenser::isSomethingUnderDispenser()
	{
	  // ### Copied from OpticSensor 3pc ###
	  analogRead(A2);
	  delay(5);
	  int lightSensorValue = analogRead(A2);
	  delay(5);

	  //Check if the light is below a certain value
	  if(lightSensorValue <= lightThreshold)
	  {
		  //Something is detected((cup,mug or hole not aligned properly)
		  return true;
	  }
	  else
	  {
		  //Nothing detected
		  return false;
	  }
	}

	/**
	 * Control the servo from the dispenser to drop a cup.
	 *
	 * @return True if it successfully has dropped a cup, False otherwise
	 */
	bool CupDispenser::dropCup()
	{
	   dispenserServo.write(45);  // Turn Servo Left to 45 degrees
	   delay(1000);          	  // Wait 1 second
	   dispenserServo.write(0);   // Turn Servo Left to 0 degrees
	   delay(1000);               // Wait 1 second
	   dispenserServo.write(90);  // Turn Servo back to center position (90 degrees)
	   delay(1000);               // Wait 1 second
	   dispenserServo.write(135); // Turn Servo Right to 135 degrees
	   delay(1000);               // Wait 1 second
	   dispenserServo.write(180); // Turn Servo Right to 180 degrees
	   delay(1000);               // Wait 1 second
	   dispenserServo.write(90);  // Turn Servo back to center position (90 degrees)
	   delay(1000);               // Wait 1 second

		//Check if the cup is dispensed
		if(isSomethingUnderDispenser())
		{
			//Subtract 1 from the amount of cups left
			setCupAmount(getCupsLeft() -1);
			//Cup is successfully dispensed
			return true;
		}
		else
		{
			//Cup is not dispensed
			return false;
		}
	}


}


