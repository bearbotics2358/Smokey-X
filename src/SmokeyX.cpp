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
		a_Collector(COLLECTOR_ONE, COLLECTOR_TWO),
		a_Impeller(IMPELLER_PORT),
		a_Gyro(I2C::kOnboard),
		a_Shooter(SHOOTER, 21)
{
	tState = 0;
	SmartDashboard::init();
	a_Drive.Init();
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

	/*
	SmartDashboard::PutNumber("Front Right Speed", a_FrontRight.GetSpeed());
	SmartDashboard::PutNumber("Front Left Speed", a_FrontLeft.GetSpeed());
	SmartDashboard::PutNumber("Back Right Speed", a_BackRight.GetSpeed());
	SmartDashboard::PutNumber("Back Left Speed", a_BackLeft.GetSpeed());

	SmartDashboard::PutNumber("Front Right Angle", a_FrontRight.GetAngle());
	SmartDashboard::PutNumber("Front Left Angle", a_FrontLeft.GetAngle());
	SmartDashboard::PutNumber("Back Right Angle", a_BackRight.GetAngle());
	SmartDashboard::PutNumber("Back Left Angle", a_BackLeft.GetAngle());
	*/

}

void SmokeyX::AutonomousInit()
{
	// a_Gyro.Cal();
	tState = 0;
}

void SmokeyX::AutonomousPeriodic()
{
	// AutoState nextState = a_AutoState;

/*  float driveDistance = a_Drive.GetDistance; // already converts to inches
	// SmartDashboard::PutNumber("Drive Distance", driveDistance);

	const double BASELINE_DISTANCE = 93.3 - CHASSIS_WIDTH;
	// double pegDistance = 31.11;
	// double pegAngle[] = {25.42,27.89,57.996}; // left, right, middle, Goal on left
	// double shieldsDistance = 20; // only for middle

	a_Gyro.Update();
	float gyroValue = a_Gyro.GetAngle();
	SmartDashboard::PutNumber("Gyro, yum", gyroValue);

	switch (a_AutoState) {
		case kMoveToBaseline:
			if (driveDistance < BASELINE_DISTANCE) {
				a_Drive.Set(.5,0,0);
			} else {
				// AutonUpdate?
				nextState = kTurnToPeg;
			}
			break;
		case kTurnToPeg:
			int angleSelection;
			switch (a_BotPosition){
				case kBlueLeft:
					SetTwistingRelAngle(a_Gyro.GetAngle(),25.42);
					break;
				case kBlueRight:
					SetTwistingRelAngle(a_Gyro.GetAngle(),27.89);
					break;
				case kRedLeft:
					SetTwistingRelAngle(a_Gyro.GetAngle(),27.89);
					break;
				case kRedLeft:
					SetTwistingRelAngle(a_Gyro.GetAngle(),25.42);
					break;
			}
			if(position = left){
				SetTwistingRelAngle(a_Gyro.GetAngle(),kLeftTwistAngle);
				// angleSelection = 0;
			}else if(position = mid){
				SetTwistingRelAngle(a_Gyro.GetAngle(),kMiddleTwistAngle);
				// angleSelection = 1;
			}else if(position = right){
				SetTwistingRelAngle(a_Gyro.GetAngle(),kRightTwistAngle);
				// angleSelection = 2;
			}
			if(goalSide = right){
				if(position = left){
					SetTwistingRelAngle(a_Gyro.GetAngle(),kRightTwistAngle);
					// angleSelection = 2;
				}else if(position = mid){
					SetTwistingRelAngle(a_Gyro.GetAngle(),kMiddleTwistAngle);
					// angleSelection = 1;
				}else if(position = right){
					SetTwistingRelAngle(a_Gyro.GetAngle(),kLeftTwistAngle);
					// angleSelection = 0;
				}
			}
			// TurnToAngle pegAngle[angleSelection];
			nextState = kMoveToPeg;
			break;
		case kMoveToPeg:
			if (position = mid){
				pegDistance=0;
			}
			if (driveDistance < pegDistance) {
				a_Drive.Set(.5,0,0);
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
			if (driveDistance < pegDistance) {
				a_Drive.set(-.5,0,0);
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
			if (driveDistance < SHOOTING_DISTANCE) {
				a_Drive.set(0.5,0,0);
			} else {
				// AutonUpdate
				nextState = kAutoIdle;
			}
			break;
		case kAutoIdle:
			// AutonUpdate
			// ResetEncoders
			break;
		}*/

	// a_AutoState = nextState;
}



void SmokeyX::TeleopInit()
{
	// a_Gyro.Cal();
	// a_Gyro.Zero();

}

void SmokeyX::TeleopPeriodic()
{
	a_Shooter.Set(a_Joystick2.GetY(),0,0);
	SmartDashboard::PutNumber("Shooter", a_Joystick2.GetY()  * 4500);
	SmartDashboard::PutNumber("Speed", a_Shooter.GetSpeed());

	a_Gyro.Update();
	SmartDashboard::PutNumber("Gyro, yum", a_Gyro.GetAngle());

	// a_Drive.Update(a_Joystick.GetX(), a_Joystick.GetY(), a_Joystick.GetZ() , a_Gyro.GetAngle());


	// a_Collector.Update(2*a_Joystick.GetMagnitude()*4248*4/1.25,2*a_Joystick.GetMagnitude()*4248*4/1.25); // Setting the collector tangential velocity to twice as fast as the theoretical linear velocity of the robot

	a_Collector.Update(a_Joystick.GetY(),a_Joystick.GetY());
	/*
	SmartDashboard::PutNumber("Front Right", a_FrontRight.GetSpeed());
	SmartDashboard::PutNumber("Front Left", a_FrontLeft.GetSpeed());
	SmartDashboard::PutNumber("Back Right", a_BackRight.GetSpeed());
	SmartDashboard::PutNumber("Back Left", a_BackLeft.GetSpeed());


	SmartDashboard::PutNumber("Front Right Angle", a_FrontRight.GetAngle());
	SmartDashboard::PutNumber("Front Left Angle", a_FrontLeft.GetAngle());
	SmartDashboard::PutNumber("Back Right Angle", a_BackRight.GetAngle());
	SmartDashboard::PutNumber("Back Left Angle", a_BackLeft.GetAngle());
	*/

}

void SmokeyX::TestInit()
{

}

void SmokeyX::TestPeriodic()
{


}

START_ROBOT_CLASS(SmokeyX);

