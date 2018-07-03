#include <Arduino.h>
#include <Servo.h>

#include "robotParts/Traction.h"
#include "robotParts/LineSensor.h"

using namespace robotParts;

Traction b = Traction(14, 15);
LineSensor lineSensor = LineSensor();

void setup() {
	lineSensor.calibrateSensors();
}

void loop() {
	digitalWrite(13, HIGH);
	b.moveAhead(100);
	digitalWrite(13, LOW);
	b.moveBack(100);
}
