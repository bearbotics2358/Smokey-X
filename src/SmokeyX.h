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
#include "SwerveModule.h"
#include "SwerveDrive.h"
#include "SmartDashboard/SmartDashboard.h"
#include "SmartDashboard/SendableChooser.h"
#include "Collector.h"
#include "Impeller.h"
#include "Shooter.h"
#include "LightRingController.h"

/*enum AutoState {
	kMoveToBaseline=0,
	kTurnToPeg,
	kMoveToPeg,
	kScoreGear,
	kClearShields,
	kTurnToBoiler,
	kMoveToShootingDistance,
	kAutoIdle
};

enum BotPosition {
	kBlueLeft=0,
	kBlueRight,
	kRedLeft,
	kRedRight,
	kMiddle
};*/

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

	Collector a_Collector;

	Impeller a_Impeller;

	LightRingController a_LRC;

	ADXL345_I2C a_Accelerometer;

	JrimmyGyro a_Gyro;

	Shooter a_Shooter;

	// AutoState a_AutoState;

	// BotPosition a_BotPosition;

	double tState;

};




#endif
