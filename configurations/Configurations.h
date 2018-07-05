/*
 * Configurations.h
 *
 *  Created on: 27 de jun de 2018
 *      Author: ensis
 */

#ifndef CONFIGURATIONS_CONFIGURATIONS_H_
#define CONFIGURATIONS_CONFIGURATIONS_H_

namespace configurations {

	class Configurations {
		public:
			static void init();

			static int rightServoPin;
			static int leftServoPin;

			static int leftLightSensorPin;
			static int rightLightSensorPin;
			static int middleLightSensorPin;

			static int calibrationButtomPin;

			static int notificationLedPin;

			static int leftSonicSensorEchoPin;
			static int rightSonicSensorEchoPin;
			static int frontSonicSensorEchoPin;

			static int leftSonicSensorTriggerPin;
			static int rightSonicSensorTriggerPin;
			static int frontSonicSensorTriggerPin;

			static int obstacleDistance;
	};

} /* namespace configurations */

#endif /* CONFIGURATIONS_CONFIGURATIONS_H_ */
