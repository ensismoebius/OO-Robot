/*
 * SonicSensor.cpp
 *
 *  Created on: 4 de jul de 2018
 *      Author: ensis
 */

#include "SonicSensor.h"

#include <Arduino.h>

namespace configurations {

	SonicSensor::SonicSensor() {

	}

	bool SonicSensor::reachLeftObstacle() {
		if (getDistance(this->leftEchoPin, this->leftTriggerPin) <= this->obstacleDistance) {
			return true;
		}
		return false;
	}

	bool SonicSensor::reachRightObstacle() {
		if (getDistance(this->rightEchoPin, this->rightTriggerPin) <= this->obstacleDistance) {
			return true;
		}
		return false;
	}

	bool SonicSensor::reachFrontObstacle() {
		if (getDistance(this->frontEchoPin, this->frontTriggerPin) <= this->obstacleDistance) {
			return true;
		}
		return false;
	}

	long SonicSensor::getDistance(int echoPin, int triggerPin) {
		long duration;

		delay(1);

		pinMode(triggerPin, OUTPUT);
		digitalWrite(triggerPin, LOW);
		delayMicroseconds(10);
		digitalWrite(triggerPin, HIGH);
		delayMicroseconds(10);
		digitalWrite(triggerPin, LOW);

		pinMode(echoPin, INPUT);
		duration = pulseIn(echoPin, HIGH);

		return microsecondsToCentimeters(duration);
	}

	void SonicSensor::setSonicSensorFrontEchoPin(int frontEchoPin = 0) {
		this->frontEchoPin = frontEchoPin;
	}

	void SonicSensor::setSonicSensorFrontTriggerPin(int frontTriggerPin = 0) {
		this->frontTriggerPin = frontTriggerPin;
	}

	void SonicSensor::setSonicSensorLeftEchoPin(int leftEchoPin = 0) {
		this->leftEchoPin = leftEchoPin;
	}

	void SonicSensor::setSonicSensorLeftTriggerPin(int leftTriggerPin = 0) {
		this->leftTriggerPin = leftTriggerPin;
	}

	void SonicSensor::setSonicSensorRightEchoPin(int rightEchoPin = 0) {
		this->rightEchoPin = rightEchoPin;
	}

	void SonicSensor::setSonicSensorRightTriggerPin(int rightTriggerPin = 0) {
		this->rightTriggerPin = rightTriggerPin;
	}

	void SonicSensor::setObstacleDistance(int obstacleDistance) {
		this->obstacleDistance = obstacleDistance;
	}

	long SonicSensor::microsecondsToCentimeters(long microseconds) {
		// The speed of sound is 340 m/s or 29 microseconds per centimeter.
		// The ping travels out and back, so to find the distance of the
		// object we take half of the distance travelled.
		return microseconds / 29 / 2;
	}

}
/* namespace configurations */
