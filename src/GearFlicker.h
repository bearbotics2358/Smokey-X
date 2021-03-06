/*
 * GearFlicker.h
 *
 *  Created on: Mar 20, 2017
 *      Author: user
 */

#ifndef SRC_GEARFLICKER_H_
#define SRC_GEARFLICKER_H_

#include <CANTalon.h>
#include "Prefs.h"

class GearFlicker
{
public:
	GearFlicker(int TalonPort);
	virtual ~GearFlicker() = default;
	void Set(float val);
	void Update();
private:
	CANTalon a_GearFlicker;
	float setVal;
	float tLastSet;
};

#endif /* SRC_GEARFLICKER_H_ */
