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
	a_Flicker.SetControlMode(CANTalon::kPercentVbus); // this is the voltage percent control type, which is default- other stuff is -12v to 12v, this is -100% to 100% of whatever voltage comes into the talon
	setVal = 0;
	tState = 0;
	tLastSet = 0;
}

void GearFlicker::Set(float val)
{
	setVal = val;
	tLastSet = Timer::GetFPGATimestamp();

}

void GearFlicker::Update()
{
	tState = Timer::GetFPGATimestamp();
	if(tState - tLastSet < 0.1){
		a_Flicker.Set(setVal);
	} else {
		setVal = 0;
		a_Flicker.Set(0);
	}
}

