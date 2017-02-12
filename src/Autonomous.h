#ifndef SRC_AUTONOMOUS_H_
#define SRC_AUTONOMOUS_H_

#include <WPILib.h>
#include "Prefs.h"
#include "SwerveDrive.h"
#include "JrimmyGyro.h"
#include "Shooter.h"

enum BotPosition {
	kBlueLeft=0,
	kBlueRight,
	kRedLeft,
	kRedRight,
	kMiddle
};

class Autonomous {

public:
	Autonomous(Joystick &buttonBox, SwerveDrive &SwerveDrive, JrimmyGyro &Gyro, Shooter &Shooter);
	virtual ~Autonomous() = default;
	void Update(float GyroValue);
	void MoveToBaseline(int i);
	void TurnToPeg(int i);
	void TurnToPegWait(int i);
	void MoveToPeg(int i);
	void ScoreGear(int i);
	void ClearShields(int i);
	void TurnToBoiler(int i);
	void TurnToBoilerWait(int i);
	void MoveToBoiler(int i);
	void ShootFuel(int i);

	void AdjustOnWall(int i);
	void ClearBoiler(int i);
	void TurnToFront(int i);
	void TurnToFrontWait(int i);

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
	Shooter &a_Shooter;

	bool  a_NeedsToRun[10] = {true};

	float a_BaselineDistances[5] = {32.308, 105.953, 105.953, 32.308, 93.33};
	float a_PegAngles[5] = {60,-60, 60, -60, 0};
	float a_PegDistances[5] = {78.98, 19.39, 19.39, 78.98, 0};
	float a_ShieldsDistances[5] = {0, 19.39, 19.39, 0, 0};
	float a_BoilerAngles[5] = {0, -30+24.55, 30-24.55, 0, 27.97};
	float a_BoilerDistances[5] = {0, 182.83, 182.83, 0, 156.259};
	float a_WallDistances[5] = {1.25, 0, 0, 1.25, 0};
	float a_FrontAngles[5] = {45, 0, 0, -45, 0};

/*	float a_AutoInfo[8][5] = {{32.308, 105.953, 105.953, 32.308, 93.33},
						      {60,-60, 60, -60, 0},
	                          {78.98, 19.39, 19.39, 78.98, 0},
	                          {0, 19.39, 19.39, 0, 0},
	                          {0, -30+24.55, 30-24.55, 0, 27.97},
	                          {0, 182.83, 182.83, 0, 182.83},
	                          {1.25, 0, 0, 1.25, 0},
	                          {45, 0, 0, -45, 0}};*/

	BotPosition a_BotPosition;
	float driveDistance;

};

#endif
