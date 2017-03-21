/*
 * GearFlicker.cpp
 *
 *  Created on: Mar 20, 2017
 *      Author: user
 */

#include <WPILib.h>
#include "GearFlicker.h"

GearFlicker::GearFlicker(int TalonPort)
: a_Flicker(TalonPort)
{
	a_Flicker.SetControlMode(CANTalon::kVoltage);
	setVal = 0;
}

void GearFlicker::Set(float val)
{
	if (val>0){
		a_Flicker.Set(.2);
	}
	setVal = val;
}

