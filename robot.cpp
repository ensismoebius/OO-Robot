#include "robotParts/Traction.h"
#include "robotParts/LineSensor.h"
#include "notification/Notification.h"
#include "configurations/Configurations.h"

using namespace robotParts;
using namespace configurations;

Traction traction;
LineSensor lineSensor;

void setup() {
	Configurations::init();

	traction = Traction(Configurations::rightLightSensorPin, Configurations::leftLightSensorPin);

	lineSensor = LineSensor(Configurations::calibrationButtomPin);
	lineSensor.setMiddlePin(Configurations::middleLightSensorPin);
	lineSensor.setRightPin(Configurations::rightLightSensorPin);
	lineSensor.setLeftPin(Configurations::leftLightSensorPin);

	Notification::init(Configurations::notificationLedPin);
	Notification::wait();

	// Stays here until the robot is not calibrated
	while (lineSensor.calibrateSensors())
		;

	Notification::read();
}

void loop() {

	digitalWrite(13, HIGH);
	if (lineSensor.getLeftSensorState() == LineSensor::BLACK_SIGNAL) traction.turnLeft(10);
	if (lineSensor.getRightSensorState() == LineSensor::BLACK_SIGNAL) traction.turnRight(10);
	if (lineSensor.getMiddleSensorState() == LineSensor::BLACK_SIGNAL) traction.moveAhead(10);
	digitalWrite(13, LOW);
}
