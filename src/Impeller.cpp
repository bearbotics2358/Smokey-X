#include <WPILib.h>
#include "Impeller.h"

Impeller::Impeller(int ImpellerPort)
: a_Impeller(ImpellerPort)
{
	a_Impeller.SetControlMode(CANTalon::kSpeed);
	a_Impeller.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	a_Impeller.SetP(0.25);
	a_Impeller.SetI(0);
	a_Impeller.SetD(1.5);
	a_Impeller.SetF(0.65);
}

void Impeller::Update(float val, uint8_t syncGroup)
{
	a_Impeller.Set(val);
}

float Impeller::GetSpeed()
{
	return a_Impeller.GetSpeed();
}
