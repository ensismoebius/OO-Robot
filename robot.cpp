#include "robotParts/Traction.h"
#include "robotParts/LineSensor.h"
#include "robotParts/SonicSensor.h"
#include "notification/Notification.h"
#include "configurations/Configurations.h"

using namespace robotParts;
using namespace configurations;

Traction traction;
LineSensor lineSensor;
SonicSensor sonicSensor;

void setup() {
	Configurations::init();

	traction = Traction(Configurations::rightLightSensorPin, Configurations::leftLightSensorPin);

	lineSensor = LineSensor(Configurations::calibrationButtomPin);
	lineSensor.setMiddlePin(Configurations::middleLightSensorPin);
	lineSensor.setRightPin(Configurations::rightLightSensorPin);
	lineSensor.setLeftPin(Configurations::leftLightSensorPin);

	sonicSensor.setObstacleDistance(Configurations::obstacleDistance);

	sonicSensor.setSonicSensorLeftEchoPin(Configurations::leftSonicSensorEchoPin);
	sonicSensor.setSonicSensorFrontEchoPin(Configurations::frontSonicSensorEchoPin);
	sonicSensor.setSonicSensorRightEchoPin(Configurations::rightSonicSensorEchoPin);

	sonicSensor.setSonicSensorLeftTriggerPin(Configurations::leftSonicSensorTriggerPin);
	sonicSensor.setSonicSensorFrontTriggerPin(Configurations::frontSonicSensorTriggerPin);
	sonicSensor.setSonicSensorRightTriggerPin(Configurations::rightSonicSensorTriggerPin);

	Notification::init(Configurations::notificationLedPin);
	Notification::wait();

	// Stays here until the robot is not calibrated
	while (lineSensor.calibrateSensors())
		;

	Notification::read();
}

void loop() {
	delay(200);
	digitalWrite(13, HIGH);

	if (sonicSensor.frontReachObstacle() || sonicSensor.leftReachObstacle() || sonicSensor.rightReachObstacle()) {
		traction.turnAround(10);
		return;
	}

	// Follows the black line
	if (lineSensor.getLeftSensorState() == LineSensor::BLACK_SIGNAL) traction.turnLeft(10);
	if (lineSensor.getRightSensorState() == LineSensor::BLACK_SIGNAL) traction.turnRight(10);
	if (lineSensor.getMiddleSensorState() == LineSensor::BLACK_SIGNAL) traction.moveAhead(10);

	// All sensor are white: Go ahead!
	if (lineSensor.getMiddleSensorState() == LineSensor::WHITE_SIGNAL && lineSensor.getMiddleSensorState() == LineSensor::WHITE_SIGNAL && lineSensor.getMiddleSensorState() == LineSensor::WHITE_SIGNAL) {
		traction.moveAhead(10);
	}
	digitalWrite(13, LOW);
}
