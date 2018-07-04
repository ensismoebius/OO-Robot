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
			static const int OUT_OF_RANGES_SIGNAL = 2;
			LineSensor(int calibrationButtomPin);
			LineSensor();
			int getLeftSensorState();
			int getMiddleSensorState();
			int getRightSensorState();
			void calibrateSensors();
		private:
			int leftPin;
			int rightPin;
			int middlePin;
			int calibrationButtomPin;

			int leftWhiteAverage = 0;
			int rightWhiteAverage = 0;
			int middleWhiteAverage = 0;

			int leftBlackAverage = 0;
			int rightBlackAverage = 0;
			int middleBlackAverage = 0;

			int leftWhiteError = 0;
			int rightWhiteError = 0;
			int middleWhiteError = 0;

			int leftBlackError = 0;
			int rightBlackError = 0;
			int middleBlackError = 0;

			bool isValueBetween(int value, int reference, int error);

	};

} /* namespace configurations */

#endif /* ROBOTPARTS_LINESENSOR_H_ */
