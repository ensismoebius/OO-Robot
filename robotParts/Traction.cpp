/*
 * Body.cpp
 *
 *  Created on: 27 de jun de 2018
 *      Author: ensis
 */
#include "Traction.h"
#include "stdlib.h"

namespace robotParts {
	Traction::Traction() {

	}

	Traction::Traction(int rightServoPin, int leftServoPin) {
		this->rigthServo = Servo();
		this->leftServo = Servo();
		this->rightServoPin = rightServoPin;
		this->leftServoPin = leftServoPin;
	}

	void Traction::turnAround(int amount) {
		for (int i = 5; i <= amount; i += 5) {
			this->turnLeft(i);
			this->moveAhead(i);
		}
	}

	void Traction::moveAhead(int amount) {
		this->rigthServo.attach(this->rightServoPin);
		this->leftServo.attach(this->leftServoPin);
		this->rigthServo.write(-amount);
		this->leftServo.write(amount);
		delay(abs(amount * 100));
	}
	void Traction::moveBack(int amount) {
		this->rigthServo.attach(this->rightServoPin);
		this->leftServo.attach(this->leftServoPin);
		this->rigthServo.write(amount);
		this->leftServo.write(-amount);
		delay(abs(amount * 100));
	}

	void Traction::stop() {
		this->rigthServo.detach();
		this->leftServo.detach();
	}

	void Traction::turnLeft(int amount) {
		this->rigthServo.attach(this->rightServoPin);
		this->leftServo.attach(this->leftServoPin);
		this->rigthServo.write(amount);
		this->leftServo.write(amount);
		delay(abs(amount * 100));
	}

	void Traction::turnRight(int amount) {
		this->rigthServo.attach(this->rightServoPin);
		this->leftServo.attach(this->leftServoPin);
		this->rigthServo.write(-amount);
		this->leftServo.write(-amount);
		delay(abs(amount * 100));
	}
} /* namespace robot */
