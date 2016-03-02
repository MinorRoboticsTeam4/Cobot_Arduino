/*
 * Turntable.h
 *
 *  Created on: 24 jan. 2016
 *      Author: AC-Langerak
 */

#ifndef SRC_TURNTABLE_H_
#define SRC_TURNTABLE_H_

#include "Consumption.h"
#include "Arduino.h"
#include "AccelStepper.h"


namespace coffee {

	class Turntable {

		public:


			static Turntable& getInstance() {
				static Turntable instance;
				return instance;
			}

			bool turnToMachine(int location);
			bool turnToDispenser(int location);
			bool turnToNFCReader(int location);
			bool turnToTake(int location);
			int getEmptyCupLocation();
			int getEmptyMugLocation();


		private:
			Turntable();
			Turntable(Turntable const&); //Dont implement
			void operator=(Turntable const&); //Dont implement

			bool turnTable(float angle);

			bool calibrate();

			// Variables stepper and micro switches
			const int XSTEP = 11;
			const int XDIR = 35;
			const int ENABLEPIN = 31;
			const int RESETPIN = 33;
			const int STEPS = 6400;                               	// amount of steps for one round
			const float DEGREES = STEPS/360;                      	// number the angle given will be multiplied with
			const float ANGLE = 0;                                	// angle the motor will turn
			const float ACCEL = 5000;                             	// accelaration used (steps/second^2)
			const float MAXSPEED = 1000;                          	// max speed the motor will run (steps/second)
			const int MS_TURNTABLE_PIN = 27;                      	// pin at which micro switch is attached
			const int MS_DISP_PIN = 29;                           	// pin at which micro switch is attached
			int MS_TURNTABLE = 1;                                 	// variable for micro switch used for calibration
			int MS_DISP = 1;                                      	// variable for micro switch used for dispenser

			// Angles of positions
			const float POS1 = 0;
			const float POS2 = 46.11;
			const float POS3 = 87.79;
			const float POS4 = 133.9;
			const float POS5 = 180;
			const float POS6 = 226.12;
			const float POS7 = 272.23;
			const float POS8 = 313.91;
			const float POS_DISP = 270;                        		// position dispenser is at
			const float POS_POUR = 0;                               // postition where coffee is poured
			const float POS_TAKE = 180;                             // postition where coffee is taken
			const float POS_READ = 225;                             // postition of NFC reader
			const float POS_REF = 3.66;                             // postition of reference point
			float POS[8] = {POS1,POS2,POS3,POS4,POS5,POS6,POS7,POS8};
			int POSFILLED[8] = {0,0,0,0,0,0,0,0};				// variable to store filled positions in

			AccelStepper stepper;
	};

}

#endif /* SRC_TURNTABLE_H_ */
