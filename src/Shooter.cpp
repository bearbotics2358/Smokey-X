#include "Shooter.h"

const double ANALOG_CONV_FACTOR = 1024.0 / 360.0;
const double QUAD_SPEED_CONV_FACTOR = 0; //situational upon bot/ drive type- max rpm is 0 until we have an actual value
// 4 * encoder cpr * max rpm * 1 minute / 60s / 10 = maximum encoder value delta / .1s
Shooter::Shooter(int firePort, int anglePort)
: a_ShooterFire(firePort),
  a_ShooterAngle(anglePort)
{
	a_ShooterAngle.SetControlMode(CANTalon::kPosition);
	a_ShooterAngle.SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
	a_ShooterAngle.SetSensorDirection(false);
	a_ShooterAngle.SetP(0);
	a_ShooterAngle.SetI(0);
	a_ShooterAngle.SetD(0);
	a_ShooterAngle.Set(0);

	a_ShooterFire.SetControlMode(CANTalon::kSpeed);
	a_ShooterFire.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	a_ShooterFire.SetSensorDirection(false);
	a_ShooterFire.SetP(0);
	a_ShooterFire.SetI(0);
	a_ShooterFire.SetD(0);
	a_ShooterFire.SetF(0);
	a_ShooterFire.Set(0);

}

void Shooter::Set(float speed, float angle, float offset)
{
	a_ShooterFire.Set(speed * QUAD_SPEED_CONV_FACTOR);
	a_ShooterAngle.Set((angle + offset) * ANALOG_CONV_FACTOR);
}

float Shooter::GetAngle()
{
	return a_ShooterAngle.GetPosition();
}

float Shooter::GetSpeed()
{
	return a_ShooterFire.GetSpeed();
}

void Shooter::InvertQuad()
{
	a_ShooterFire.SetSensorDirection(true);
}

void Shooter::InvertAnalog()
{
	a_ShooterAngle.SetSensorDirection(true);
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

void Shooter::SetAnglePID(float angleP, float angleI, float angleD)
{
	a_ShooterAngle.SetP(angleP);
	a_ShooterAngle.SetI(angleI);
	a_ShooterAngle.SetD(angleD);
}
