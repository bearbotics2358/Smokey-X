/*
 * GearFlicker.cpp
 *
 *  Created on: Mar 20, 2017
 *      Author: user
 */

#include <WPILib.h>
#include "GearFlicker.h"

GearFlicker::GearFlicker(int TalonPort)
: a_GearFlicker(TalonPort)
{
	a_GearFlicker.SetControlMode(CANTalon::kPercentVbus); // this is the voltage percent control type, which is default- other stuff is -12v to 12v, this is -100% to 100% of whatever voltage comes into the talon
	setVal = 0;
	tLastSet = 0;
}

void GearFlicker::Set(float val)
{
	setVal = val;
	tLastSet = Timer::GetFPGATimestamp();
}

void GearFlicker::Update()
{
	printf("Setval is: %f ", setVal );
	if(Timer::GetFPGATimestamp() - tLastSet < 0.1){
		a_GearFlicker.Set(setVal);
		printf("we should be moving the flicker now\n");
	} else {
		setVal = 0;
		a_GearFlicker.Set(0);
		printf("the flicker should not move now\n");
	}
}

