/*
 * Consumption.h
 *
 *  Created on: 24 jan. 2016
 *      Author: AC-Langerak
 */

#ifndef SRC_CONSUMPTION_H
#define SRC_CONSUMPTION_H

#include "CoffeeMachine.h"

namespace coffee {

//Container that will contain coffee
enum containerType
{
	cup = 0,
	mug = 1
};


	class Consumption {
	public:

			Consumption();
			~Consumption();

			void setCoffeeType(coffee::coffeeTypes flavour);
			void setContainerType(containerType holdingContainer);


			coffeeTypes getCoffeeType();
			containerType getContainerType();

			bool isFilled();
			bool isPlaced();
			int getLocation();

			void setFilled(bool isFill);
			void setPlaced(bool isPlaced);
			void setLocation(int setLocation);

		private:

			coffeeTypes type;
			containerType container;

			int location;

			bool placed;
			bool filled;

	};

}

#endif /* SRC_CONSUMPTION_H_ */
