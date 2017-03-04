#include <WPILib.h>
#include "Impeller.h"

Impeller::Impeller(int ImpellerPort)
: a_Impeller(ImpellerPort)
{
	a_Impeller.SetControlMode(CANTalon::kSpeed);
	a_Impeller.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	a_Impeller.SetP(IMPELLER_P);
	a_Impeller.SetI(IMPELLER_I);
	a_Impeller.SetD(IMPELLER_D);
	a_Impeller.SetF(IMPELLER_F);
	tState = 0;
	setVal = 0;
}

void Impeller::Update()
{
	a_Impeller.Set(setVal * 260);
}

void Impeller::Set(float val)
{
	a_Impeller.Set(val * 260);
	setVal = val;
}

float Impeller::GetSpeed()
{
	return a_Impeller.GetSpeed();
}
