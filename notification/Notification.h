/*
 * Notification.h
 *
 *  Created on: 3 de jul de 2018
 *      Author: ensis
 */

#ifndef NOTIFICATION_NOTIFICATION_H_
#define NOTIFICATION_NOTIFICATION_H_

namespace configurations {

	class Notification {
		public:
			static void init(int pinNumber);
			static void wait();
			static void read();
		private:
			static int outputPin;

	};

} /* namespace configurations */

#endif /* NOTIFICATION_NOTIFICATION_H_ */
