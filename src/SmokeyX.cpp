#include <iostream>
#include <memory>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "SmokeyX.h"

SmokeyX::SmokeyX(void):
		a_Joystick(JOYSTICK_PORT),
		a_Joystick2(JOYSTICKTWO_PORT),
		a_PDP(PDP_PORT),
		a_Compressor(PCM_PORT),
		a_FrontRight(FRONT_RIGHT_TURN, FRONT_RIGHT_MOVE),
		a_FrontLeft(FRONT_LEFT_TURN, FRONT_LEFT_MOVE),
		a_BackLeft(BACK_LEFT_TURN, BACK_LEFT_MOVE),
		a_BackRight(BACK_RIGHT_TURN, BACK_RIGHT_MOVE),
		a_Drive(a_FrontRight, a_FrontLeft, a_BackLeft, a_BackRight, CHASSIS_LENGTH, CHASSIS_WIDTH),
		a_Roller(ROLLER, ROLLER_SWITCH_PORT),
		a_Gyro(I2C::kMXP), // Didn't work because we used smartdashboard in the constructor- wait to use it until after RobotInit()
		a_AutoState(kAutoIdle)
{
	tState = 0;
	SmartDashboard::init();
	a_Drive.Init();
	a_Gyro.Cal();
	// a_BackLeft.InvertDriveMotor();
	// a_BackRight.InvertDriveMotor();
	// a_FrontRight.InvertDriveMotor();
	// a_FrontLeft.InvertDriveMotor();
	// a_BackLeft.SetDrivePID(2,0,0);
}

void SmokeyX::RobotInit()
{

}

void SmokeyX::DisabledInit()
{


}

void SmokeyX::DisabledPeriodic()
{
	SmartDashboard::PutNumber("Front Right Speed", a_FrontRight.GetSpeed());
	SmartDashboard::PutNumber("Front Left Speed", a_FrontLeft.GetSpeed());
	SmartDashboard::PutNumber("Back Right Speed", a_BackRight.GetSpeed());
	SmartDashboard::PutNumber("Back Left Speed", a_BackLeft.GetSpeed());

	SmartDashboard::PutNumber("Front Right Angle", a_FrontRight.GetAngle());
	SmartDashboard::PutNumber("Front Left Angle", a_FrontLeft.GetAngle());
	SmartDashboard::PutNumber("Back Right Angle", a_BackRight.GetAngle());
	SmartDashboard::PutNumber("Back Left Angle", a_BackLeft.GetAngle());
}

void SmokeyX::AutonomousInit()
{
	a_Gyro.Cal();
	a_AutoState = kMoveToBaseline;
	//a_Tank.Enable();
	//a_Left.ResetEncoder();
	//a_Right.ResetEncoder();
	tState = 0;
	//a_TargetDetector.TurnLRCBright();
	//a_TargetDetector.StartProcessing();
}

void SmokeyX::AutonomousPeriodic()
{
	AutoState nextState = a_AutoState;

	// float chasisDistance = getDistance; //getDistance() already converts to inches
	// SmartDashboard::PutNumber("Chasis Distance", chasisDistance);

	const double BASELINE_DISTANCE = 93.3 - CHASSIS_WIDTH;
	double pegDistance = 31.11;
	double pegAngle[] = {25.42,27.89,57.996}; //left, right, middle, Goal on left
	// double shieldsDistance = 20; // only for middle

	/*
	switch (a_AutoState) {
		case kMoveToBaseline:
			if (chasisDistance < BASELINE_DISTANCE) {
				// DriveStraightForwardTo BASELINE_DISTANCE
			} else {
				// AutonUpdate?
				nextState = kTurnToPeg;
			}
			break;
		case kTurnToPeg:
			int angleSelection;
			if(position = left){
				angleSelection = 0;
			}else if(position = mid){
				angleSelection = 1;
			}else if(position = right){
				angleSelection = 2;
			}
			if(goalSide = right){
				if(position = left){
					angleSelection = 2;
				}else if(position = mid){
					angleSelection = 1;
				}else if(position = right){
					angleSelection = 0;
				}
			}
			TurnToAngle pegAngle[angleSelection];
			nextState = kMoveToPeg;
			break;
		case kMoveToPeg:
			if (position = mid){
				pegDistance=0;
			}
			if (chasisDistance < pegDistance) {
				// DriveStraightForwardTo pegDistance
			} else {
				// AutonUpdate
				nextState = kScoreGear;
			}
			break;
		case kScoreGear:
			// ScoreGear
			nextState = kClearShields;
			break;
		case kClearShields:
			if (position = mid){
				pegDistance = 20;
			}
			if (chasisDistance < pegDistance) {
				// DriveStraightBackwardTo pegDistance
			} else {
				// AutonUpdate
				nextState = kTurnToBoiler;
			}
			break;
		case kTurnToBoiler:
			int angleSelection;
			if(position = left){
				angleSelection = 0;
			}else if(position = mid){
				angleSelection = 1;
			}else if(position = right){
				angleSelection = 2;
			}
			if(goalSide = right){
				if(position = left){
					angleSelection = 2;
				}else if(position = mid){
					angleSelection = 1;
				}else if(position = right){
					angleSelection = 0;
				}
			}
			TurnToAngle pegAngle;
			TurnToAngle BOILER_ANGLE
			nextState = kMoveToShootingDistance;
			break;
		case kMoveToShootingDistance:
			if (chasisDistance < SHOOTING_DISTANCE) {
				// DriveStraightTo SHOOTING_DISTANCE
			} else {
				// AutonUpdate
				nextState = kAutoIdle;
			}
			break;
		case kAutoIdle:
			// AutonUpdate
			// ResetEncoders
			break;
		}
	 */
	a_AutoState = nextState;
}



void SmokeyX::TeleopInit()
{
	a_Gyro.Cal();
	a_Gyro.Zero();

}

void SmokeyX::TeleopPeriodic()
{

	a_Gyro.Update();

	a_Drive.Update(a_Joystick.GetX(), a_Joystick.GetY(), a_Joystick.GetZ() , a_Gyro.GetAngle());



	if(a_Joystick.GetRawButton(8)) {
		a_Roller.Update(0.25);
	} else if(a_Joystick.GetRawButton(1)) {
		a_Roller.Update(-0.5);
	} else {
		a_Roller.Update(0);
	}

	SmartDashboard::PutNumber("Gyro, yum", a_Gyro.GetAngle());
	SmartDashboard::PutNumber("Front Right", a_FrontRight.GetSpeed());
	SmartDashboard::PutNumber("Front Left", a_FrontLeft.GetSpeed());
	SmartDashboard::PutNumber("Back Right", a_BackRight.GetSpeed());
	SmartDashboard::PutNumber("Back Left", a_BackLeft.GetSpeed());


	SmartDashboard::PutNumber("Front Right Angle", a_FrontRight.GetAngle());
	SmartDashboard::PutNumber("Front Left Angle", a_FrontLeft.GetAngle());
	SmartDashboard::PutNumber("Back Right Angle", a_BackRight.GetAngle());
	SmartDashboard::PutNumber("Back Left Angle", a_BackLeft.GetAngle());

}

void SmokeyX::TestInit()
{

}

void SmokeyX::TestPeriodic()
{


}

START_ROBOT_CLASS(SmokeyX);

