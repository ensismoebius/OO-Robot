/*
 * Configurations.cpp
 *
 *  Created on: 27 de jun de 2018
 *      Author: ensis
 */
#include "Configurations.h"

namespace configurations {

	static int Configurations::rightServoPin;
	static int Configurations::leftServoPin;

	static int Configurations::leftLightSensorPin;
	static int Configurations::rightLightSensorPin;
	static int Configurations::middleLightSensorPin;

	static int Configurations::calibrationButtomPin;

	static int Configurations::notificationLedPin;

	static int Configurations::leftSonicSensorEchoPin;
	static int Configurations::rightSonicSensorEchoPin;
	static int Configurations::frontSonicSensorEchoPin;

	static int Configurations::leftSonicSensorTriggerPin;
	static int Configurations::rightSonicSensorTriggerPin;
	static int Configurations::frontSonicSensorTriggerPin;

	static int Configurations::obstacleDistance;

	static void Configurations::init() {

		Configurations::leftServoPin = 12;
		Configurations::rightServoPin = 11;

		Configurations::calibrationButtomPin = 2;

		Configurations::notificationLedPin = 13;

		Configurations::leftLightSensorPin = 14;
		Configurations::rightLightSensorPin = 16;
		Configurations::middleLightSensorPin = 15;

		Configurations::leftSonicSensorEchoPin = 16;
		Configurations::rightSonicSensorEchoPin = 17;
		Configurations::frontSonicSensorEchoPin = 18;

		Configurations::leftSonicSensorTriggerPin = 19;
		Configurations::rightSonicSensorTriggerPin = 20;
		Configurations::frontSonicSensorTriggerPin = 21;

		Configurations::obstacleDistance = 4;

	}
} /* namespace configurations */
