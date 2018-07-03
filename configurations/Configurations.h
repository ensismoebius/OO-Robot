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
			Configurations();
			static long leftWhiteAverage;
			static long rightWhiteAverage;
			static long middleWhiteAverage;

			static long leftWhiteError;
			static long rightWhiteError;
			static long middleWhiteError;

			static long leftBlackAverage;
			static long rightBlackAverage;
			static long middleBlackAverage;

			static long leftBlackError;
			static long rightBlackError;
			static long middleBlackError;

			static long leftPin;
			static long rightPin;
			static long middlePin;

			static int calibrationButtomPin;
	};

} /* namespace configurations */

#endif /* CONFIGURATIONS_CONFIGURATIONS_H_ */
