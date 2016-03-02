/*
 * Turntable.cpp
 *
 *  Created on: 24 jan. 2016
 *      Author: AC-Langerak
 */

#include "Turntable.h"
namespace coffee {

	Turntable::Turntable() : stepper(1, XSTEP, XDIR) {
	    pinMode(ENABLEPIN, OUTPUT);
	    pinMode(RESETPIN, OUTPUT);
	    pinMode(MS_TURNTABLE_PIN, INPUT);
	    digitalWrite(ENABLEPIN,HIGH);                         // LOW: motor active | HIGH: free to move
	    digitalWrite(RESETPIN,LOW);                           // HIGH: motor active | LOW: free to move

	    stepper.setMaxSpeed(MAXSPEED);                        // set max speed of stepper
	    stepper.setAcceleration(ACCEL);                       // set accelaration of stepper
	    stepper.setCurrentPosition(0);                        // set current postition
	}


	bool Turntable::calibrate(){

	  stepper.moveTo(STEPS*2);
	  digitalWrite(RESETPIN,HIGH);

	  while(stepper.distanceToGo() && MS_TURNTABLE == 1 && MS_DISP == 1){      	// run stepper to his position and stop if MS (microswitch
		   digitalWrite(ENABLEPIN,LOW);
		   digitalWrite(RESETPIN,HIGH);
		   stepper.run();
		   MS_TURNTABLE = digitalRead(MS_TURNTABLE_PIN);
		   MS_DISP = digitalRead(MS_DISP_PIN);
		  }
	  stepper.stop();

	  if (MS_TURNTABLE == 0){
		  stepper.setCurrentPosition(POS_REF);                     				// set angle the stepper is at
		  MS_TURNTABLE = 1;
		  }
	  if(MS_DISP == 0){
		  MS_DISP = 1;
		  return true;
		  }
	  else{
		  return false;
		  }
	}

	/**
	 * Check if a mug is too high
	 *
	 * @return True if mug is too high, False otherwise
	 */


	bool Turntable::turnToDispenser(int location){
		float angle = POS_DISP - POS[(location-1)];
		bool returnValue = turnTable(angle);
		return returnValue;
	}
	bool Turntable::turnToMachine(int location){
		float angle = POS_POUR - POS[(location-1)];
		bool returnValue = turnTable(angle);
		return returnValue;
	}
	bool Turntable::turnToNFCReader(int location){
		float angle = POS_READ - POS[(location-1)];
		bool returnValue = turnTable(angle);
		return returnValue;
	}
	bool Turntable::turnToTake(int location){
		float angle = POS_TAKE - POS[(location-1)];
		bool returnValue = turnTable(angle);
		return returnValue;
	}
	bool Turntable::turnTable(float angle){

		int angleFlag = 0;
		  while((angle - (stepper.currentPosition()/STEPS*360) <= 0))
		  {
		    angleFlag = 1;
		    angle = angle + 360;
		  }
		  stepper.moveTo(angle*DEGREES);

		  while(stepper.distanceToGo() && MS_DISP == 1)
		     {
		       digitalWrite(ENABLEPIN,LOW);
		       digitalWrite(RESETPIN,HIGH);
		       stepper.run();
		       MS_DISP = digitalRead(MS_DISP_PIN);
		      }

		  stepper.stop();

		  if(angleFlag == 1){
		    stepper.setCurrentPosition(stepper.currentPosition()-(STEPS));
		    Serial.println(stepper.currentPosition()/STEPS*360);
		  }

		  if(MS_DISP == 0){
			  MS_DISP = 1;
		  	  return true;
		  }
		  else{
		  	  return false;
		  }
	}
	int Turntable::getEmptyCupLocation(){
		int POSRETURN = 0;
		if((stepper.currentPosition()*(360*STEPS)) < 224.89 && (stepper.currentPosition()*(360*STEPS)) >= 183.21){
			POSRETURN = 2;
			POSFILLED[2] = 1;
		}
		if((stepper.currentPosition()*(360*STEPS)) < 183.21 && (stepper.currentPosition()*(360*STEPS)) >= 90.99){
			POSRETURN = 3;
			POSFILLED[3] = 1;
		}
		if((stepper.currentPosition()*(360*STEPS)) < 90.99 && (stepper.currentPosition()*(360*STEPS)) >= 0){
			POSRETURN = 5;
			POSFILLED[5] = 1;
		}
		if((stepper.currentPosition()*(360*STEPS)) < 360 && (stepper.currentPosition()*(360*STEPS)) >= 358.77){
			POSRETURN = 5;
			POSFILLED[5] = 1;
		}
		if((stepper.currentPosition()*(360*STEPS)) < 358.77 && (stepper.currentPosition()*(360*STEPS)) >= 317.09){
			POSRETURN = 7;
			POSFILLED[7] = 1;
		}
		if((stepper.currentPosition()*(360*STEPS)) < 317.09 && (stepper.currentPosition()*(360*STEPS)) >= 224.89){
			POSRETURN = 8;
			POSFILLED[8] = 1;
		}
		return POSRETURN;
	}
	int Turntable::getEmptyMugLocation(){
			int POSRETURN = 0;
			if((stepper.currentPosition()*(360*STEPS)) < 180 && (stepper.currentPosition()*(360*STEPS)) >= 46.1){
				POSRETURN = 1;
				POSFILLED[1] = 1;
			}
			if((stepper.currentPosition()*(360*STEPS)) < 360 && (stepper.currentPosition()*(360*STEPS)) >= 313.88){
				POSRETURN = 4;
				POSFILLED[4] = 1;
			}
			if((stepper.currentPosition()*(360*STEPS)) < 46.1 && (stepper.currentPosition()*(360*STEPS)) >= 0){
				POSRETURN = 4;
				POSFILLED[4] = 1;
			}
			if((stepper.currentPosition()*(360*STEPS)) < 313.88 && (stepper.currentPosition()*(360*STEPS)) >= 180){
				POSRETURN = 6;
				POSFILLED[6] = 1;
			}
			return POSRETURN;
		}
}



