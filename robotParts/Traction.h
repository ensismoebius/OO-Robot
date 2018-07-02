/*
 * Body.h
 *
 *  Created on: 27 de jun de 2018
 *      Author: ensis
 */
#include <Servo.h>
#include <Arduino.h>

#ifndef BODY_H_
#define BODY_H_

namespace robotParts {

	class Traction {
		public:
			Traction(int rightServoPin, int leftServoPin);
			void moveAhead(int amount);
			void moveBack(int amount);
			void stop();
			void turnRight(int amount);
			void turnLeft(int amount);
		private:
			Servo rigthServo;
			Servo leftServo;
			int rightServoPin;
			int leftServoPin;
	};

} /* namespace robot */

#endif /* BODY_H_ */
