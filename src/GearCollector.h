#ifndef SRC_GEARCOLLECTOR_H_
#define SRC_GEARCOLLECTOR_H_

#include <WPILib.h>
#include <CANTalon.h>
#include "Prefs.h"

class GearCollector
{
public:
	GearCollector(int TalonPort1, int TalonPort2);
	void Update(Joystick &a_Stick);

private:
	CANTalon a_GearCollectorOne;
	CANTalon a_GearCollectorTwo;
	DigitalInput a_GearSwitch;
};

#endif
