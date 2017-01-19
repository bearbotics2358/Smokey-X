#include "Shooter.h"

const double ANALOG_CONV_FACTOR = 1024.0 / 360.0;
const double QUAD_SPEED_CONV_FACTOR = 0; //situational upon bot/ drive type- max rpm is 0 until we have an actual value
// 4 * encoder cpr * max rpm * 1 minute / 60s / 10 = maximum encoder value delta / .1s
Shooter::Shooter(int firePort, int anglePort)
: a_ShooterFire(firePort),
  a_ShooterAngle(anglePort)
{

}

void Shooter::Set(float speed, float angle, float offset)
{

}

float Shooter::GetAngle()
{
	return 0.0;
}

float Shooter::GetSpeed()
{
	return 0.0;
}

void InvertQuad()
{

}

void InvertAnalog()
{

}

void InvertFlyWheelMotor()
{

}

void SetWheelPIDF(float wheelP, float wheelI, float wheelD, float wheelF)
{

}

void SetAnglePID(float angleP, float angleI, float angleD)
{

}
