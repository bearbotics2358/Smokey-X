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
	void Update();
	void Set(float val);
	float GetSpeed();
private:
	CANTalon a_Flicker;
	float setVal;
};

#endif /* SRC_GEARFLICKER_H_ */
