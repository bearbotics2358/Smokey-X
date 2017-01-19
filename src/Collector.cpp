/*
 * Collector.cpp
 *
 *  Created on: Jan 18, 2017
 *      Author: hstechclub
 */

#include <WPILib.h>
#include "Collector.h"

Collector::Collector(int TalonPort1, int TalonPort2)
: Collector1(TalonPort1),
  Collector2(TalonPort2)
{

}

void Collector::Update(float val, uint8_t syncGroup)
{
	Collector1.Set(val);
	Collector2.Set(-1.0 * val);
}
