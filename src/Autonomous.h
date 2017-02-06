#ifndef SRC_AUTONOMOUS_H_
#define SRC_AUTONOMOUS_H_

#include <WPILib.h>
#include "Prefs.h"
#include "SwerveDrive.h"
#include "JrimmyGyro.h"

class Autonomous {

public:
	Autonomous(Joystick &buttonBox, SwerveDrive &SwerveDrive, JrimmyGyro &Gyro);
	virtual ~Autonomous() = default;
	void Update(float GyroValue);
	void MoveToBaseline();
	void TurnToPeg(float position);
	void MoveToPeg();
	void ScoreGear();
	void ClearShields();
	void TurnToBoiler();
	void MoveToShootingDistance(float position);
	void AutoIdle();

private:
	Joystick &a_ButtonBox;
	SwerveDrive &a_Drive;
	JrimmyGyro &a_Gyro;

	float driveDistance; // already converts to inches
	// double pegDistance = 31.11;
	// double pegAngle[] = {25.42,27.89,57.996}; // left, right, middle, Goal on left
	// double shieldsDistance = 20; // only for middle

};

#endif
