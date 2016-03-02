#include "MugOrNot.h"

namespace coffee {

MugOrNot::MugOrNot() : mug(false) {
	pinMode(A2, INPUT);
}

bool MugOrNot::hasMug() {
	int measurementOne = analogRead(A2);
	delay(500);
	int measurementTwo = analogRead(A2);

	if(measurementOne < 750 && measurementTwo < 750) {
		return true;
	} else {
		return false;
	}
}
}
