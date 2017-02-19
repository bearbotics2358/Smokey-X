#ifndef SRC_SHOOTER_H_
#define SRC_SHOOTER_H_

#include <WPILib.h>
#include "CANTalon.h"

class Shooter // Simple PIDF flywheel shooter
{
public:
	Shooter(int firePort);
	virtual ~Shooter() = default;

	void Set(float speed);

	float GetSpeed();

	void InvertQuad();

	void InvertFlyWheelMotor();

	void SetWheelPIDF(float wheelP, float wheelI, float wheelD, float wheelF);
private:
	CANTalon a_ShooterFire;
};



#endif
