/*
 * Collector.h
 *
 *  Created on: Jan 18, 2017
 *      Author: hstechclub
 */

#ifndef SRC_COLLECTOR_H_
#define SRC_COLLECTOR_H_

#include <CANTalon.h>
#include "Prefs.h"

class Collector // Used for a collector that needed two motors spun in opposite directions
{
public:
	Collector(int TalonPort1, int TalonPort2);
	virtual ~Collector() = default;
	void Update(float val, uint8_t syncGroup = 0);
private:
	CANTalon a_CollectorOne;
	CANTalon a_CollectorTwo;
};



#endif /* SRC_COLLECTOR_H_ */
