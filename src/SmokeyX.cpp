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
		a_KylesSoul(BUTTON_BOX_PORT),
		a_PDP(PDP_PORT),
		a_Compressor(PCM_PORT),
		a_FrontRight(FRONT_RIGHT_TURN, FRONT_RIGHT_MOVE),
		a_FrontLeft(FRONT_LEFT_TURN, FRONT_LEFT_MOVE),
		a_BackLeft(BACK_LEFT_TURN, BACK_LEFT_MOVE),
		a_BackRight(BACK_RIGHT_TURN, BACK_RIGHT_MOVE),
		a_Drive(a_FrontRight, a_FrontLeft, a_BackLeft, a_BackRight, CHASSIS_LENGTH, CHASSIS_WIDTH),
		a_Shooter(SHOOTER),
		a_Collector(COLLECTOR_ONE, COLLECTOR_TWO),
		a_Impeller(IMPELLER_PORT),
		a_Lifter(CLIMBER_PORT),
		a_LRC(),
		a_Accelerometer(I2C::kMXP,ADXL345_I2C::kRange_2G,0x53), // was 0x1D
		a_Gyro(I2C::kMXP),
		a_MQTT("RIOclient", "localhost", 1183)
		// a_Ultrasonic(9600,SerialPort::kOnboard,8,SerialPort::kParity_None, SerialPort::kStopBits_One)
{
	rc = 0;
	mosqpp::lib_init();
	tState = 0;
	SmartDashboard::init();
	a_Drive.Init();

	a_BackRight.InvertDriveMotor();
	a_FrontRight.InvertDriveMotor();

	a_FrontRight.InvertTurnMotor(); // PRACT

}

void SmokeyX::RobotInit()
{
	a_Gyro.Cal();
}

void SmokeyX::RobotPeriodic()
{
	// a_Gyro.Update();
	rc = a_MQTT.loop();
	if(rc){
		a_MQTT.reconnect();
	}
}

void SmokeyX::DisabledInit()
{

}

void SmokeyX::DisabledPeriodic()
{
	a_LRC.SetColor(0,0,0,0);
	a_LRC.SetColor(1,0,0,0);
	a_LRC.SetColor(2,0,0,0);
	a_Gyro.Update();
	SmartDashboard::PutNumber("Gyro, yum", a_Gyro.GetAngle());
	SmartDashboard::PutNumber("Front Right Speed", a_FrontRight.GetSpeed());
	SmartDashboard::PutNumber("Front Left Speed", a_FrontLeft.GetSpeed());
	SmartDashboard::PutNumber("Back Right Speed", a_BackRight.GetSpeed());
	SmartDashboard::PutNumber("Back Left Speed", a_BackLeft.GetSpeed());

	SmartDashboard::PutNumber("Front Right Angle", a_FrontRight.GetAngle());
	SmartDashboard::PutNumber("Front Left Angle", a_FrontLeft.GetAngle());
	SmartDashboard::PutNumber("Back Right Angle", a_BackRight.GetAngle());
	SmartDashboard::PutNumber("Back Left Angle", a_BackLeft.GetAngle());
	// SmartDashboard::PutNumber("ShooterSpeed", a_Shooter.GetSpeed());

	/*
	char buffer[32];
	a_Ultrasonic.Read(buffer,6);
	SmartDashboard::PutString("Ultrasonic", buffer);
	printf("Ultrasonic:: %s\n", buffer);
	*/

	// SmartDashboard::PutNumber("a_Ultrasonic", a_Ultrasonic.GetDistanceIn()); // will test monday

	SmartDashboard::PutNumber("Vision Distance:", a_MQTT.GetDistance());
}

void SmokeyX::AutonomousInit()
{
	// a_Gyro.Cal();
	tState = 0;
}

void SmokeyX::AutonomousPeriodic()
{

}

void SmokeyX::TeleopInit()
{
	a_Gyro.Cal();
}

void SmokeyX::TeleopPeriodic()
{
	a_Accelerometer.GetAccelerations();
	SmartDashboard::PutNumber("Accelerometer X", a_Accelerometer.GetX());
	SmartDashboard::PutNumber("Accelerometer Y", a_Accelerometer.GetY());
	SmartDashboard::PutNumber("Accelerometer Z", a_Accelerometer.GetZ());
	a_LRC.SetColor(0,0,100,0);
	a_LRC.SetColor(1,0,100,0);
	a_LRC.SetColor(2,0,100,0);

	if(a_KylesSoul.GetRawButton(5) && a_Joystick2.GetRawButton(1) && a_Joystick2.GetRawAxis(2) >= .9) {
		a_Shooter.Set(0);
		a_Collector.Update(0);
		a_Lifter.Set(1);
		a_Joystick2.SetRumble(GenericHID::RumbleType::kLeftRumble, 1);
		a_Joystick2.SetRumble(GenericHID::RumbleType::kRightRumble, 1);
	} else {
		a_Shooter.Set(0.75);
		a_Collector.Update(-1);
		a_Lifter.Set(0);
		a_Joystick2.SetRumble(GenericHID::RumbleType::kLeftRumble, 0);
		a_Joystick2.SetRumble(GenericHID::RumbleType::kRightRumble, 0);
	}

	a_Impeller.Update();
	if(a_Joystick2.GetRawAxis(3)) {
		a_Impeller.Set(-1);
	} else {
		a_Impeller.Set(0);
	}

	if(a_Joystick.GetRawButton(1)) {
		a_Gyro.Cal();
	}

	SmartDashboard::PutNumber("ImpellerTheo", -260 / 2);
	SmartDashboard::PutNumber("ImpellerSpeed", a_Impeller.GetSpeed());

	SmartDashboard::PutNumber("ShooterTheo", 0.5  * 4500);
	SmartDashboard::PutNumber("ShooterSpeed", a_Shooter.GetSpeed());

	a_Gyro.Update();

	SmartDashboard::PutNumber("Gyro, yum", a_Gyro.GetAngle());

	a_Drive.Update(a_Joystick.GetX(),a_Joystick.GetY(),a_Joystick.GetZ(), 0);

	SmartDashboard::PutNumber("Drive distance X", a_Drive.GetDistanceX());
	SmartDashboard::PutNumber("Drive distance Y", a_Drive.GetDistanceY());

	SmartDashboard::PutNumber("Front Right Angle", a_FrontRight.GetAngle());
	SmartDashboard::PutNumber("Front Left Angle", a_FrontLeft.GetAngle());
	SmartDashboard::PutNumber("Back Right Angle", a_BackRight.GetAngle());
	SmartDashboard::PutNumber("Back Left Angle", a_BackLeft.GetAngle());

	SmartDashboard::PutNumber("Front Right Speed", a_FrontRight.GetSpeed());
	SmartDashboard::PutNumber("Front Left Speed", a_FrontLeft.GetSpeed());
	SmartDashboard::PutNumber("Back Right Speed", a_BackRight.GetSpeed());
	SmartDashboard::PutNumber("Back Left Speed", a_BackLeft.GetSpeed());

	SmartDashboard::PutNumber("Vision Distance:", a_MQTT.GetDistance());
}


void SmokeyX::TestInit()
{

}

void SmokeyX::TestPeriodic()
{

}

START_ROBOT_CLASS(SmokeyX);
