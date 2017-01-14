/*
 * SwerveAPult.h
 *
 *  Created on: Oct 25, 2016
 *      Author: Teacher
 */

#ifndef SRC_SMOKEYX_H_
#define SRC_SMOKEYX_H_

#include <WPILib.h>
#include <SerialPort.h>
#include <IterativeRobot.h>

#include "JrimmyGyro.h"
#include "Roller.h"
#include "SwerveModule.h"
#include "SwerveDrive.h"
#include "SmartDashboard/SmartDashboard.h"
#include "SmartDashboard/SendableChooser.h"

enum AutoState {
	kMoveToBaseline=0,
	kTurnToPeg,
	kMoveToPeg,
	kScoreGear,
	kClearShields,
	kTurnToBoiler,
	kMoveToShootingDistance,
	kAutoIdle
};

class SmokeyX : public IterativeRobot {
public:
	SmokeyX(void);
	void RobotInit(void);
	void DisabledInit(void);
	void DisabledPeriodic(void);
	void TeleopInit(void);
	void TeleopPeriodic(void);
	void TestInit(void);
	void TestPeriodic(void);
	void AutonomousInit(void);
	void AutonomousPeriodicFull(void);
	void AutonomousPeriodic(void);
	void AutonomousPeriodicSimple(void);

private:

	Joystick a_Joystick;
	Joystick a_Joystick2;

	PowerDistributionPanel a_PDP;

	Compressor a_Compressor;

	SwerveModule a_FrontRight;
	SwerveModule a_FrontLeft;
	SwerveModule a_BackLeft;
	SwerveModule a_BackRight;

	SwerveDrive a_Drive;

	Roller a_Roller;

	JrimmyGyro a_Gyro;

	AutoState a_AutoState;

	double tState;

};




#endif
