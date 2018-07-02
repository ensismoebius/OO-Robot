/*
 * LineSensor.cpp
 *
 *  Created on: 28 de jun de 2018
 *      Author: ensis
 */

#include "LineSensor.h"
#include "Arduino.h"
#include "../configurations/Configurations.h"

using namespace configurations;

namespace robotParts {

	LineSensor::LineSensor() {

	}

	int LineSensor::getLeftSensorState() {
		int value = analogRead(Configurations::leftPin);

		if (this->isValueBetween(value, Configurations::leftWhiteAverage, Configurations::leftWhiteError)) {
			return LineSensor::WHITE_SIGNAL;
		}

		if (this->isValueBetween(value, Configurations::leftBlackAverage, Configurations::leftBlackError)) {
			return LineSensor::BLACK_SIGNAL;
		}

		return LineSensor::OUT_OF_RANGES_SIGNAL;
	}

	int LineSensor::getMiddleSensorState() {
		int value = analogRead(Configurations::middlePin);

		if (this->isValueBetween(value, Configurations::middleWhiteAverage, Configurations::middleWhiteError)) {
			return LineSensor::WHITE_SIGNAL;
		}

		if (this->isValueBetween(value, Configurations::middleBlackAverage, Configurations::middleBlackError)) {
			return LineSensor::BLACK_SIGNAL;
		}

		return LineSensor::OUT_OF_RANGES_SIGNAL;
	}

	int LineSensor::getRightSensorState() {
		int value = analogRead(Configurations::rightPin);

		if (this->isValueBetween(value, Configurations::rightWhiteAverage, Configurations::rightWhiteError)) {
			return LineSensor::WHITE_SIGNAL;
		}

		if (this->isValueBetween(value, Configurations::rightBlackAverage, Configurations::rightBlackError)) {
			return LineSensor::BLACK_SIGNAL;
		}

		return LineSensor::OUT_OF_RANGES_SIGNAL;
	}

	void LineSensor::calibrateSensors() {

		int left = 0;
		int right = 0;
		int middle = 0;

		// Calibrating black color
		for (int i = 0; i < 20; ++i) {
			left = this->getLeftSensorState();
			right = this->getRightSensorState();
			middle = this->getMiddleSensorState();

			Configurations::leftBlackAverage += left;
			Configurations::rightBlackAverage += right;
			Configurations::middleBlackAverage += middle;

			Configurations::leftBlackError = left > Configurations::leftBlackError ? left : Configurations::leftBlackError;
			Configurations::rightBlackError = right > Configurations::rightBlackError ? right : Configurations::rightBlackError;
			Configurations::middleBlackError = middle > Configurations::middleBlackError ? middle : Configurations::middleBlackError;
			delay(100);
		}

		// Calibrating white color
		for (int i = 0; i < 20; ++i) {
			left = this->getLeftSensorState();
			right = this->getRightSensorState();
			middle = this->getMiddleSensorState();

			Configurations::leftWhiteAverage += left;
			Configurations::rightWhiteAverage += right;
			Configurations::middleWhiteAverage += middle;

			Configurations::leftWhiteError = left > Configurations::leftWhiteError ? left : Configurations::leftWhiteError;
			Configurations::rightWhiteError = right > Configurations::rightWhiteError ? right : Configurations::rightWhiteError;
			Configurations::middleWhiteError = middle > Configurations::middleWhiteError ? middle : Configurations::middleWhiteError;
			delay(100);
		}

		Configurations::leftBlackAverage /= 20;
		Configurations::rightBlackAverage /= 20;
		Configurations::middleBlackAverage /= 20;

		Configurations::leftWhiteAverage /= 20;
		Configurations::rightWhiteAverage /= 20;
		Configurations::middleWhiteAverage /= 20;
	}

	bool LineSensor::isValueBetween(int value, int reference, int error) {
		int upperValue = reference + error;
		int lowerValue = reference - error;

		return value >= lowerValue && value <= upperValue;
	}

} /* namespace configurations */
