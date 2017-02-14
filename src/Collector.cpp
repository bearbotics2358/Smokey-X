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
	a_CollectorOne.SetPID(0.145,0,0.5);
	a_CollectorOne.SetF(0.12);

	a_CollectorTwo.SetControlMode(CANTalon::kSpeed);
	a_CollectorTwo.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	a_CollectorTwo.SetPID(0.4,0,0.2);
	a_CollectorTwo.SetF(0.095);

}

void Collector::Update(float val, uint8_t syncGroup)
{
		a_CollectorOne.Set(val * COLLECTOR_ONE_MAX_RPM);
		a_CollectorTwo.Set(-1.0 * val * COLLECTOR_TWO_MAX_RPM);

		SmartDashboard::PutNumber("CollectorOneTheo",val * COLLECTOR_ONE_MAX_RPM);
		SmartDashboard::PutNumber("CollectorTwoTheo",-1.0*val * COLLECTOR_TWO_MAX_RPM);

		SmartDashboard::PutNumber("CollectorOne",a_CollectorOne.GetSpeed());
		SmartDashboard::PutNumber("CollectorTwo",a_CollectorTwo.GetSpeed());
}
