/*
 * Collector.h
 *
 *  Created on: Jan 18, 2017
 *      Author: hstechclub
 */

#ifndef SRC_COLLECTOR_H_
#define SRC_COLLECTOR_H_

#include "CANTalonSRX.h"

class Collector
{
public:
	Collector(int TalonPort1, int TalonPort2);
	~Collector();
	void Update(float val, uint8_t syncGroup = 0);
private:
	CanTalonSRX Collector1;
	CanTalonSRX Collector2;
};



#endif /* SRC_COLLECTOR_H_ */
