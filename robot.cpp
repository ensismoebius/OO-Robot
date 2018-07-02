#include <Arduino.h>
#include <Servo.h>

#include "configurations/Configurations.h"
#include "robotParts/Traction.h"

using namespace robotParts;
using namespace configurations;

Traction b = Traction(14, 15);
Configurations c = Configurations();

void setup() {
	pinMode(13, OUTPUT);
}

void loop() {
	digitalWrite(13, HIGH);
	b.moveAhead(100);
	digitalWrite(13, LOW);
	b.moveBack(100);
}
