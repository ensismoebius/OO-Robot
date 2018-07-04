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

	static long Configurations::leftLightSensorPin;
	static long Configurations::rightLightSensorPin;
	static long Configurations::middleLightSensorPin;

	static int Configurations::calibrationButtomPin;

	static int Configurations::notificationLedPin;

	static void Configurations::init() {

		Configurations::leftServoPin = 12;
		Configurations::rightServoPin = 11;

		Configurations::calibrationButtomPin = 2;

		Configurations::notificationLedPin = 13;

		Configurations::leftLightSensorPin = 14;
		Configurations::rightLightSensorPin = 16;
		Configurations::middleLightSensorPin = 15;

	}
} /* namespace configurations */
