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

			static long leftLightSensorPin;
			static long rightLightSensorPin;
			static long middleLightSensorPin;

			static int calibrationButtomPin;

			static int notificationLedPin;
	};

} /* namespace configurations */

#endif /* CONFIGURATIONS_CONFIGURATIONS_H_ */
