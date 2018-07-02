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

		return LineSensor::UNDEFINED_SIGNAL;
	}

	int LineSensor::getMiddleSensorState() {
		int value = analogRead(Configurations::middlePin);

		if (this->isValueBetween(value, Configurations::middleWhiteAverage, Configurations::middleWhiteError)) {
			return LineSensor::WHITE_SIGNAL;
		}

		if (this->isValueBetween(value, Configurations::middleBlackAverage, Configurations::middleBlackError)) {
			return LineSensor::BLACK_SIGNAL;
		}

		return LineSensor::UNDEFINED_SIGNAL;
	}

	int LineSensor::getRightSensorState() {
		int value = analogRead(Configurations::rightPin);

		if (this->isValueBetween(value, Configurations::rightWhiteAverage, Configurations::rightWhiteError)) {
			return LineSensor::WHITE_SIGNAL;
		}

		if (this->isValueBetween(value, Configurations::rightBlackAverage, Configurations::rightBlackError)) {
			return LineSensor::BLACK_SIGNAL;
		}

		return LineSensor::UNDEFINED_SIGNAL;
	}

	void LineSensor::calibrateSensors() {
		for (int i = 0; i < 20; ++i) {

		}
	}

	bool LineSensor::isValueBetween(int value, int reference, int error) {
		int upperValue = reference + error;
		int lowerValue = reference - error;

		return value >= lowerValue && value <= upperValue;
	}

} /* namespace configurations */
