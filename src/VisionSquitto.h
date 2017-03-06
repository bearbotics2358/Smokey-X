/*
 * VisionSquitto.h
 *
 *  Created on: Mar 6, 2017
 *      Author: user
 */

#ifndef SRC_VISIONSQUITTO_H_
#define SRC_VISIONSQUITTO_H_

#include <cpp/mosquittopp.h>

class VisionSquitto : public mosqpp::mosquittopp
{
	public:
		VisionSquitto(const char *id, const char *host, int port);
		~VisionSquitto();

		void on_connect(int rc);
		void on_message(const struct mosquitto_message *message);
		void on_subscribe(int mid, int qos_count, const int *granted_qos);
};




#endif /* SRC_VISIONSQUITTO_H_ */
