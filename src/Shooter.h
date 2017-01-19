#ifndef SRC_SHOOTER_H_
#define SRC_SHOOTER_H_

#include <WPILib.h>
#include "CANTalon.h"

class Shooter
{
public:
	Shooter(int firePort, int anglePort);
	virtual ~Shooter() = default;

	void Set(float speed, float angle, float offset);

	float GetAngle();
	float GetSpeed();

	void InvertQuad();
	void InvertAnalog();

	void InvertFlyWheelMotor();

	void SetWheelPIDF(float wheelP, float wheelI, float wheelD, float wheelF);
	void SetAnglePID(float angleP, float angleI, float angleD);
private:
	CANTalon a_ShooterFire;
	CANTalon a_ShooterAngle;
};



#endif
