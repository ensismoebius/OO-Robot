/*
 * Configurations.cpp
 *
 *  Created on: 27 de jun de 2018
 *      Author: ensis
 */

#include "Configurations.h"

namespace configurations {

	static long Configurations::leftWhiteError;
	static long Configurations::rightWhiteError;
	static long Configurations::middleWhiteError;

	static long Configurations::leftWhiteAverage;
	static long Configurations::rightWhiteAverage;
	static long Configurations::middleWhiteAverage;

	static long Configurations::leftBlackAverage;
	static long Configurations::rightBlackAverage;
	static long Configurations::middleBlackAverage;

	static long Configurations::leftBlackError;
	static long Configurations::rightBlackError;
	static long Configurations::middleBlackError;

	static long Configurations::leftPin;
	static long Configurations::rightPin;
	static long Configurations::middlePin;

	static int Configurations::calibrationButtomPin;

	Configurations::Configurations() {
		Configurations::leftWhiteError = 0;
		Configurations::rightWhiteError = 0;
		Configurations::middleWhiteError = 0;

		Configurations::leftWhiteAverage = 0;
		Configurations::rightWhiteAverage = 0;
		Configurations::middleWhiteAverage = 0;

		Configurations::leftBlackAverage = 0;
		Configurations::rightBlackAverage = 0;
		Configurations::middleBlackAverage = 0;

		Configurations::leftBlackError = 0;
		Configurations::rightBlackError = 0;
		Configurations::middleBlackError = 0;

		Configurations::leftPin = 14;
		Configurations::rightPin = 16;
		Configurations::middlePin = 15;

		Configurations::calibrationButtomPin = 16;
	}
} /* namespace configurations */
