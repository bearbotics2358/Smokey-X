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
	a_Flicker.SetControlMode(CANTalon::kSpeed);
	a_Flicker.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	setVal = 0;
}

void GearFlicker::Update()
{
	a_Flicker.Set(setVal * 260);
}

void GearFlicker::Set(float val)
{
	a_Flicker.Set(val * 260);
	setVal = val;
}

float GearFlicker::GetSpeed()
{
	return a_Flicker.GetSpeed();
}


