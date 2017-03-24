#ifndef SRC_AUTONOMOUS_H_
#define SRC_AUTONOMOUS_H_

#include <WPILib.h>
#include "Prefs.h"
#include "SwerveDrive.h"
#include "JrimmyGyro.h"
#include "GearFlicker.h"
#include "VisionSquitto.h"
// #include "Shooter.h"

enum BotPosition {
	/*	kBlueLeft=0,
	kBlueRight,
	kRedLeft,
	kRedRight,
	kMiddle,
	kStupidLeft*/
	kleft=0,
	kMiddle,
	kRight
};

class Autonomous {

public:
	Autonomous(Joystick &buttonBox, SwerveDrive &SwerveDrive, JrimmyGyro &Gyro, GearFlicker &Flicker, VisionSquitto &MQTT/*, Shooter &Shooter*/);
	virtual ~Autonomous() = default;
	void Init();
	void Update();
	void SetTimer(int i);
	void MoveToBaseline(int i);
	void TurnToPeg(int i);
	void TurnToPegWait(int i);
	void MoveToPeg(int i);
	void ScoreGear(int i);
	void MoveToPegWithVision(int i);

	/*	void ClearShields(int i);
	void TurnToBoiler(int i);
	void TurnToBoilerWait(int i);
	void MoveToBoiler(int i);
	void ShootFuel(int i);

	void AdjustOnWall(int i);
	void ClearBoiler(int i);
	void TurnToFront(int i);
	void TurnToFrontWait(int i);*/

	/*	void BlueLeft();
	void BlueRight();
	void BlueMiddle();
	void RedLeft();
	void RedRight();
	void RedMiddle();

	void StupidBlueLeft();
	void StupidBlueRight();
	void StupidBlueMiddle();
	void StupidRedLeft();
	void StupidRedRight();
	void StupidRedMiddle();

	void Stupid();*/

	void Left();
	void Middle();
	void Right();

private:
	Joystick &a_ButtonBox;
	SwerveDrive &a_Drive;
	JrimmyGyro &a_Gyro;
	GearFlicker &a_Flicker;
	VisionSquitto &a_MQTT;
	// Shooter &a_Shooter;

	bool  a_NeedsToRun[10] = {true};

	/*	float a_BaselineDistances[6] = {43.5-(CHASSIS_LENGTH_BUMPERS/2), 117.5-(CHASSIS_LENGTH_BUMPERS/2), 117.5-(CHASSIS_LENGTH_BUMPERS/2), 43-(CHASSIS_LENGTH_BUMPERS/2), 116-(CHASSIS_LENGTH_BUMPERS/2), 177.5-(CHASSIS_LENGTH_BUMPERS/2)};
	float a_PegAngles[6] = {60,-60, 60, -60, 0, 60};
	float a_PegDistances[6] = {118.5-(CHASSIS_LENGTH_BUMPERS/2), 28-(CHASSIS_LENGTH_BUMPERS/2), 27.25-(CHASSIS_LENGTH_BUMPERS/2), 117.5-(CHASSIS_LENGTH_BUMPERS/2), 0, 26-(CHASSIS_LENGTH_BUMPERS/2)};
	float a_ShieldsDistances[6] = {0, -60, -60, 0, 0, -60};
	float a_BoilerAngles[5] = {0, 45, -45, 0, 27.97};
	float a_BoilerDistances[5] = {0, 240-(CHASSIS_LENGTH_BUMPERS/2), 240-(CHASSIS_LENGTH_BUMPERS/2), 0, 156.259};
	float a_WallDistances[5] = {25-(CHASSIS_WIDTH_BUMPERS/2), 0, 0, 16-(CHASSIS_WIDTH_BUMPERS/2), 0};
	float a_FrontAngles[5] = {45, 0, 0, -45, 0};*/

	/*	float a_AutoInfo[8][5] = {{32.308, 105.953, 105.953, 32.308, 93.33},
						      {60,-60, 60, -60, 0},
	                          {78.98, 19.39, 19.39, 78.98, 0},
	                          {0, 19.39, 19.39, 0, 0},
	                          {0, -30+24.55, 30-24.55, 0, 27.97},
	                          {0, 182.83, 182.83, 0, 182.83},
	                          {1.25, 0, 0, 1.25, 0},
	                          {45, 0, 0, -45, 0}};*/

	float a_BaselineDistances[3] = {81.105-(CHASSIS_LENGTH_BUMPERS / 2),108-(CHASSIS_LENGTH_BUMPERS / 2), 81.105-(CHASSIS_LENGTH_BUMPERS / 2)};
	float a_PegAngles[3] = {60,0,-60};
	float a_PegDistances[3] = {74.87-(CHASSIS_LENGTH_BUMPERS/2),0, 74.87-(CHASSIS_LENGTH_BUMPERS/2)};

	BotPosition a_BotPosition;
	float driveDistance;
	float gyroAngle;
	float tState;

	bool side = false;
	bool level = false;
	bool leftPos = false;
	bool midPos = false;
	bool rightPos = false;
};

#endif
