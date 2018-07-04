/*
 * LineSensor.cpp
 *
 *  Created on: 28 de jun de 2018
 *      Author: ensis
 */

#include "LineSensor.h"

#include <Arduino.h>

namespace robotParts {

	LineSensor::LineSensor(int calibrationButtomPin) {
		this->leftBlackError = 0;
		this->leftWhiteError = 0;

		this->rightBlackAverage = 0;
		this->rightWhiteError = 0;

		this->middleBlackError = 0;
		this->middleWhiteError = 0;

		this->leftBlackAverage = 0;
		this->leftWhiteAverage = 0;

		this->rightBlackAverage = 0;
		this->rightWhiteAverage = 0;

		this->middleBlackAverage = 0;
		this->middleWhiteAverage = 0;

		this->calibrationButtomPin = calibrationButtomPin;
	}

	int LineSensor::getLeftSensorState() {
		pinMode(this->leftPin, INPUT);

		int value = analogRead(this->leftPin);

		if (this->isValueBetween(value, this->leftWhiteAverage, this->leftWhiteError)) {
			return LineSensor::WHITE_SIGNAL;
		}

		if (this->isValueBetween(value, this->leftBlackAverage, this->leftBlackError)) {
			return LineSensor::BLACK_SIGNAL;
		}

		return LineSensor::OUT_OF_RANGES_SIGNAL;
	}

	int LineSensor::getMiddleSensorState() {
		pinMode(this->middlePin, INPUT);

		int value = analogRead(this->middlePin);

		if (this->isValueBetween(value, this->middleWhiteAverage, this->middleWhiteError)) {
			return LineSensor::WHITE_SIGNAL;
		}

		if (this->isValueBetween(value, this->middleBlackAverage, this->middleBlackError)) {
			return LineSensor::BLACK_SIGNAL;
		}

		return LineSensor::OUT_OF_RANGES_SIGNAL;
	}

	int LineSensor::getRightSensorState() {
		pinMode(this->rightPin, INPUT);

		int value = analogRead(this->rightPin);

		if (this->isValueBetween(value, this->rightWhiteAverage, this->rightWhiteError)) {
			return LineSensor::WHITE_SIGNAL;
		}

		if (this->isValueBetween(value, this->rightBlackAverage, this->rightBlackError)) {
			return LineSensor::BLACK_SIGNAL;
		}

		return LineSensor::OUT_OF_RANGES_SIGNAL;
	}

	void LineSensor::calibrateSensors() {

		pinMode(this->leftPin, INPUT);
		pinMode(this->rightPin, INPUT);
		pinMode(this->middlePin, INPUT);
		pinMode(this->calibrationButtomPin, INPUT);

		int left = 0;
		int right = 0;
		int middle = 0;

		// Waits until calibration button are pressed
		while (digitalRead(this->calibrationButtomPin) == LOW)
			;

		// Calibrating black color
		for (int i = 1; i <= 20; ++i) {
			left = analogRead(this->leftPin);
			right = analogRead(this->rightPin);
			middle = analogRead(this->middlePin);

			this->leftBlackAverage += left;
			this->rightBlackAverage += right;
			this->middleBlackAverage += middle;

			this->leftBlackError = abs(this->leftBlackAverage / i - left);
			this->rightBlackError = abs(this->rightBlackAverage / i - right);
			this->middleBlackError = abs(this->middleBlackAverage / i - middle);

			delay(100);
		}

		// Waits until calibration button are pressed
		while (digitalRead(this->calibrationButtomPin) == LOW)
			;

		// Calibrating white color
		for (int i = 1; i <= 20; ++i) {
			left = analogRead(this->leftPin);
			right = analogRead(this->rightPin);
			middle = analogRead(this->middlePin);

			this->leftWhiteAverage += left;
			this->rightWhiteAverage += right;
			this->middleWhiteAverage += middle;

			this->leftWhiteError = abs(this->leftWhiteAverage / i - left);
			this->rightWhiteError = abs(this->rightWhiteAverage / i - right);
			this->middleWhiteError = abs(this->middleWhiteAverage / i - middle);

			delay(100);
		}

		this->leftBlackAverage /= 20;
		this->rightBlackAverage /= 20;
		this->middleBlackAverage /= 20;

		this->leftWhiteAverage /= 20;
		this->rightWhiteAverage /= 20;
		this->middleWhiteAverage /= 20;
	}

	bool LineSensor::isValueBetween(int value, int reference, int error) {
		int upperValue = reference + error;
		int lowerValue = reference - error;

		return value >= lowerValue && value <= upperValue;
	}

} /* namespace configurations */
