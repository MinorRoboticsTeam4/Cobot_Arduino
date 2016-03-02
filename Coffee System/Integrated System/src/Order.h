/*
 * Order.h
 *
 *  Created on: 24 jan. 2016
 *      Author: AC-Langerak
 */

#ifndef SRC_ORDER_H_
#define SRC_ORDER_H_

#include "Consumption.h"
#include "SimpleList.h"

namespace coffee {

	class Order {
		public:

		enum Status{
			NOT_DONE = 0,
			COMPLETED = 1
		};

			Order();
			~Order();

			int getTotalAmountOfCups();
			int getTotalAmountOfMugs();

			void addConsumption(coffee::containerType container,coffee::coffeeTypes type);

			void removeAllConsumptions();

			Consumption* getNextEmptyCup();
			Consumption* getNextEmptyMug();

			Consumption* getNextUnplacedCup();
			Consumption* getNextUnplacedMug();

			Consumption* getNextFilledCup();
			Consumption* getNextFilledMug();

			int getAmountUnfilledCups();
			int getAmountUnfilledMugs();

			int getAmountUnplacedCups();
			int getAmountUnplacedMugs();

			int getAmountFilledCups();
			int getAmountFilledMugs();

			void setStatus(Status status);
			Status getStatus();

		private:
			SimpleList<Consumption> orderList;

			Status currentStatus;

			int unfilledCups;
			int unfilledMugs;

			int unplacedCups;
			int unplacedMugs;

			int filledMugs;
			int filledCups;

			int amountOfCups;
			int amountOfMugs;
	};

}

#endif /* SRC_ORDER_H_ */
