/*
 * LineSensor.h
 *
 *  Created on: 28 de jun de 2018
 *      Author: ensis
 */

#ifndef ROBOTPARTS_LINESENSOR_H_
#define ROBOTPARTS_LINESENSOR_H_

namespace robotParts {

	class LineSensor {
		public:
			static const int BLACK_SIGNAL = 0;
			static const int WHITE_SIGNAL = 1;
			static const int UNDEFINED_SIGNAL = 2;
			LineSensor();
			int getLeftSensorState();
			int getMiddleSensorState();
			int getRightSensorState();
			void calibrateSensors();
		private:
			bool isValueBetween(int value, int reference, int error);

	};

} /* namespace configurations */

#endif /* ROBOTPARTS_LINESENSOR_H_ */
