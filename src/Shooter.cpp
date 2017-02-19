#include "Shooter.h"

const double MAX_RPM = 4500; //situational upon bot/ drive type- max rpm is 0 until we have an actual value

Shooter::Shooter(int firePort)
: a_ShooterFire(firePort)
{
	a_ShooterFire.SetControlMode(CANTalon::kSpeed);
	a_ShooterFire.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	a_ShooterFire.SetSensorDirection(true);
	a_ShooterFire.SetP(0.125);
	a_ShooterFire.SetI(0);
	a_ShooterFire.SetD(1);
	a_ShooterFire.SetF(0.0275);
	a_ShooterFire.Set(0);

}

void Shooter::Set(float speed)
{
	a_ShooterFire.Set(speed* MAX_RPM); // ctre mag encoders and talon srx's work well together- no config needed for straightforward RPM control
}

float Shooter::GetSpeed()
{
	return a_ShooterFire.GetSpeed();
}

void Shooter::InvertQuad()
{
	a_ShooterFire.SetSensorDirection(true);
}

void Shooter::InvertFlyWheelMotor()
{
	a_ShooterFire.SetInverted(true);
}

void Shooter::SetWheelPIDF(float wheelP, float wheelI, float wheelD, float wheelF)
{
	a_ShooterFire.SetP(wheelP);
	a_ShooterFire.SetI(wheelI);
	a_ShooterFire.SetD(wheelD);
	a_ShooterFire.SetF(wheelF);
}
