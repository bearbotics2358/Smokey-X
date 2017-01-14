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
		a_Gyro(I2C::kMXP) // Didn't work because we used smartdashboard in the constructor- wait to use it until after RobotInit()
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

}

void SmokeyX::AutonomousPeriodic() {

}



void SmokeyX::TeleopInit()
{
	a_Gyro.Cal();
	a_Gyro.Zero();

}

void SmokeyX::TeleopPeriodic()
{

	a_Gyro.Update();

	a_Drive.Update(a_Joystick, a_Gyro.GetAngle());



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

