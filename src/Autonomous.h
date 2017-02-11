#ifndef SRC_AUTONOMOUS_H_
#define SRC_AUTONOMOUS_H_

#include <WPILib.h>
#include "Prefs.h"
#include "SwerveDrive.h"
#include "JrimmyGyro.h"

enum BotPosition {
	kBlueLeft=0,
	kBlueRight,
	kRedLeft,
	kRedRight,
	kMiddle
};

class Autonomous {

public:
	Autonomous(Joystick &buttonBox, SwerveDrive &SwerveDrive, JrimmyGyro &Gyro);
	virtual ~Autonomous() = default;
	void Update(float GyroValue);
	void MoveToBaseline();
	void TurnToPeg();
	void MoveToPeg();
	void ScoreGear();
	void ClearShields();
	void TurnToBoiler();
	void MoveToBoiler();
	void ShootFuel();

	void AdjustOnWall();
	void ClearBoiler();
	void TurnToFront();

	void BlueLeft();
	void BlueRight();
	void BlueMiddle();
	void RedLeft();
	void RedRight();
	void RedMiddle();

private:
	Joystick &a_ButtonBox;
	SwerveDrive &a_Drive;
	JrimmyGyro &a_Gyro;

	BotPosition a_BotPosition;
	float driveDistance;

};

#endif
