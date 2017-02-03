/*
 * Collector.cpp
 *
 *  Created on: Jan 18, 2017
 *      Author: hstechclub
 */

#include <WPILib.h>
#include "Collector.h"

Collector::Collector(int TalonPort1, int TalonPort2)
: a_CollectorOne(TalonPort1),
  a_CollectorTwo(TalonPort2)
{
	a_CollectorOne.SetControlMode(CANTalon::kSpeed);
	a_CollectorOne.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	a_CollectorOne.SetPID(0,0,0);
	a_CollectorOne.SetF(0);

	a_CollectorTwo.SetControlMode(CANTalon::kSpeed);
	a_CollectorTwo.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	a_CollectorTwo.SetPID(0,0,0);
	a_CollectorTwo.SetF(0);
}

void Collector::Update(float val, uint8_t syncGroup)
{
	if (val > MAX_BAG_RPM_FIVE_TO_ONE){
		a_CollectorOne.Set(MAX_BAG_RPM_FIVE_TO_ONE);
		a_CollectorOne.Set(MAX_BAG_RPM_FIVE_TO_ONE);
	} else {
		a_CollectorOne.Set(val);
		a_CollectorTwo.Set(-1.0 * val);
	}
}
