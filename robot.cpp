#include <Arduino.h>
#include <Servo.h>

#include "robotParts/Traction.h"
#include "robotParts/LineSensor.h"
#include "configurations/Configurations.h"

using namespace robotParts;
using namespace configurations;

Traction traction;
LineSensor lineSensor;

void setup() {
	Configurations::init();

	traction = Traction(Configurations::rightLightSensorPin, Configurations::leftLightSensorPin);

	lineSensor = LineSensor(Configurations::calibrationButtomPin);
	lineSensor.setLeftPin(Configurations::leftLightSensorPin);
	lineSensor.setRightPin(Configurations::rightLightSensorPin);
	lineSensor.setMiddlePin(Configurations::middleLightSensorPin);

	// Stays here until the robot is not calibrated
	while (lineSensor.calibrateSensors())
		;
}

void loop() {

	if (lineSensor.getLeftSensorState() == LineSensor::BLACK_SIGNAL) {
		traction.turnLeft(10);
	}

	if (lineSensor.getRightSensorState() == LineSensor::BLACK_SIGNAL) {
		traction.turnRight(10);
	}

	if (lineSensor.getMiddleSensorState() == LineSensor::BLACK_SIGNAL) {
		traction.moveAhead(10);
	}

	digitalWrite(13, HIGH);
	traction.moveAhead(100);
	digitalWrite(13, LOW);
	traction.moveBack(100);
}
