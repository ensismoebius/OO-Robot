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
			int getLeftSensorState();
			int getMiddleSensorState();
			int getRightSensorState();
			void calibrateSensors();
		private:
			int leftPin;
			int rightPin;
			int middlePin;

			int leftWhiteAverage;
			int rightWhiteAverage;
			int middleWhiteAverage;

			int leftBlackAverage;
			int rightBlackAverage;
			int middleBlackAverage;

			int leftWhiteError;
			int rightWhiteError;
			int middleWhiteError;

			int leftBlackError;
			int rightBlackError;
			int middleBlackError;

			int calibrationButtomPin;

			bool isValueBetween(int value, int reference, int error);

	};

} /* namespace configurations */

#endif /* ROBOTPARTS_LINESENSOR_H_ */
