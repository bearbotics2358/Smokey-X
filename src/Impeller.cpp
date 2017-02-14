#include <WPILib.h>
#include "Impeller.h"

Impeller::Impeller(int ImpellerPort)
: a_Impeller(ImpellerPort)
{
	a_Impeller.SetControlMode(CANTalon::kSpeed);
	a_Impeller.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	a_Impeller.SetPID(0,0,0);
	a_Impeller.SetF(0);
}

void Impeller::Update(float val, uint8_t syncGroup)
{
	a_Impeller.Set(val); // * MAX_BAG_RPM_FIVE_TO_ONE);
}
