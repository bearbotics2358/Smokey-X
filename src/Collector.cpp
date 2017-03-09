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
	a_CollectorOne.SetPID(COLLECTOR_ONE_PID);
	a_CollectorOne.SetF(COLLECTOR_ONE_F);

	a_CollectorTwo.SetControlMode(CANTalon::kSpeed);
	a_CollectorTwo.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	a_CollectorTwo.SetPID(COLLECTOR_TWO_PID);
	a_CollectorTwo.SetF(COLLECTOR_TWO_F);
}

void Collector::Update(float val, uint8_t syncGroup)
{
		a_CollectorOne.Set(val * 1300);
		a_CollectorTwo.Set( -1.0 * val * 260 / 2);

		SmartDashboard::PutNumber("CollectorOneTheo",val * COLLECTOR_ONE_MAX_RPM);
		SmartDashboard::PutNumber("CollectorTwoTheo",-1.0*val * 260 / 4);

		SmartDashboard::PutNumber("CollectorOne",a_CollectorOne.GetSpeed());
		SmartDashboard::PutNumber("CollectorTwo",a_CollectorTwo.GetSpeed());
}
