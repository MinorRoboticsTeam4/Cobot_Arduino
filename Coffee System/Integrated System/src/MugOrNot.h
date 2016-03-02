/*
 * MugoRNot.h
 *
 *  Created on: Jan 27, 2016
 *      Author: Emil Flach
 */

#ifndef SRC_MUGORNOT_H_
#define SRC_MUGORNOT_H_

#include "Arduino.h"

namespace coffee {

class MugOrNot {
public:
	static MugOrNot& getInstance() {
		static MugOrNot instance;
		return instance;
	}

	bool hasMug();
private:
	MugOrNot();
	MugOrNot(MugOrNot const&); //Dont implement
	void operator=(MugOrNot const&); //Dont implement
	bool mug;
};

} /* namespace coffee */

#endif /* SRC_MUGORNOT_H_ */
