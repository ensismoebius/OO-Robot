/*
 * SonicSensor.h
 *
 *  Created on: 4 de jul de 2018
 *      Author: ensis
 */

#ifndef ROBOTPARTS_SONICSENSOR_H_
#define ROBOTPARTS_SONICSENSOR_H_

namespace configurations {

	class SonicSensor {
		public:
			SonicSensor();

			bool leftReachObstacle();
			bool rightReachObstacle();
			bool frontReachObstacle();

			void setObstacleDistance(int obstacleDistance = 0);

			void setSonicSensorLeftEchoPin(int sonicSensorLeftEchoPin = 0);
			void setSonicSensorFrontEchoPin(int sonicSensorFrontEchoPin = 0);
			void setSonicSensorRightEchoPin(int sonicSensorRightEchoPin = 0);

			void setSonicSensorLeftTriggerPin(int sonicSensorLeftTriggerPin = 0);
			void setSonicSensorFrontTriggerPin(int sonicSensorFrontTriggerPin = 0);
			void setSonicSensorRightTriggerPin(int sonicSensorRightTriggerPin = 0);

		private:
			int obstacleDistance = 0;

			int leftEchoPin = 0;
			int frontEchoPin = 0;
			int rightEchoPin = 0;

			int leftTriggerPin = 0;
			int frontTriggerPin = 0;
			int rightTriggerPin = 0;

			long getDistance(int pinNumber, int triggerPin);
			long microsecondsToCentimeters(long microseconds);
	};

} /* namespace configurations */

#endif /* ROBOTPARTS_SONICSENSOR_H_ */
