/*
 * VisionSquitto.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: user
 */
#include <cstdio>
#include <cstring>

#include "VisionSquitto.h"
#include <cpp/mosquittopp.h>

VisionSquitto::VisionSquitto(const char *id, const char *host, int port) : mosquittopp(id)
{
	int keepalive = 60;

	/* Connect immediately. This could also be done by calling
	 * mqtt_tempconv->connect(). */
	connect(host, port, keepalive);
}

VisionSquitto::~VisionSquitto()
{

}

void VisionSquitto::on_connect(int rc)
{
	printf("Connected with code %d.\n", rc);
	if(rc == 0){
		/* Only attempt to subscribe on a successful connect. */
		subscribe(NULL, "PI/CV/SHOOT/DATA");
	}
}

void VisionSquitto::on_message(const struct mosquitto_message *message)
{
	char buf[255];

	if(!strcmp(message->topic, "PI/CV/SHOOT/DATA")){
		memset(buf, 0, 255*sizeof(char));
		/* Copy N-1 bytes to ensure always 0 terminated. */
		memcpy(buf, message->payload, 254*sizeof(char));
		float distance = 0;
		float angle = 0;
		scanf(buf, distance, angle);
		printf("vision data is %f in and %f degrees", distance, angle);
	}
}

void VisionSquitto::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
	printf("Subscription succeeded.\n");
}





