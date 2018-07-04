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
	lineSensor.calibrateSensors();
}

void loop() {
	digitalWrite(13, HIGH);
	traction.moveAhead(100);
	digitalWrite(13, LOW);
	traction.moveBack(100);
}
