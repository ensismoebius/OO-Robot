/*
 * Notification.cpp
 *
 *  Created on: 3 de jul de 2018
 *      Author: ensis
 */

#include "Notification.h"
#include "Arduino.h"
#include "../configurations/Configurations.h"

namespace configurations {

	static int Notification::outputPin;

	static void Notification::init(int pinNumber) {
		Serial.begin(9600);
		Notification::outputPin = pinNumber;
	}

	static void Notification::wait() {

		pinMode(Notification::outputPin, OUTPUT);

		Serial.write("Wait...");

		for (int var = 0; var < 5; ++var) {
			digitalWrite(Notification::outputPin, HIGH);
			delay(500);
			digitalWrite(Notification::outputPin, LOW);
			delay(500);
		}
		digitalWrite(Notification::outputPin, LOW);
	}

	static void Notification::read() {

		pinMode(Notification::outputPin, OUTPUT);

		Serial.write("Read!");

		for (int var = 0; var < 20; ++var) {
			digitalWrite(Notification::outputPin, HIGH);
			delay(125);
			digitalWrite(Notification::outputPin, LOW);
			delay(125);
		}
		digitalWrite(Notification::outputPin, LOW);
	}

	void Notification::turnOn() {
		pinMode(Notification::outputPin, OUTPUT);
		digitalWrite(Notification::outputPin, HIGH);
	}

	void Notification::turnOff() {
		pinMode(Notification::outputPin, OUTPUT);
		digitalWrite(Notification::outputPin, LOW);
	}

} /* namespace configurations */
