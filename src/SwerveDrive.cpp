/*
 * SwerveDrive.cpp
 *
 *  Created on: Mar 22, 2016
 *      Author: hstechclub
 */

#include "SwerveDrive.h"
#include "Joystick.h"
#include "SmokeyX.h"
#include "SmartDashboard/SmartDashboard.h"
#include "SmartDashboard/SendableChooser.h"
#include "SmartDashboard/NamedSendable.h"
#include "SmartDashboard/SendableChooser.inc"
#include "SmartDashboard/SendableChooserBase.h"
#include "SmartDashboard/Sendable.h"

const std::string SwerveDrive::CONTROL_TYPE_KEY = "Drive Scheme";

const int         SwerveDrive::CONTROL_TYPE_SWERVE = 0;
const std::string SwerveDrive::CONTROL_TYPE_SWERVE_KEY = "Swerve Drive";
const int         SwerveDrive::CONTROL_TYPE_CRAB   = 1;
const std::string SwerveDrive::CONTROL_TYPE_CRAB_KEY   = "Crab Drive";

SwerveDrive::SwerveDrive(SwerveModule &FR, SwerveModule &FL, SwerveModule &BL, SwerveModule &BR, float Length, float Width)
: a_FrontRight(FR),
  a_FrontLeft(FL),
  a_BackLeft(BL),
  a_BackRight(BR)
{
	a_RobotLength = Length;
	a_RobotWidth = Width;
	a_ChassisRadius = sqrt(pow(a_RobotLength, 2) + pow(a_RobotWidth, 2));
	a_ControlTypeChooser.AddDefault(CONTROL_TYPE_SWERVE_KEY, CONTROL_TYPE_SWERVE_KEY);
	a_ControlTypeChooser.AddObject(CONTROL_TYPE_CRAB_KEY, CONTROL_TYPE_CRAB_KEY);
}

void SwerveDrive::Init()
{
	// FR 165.25 FL 254.18 BR 194.766 BL 279.85
	InitSendableChooser(); // please, please, PLEASE call this first- otherwise our drive mode might not initialize properly, or a function you attempt to call may not work
	a_FrontRight.Set(0,0,0);
	a_FrontLeft.Set(0,0,0);
	a_BackLeft.Set(0,0,0);
	a_BackRight.Set(0,0,0);
}

void SwerveDrive::InitSendableChooser()
{


	SmartDashboard::PutData(CONTROL_TYPE_KEY, &a_ControlTypeChooser);
}

void SwerveDrive::Update(float xIn, float yIn, float zIn, float gyroValue)
{
	float zInput = zIn; // Rotation Clockwise
	float xInput = xIn; // Strafe
	float yInput = - 1 * yIn; // Forward

	float temp = yInput * cos(gyroValue * M_PI / 180) + xInput * sin(gyroValue * M_PI / 180); // This block of commands SHOULD make this thing field oriented
	xInput = -yInput * sin(gyroValue * M_PI / 180) + xInput * cos(gyroValue * M_PI / 180);
	yInput = temp;

	std::string controlType;

	controlType = a_ControlTypeChooser.GetSelected();

	if (controlType == "")
	{
		std::cout << "error reading control type" << std::endl;
		return;
	}

	float A = xInput - zInput * (a_RobotLength / a_ChassisRadius);
	float B = xInput + zInput * (a_RobotLength / a_ChassisRadius);
	float C = yInput - zInput * (a_RobotWidth / a_ChassisRadius);
	float D = yInput + zInput * (a_RobotWidth / a_ChassisRadius);

	float max = -9 * pow(10,4);

	double frSpeed = 0.0;
	double frAngle = 0.0;

	double flSpeed = 0.0;
	double flAngle = 0.0;

	double blSpeed = 0.0;
	double blAngle = 0.0;

	double brSpeed = 0.0;
	double brAngle = 0.0;

	if(controlType == CONTROL_TYPE_SWERVE_KEY) {
		frSpeed = sqrt(pow(B,2) + pow(C,2));
				flSpeed = sqrt(pow(B,2) + pow(D,2));
				blSpeed = sqrt(pow(A,2) + pow(D,2));
				brSpeed = sqrt(pow(A,2) + pow(C,2));

				max = frSpeed;
				if(flSpeed > max) {
					max = flSpeed;
				}
				if(blSpeed > max) {
					max = blSpeed;
				}
				if(brSpeed > max) {
					max = brSpeed;
				}
				if(max > 1) { // This is done so that if a speed greater than 1 is calculated, all are reduced proportionally
					frSpeed /= max;
					flSpeed /= max;
					blSpeed /= max;
					brSpeed /= max;
				}

				//  atan2 outputs values in a manner similar to what is shown on the below diagram

						////////////////////
						//        90      //
						//        //      //
						//		  //      //
						//		  //      //
						//180 or - 180///0//
						//        //      //
						//        //      //
						//        //      //
						//       -90      //
						////////////////////

				frAngle = (atan2(C,B) * 180.0 / M_PI);
				flAngle = (atan2(D,B) * 180.0 / M_PI);
				blAngle = (atan2(D,A) * 180.0 / M_PI);
				brAngle = (atan2(C,A) * 180.0 / M_PI);


				// Subtract 90 from all

						////////////////////
						//        0	      //
						//        //      //
						//		  //      //
						//		  //      //
						//90 or - 270//-90//
						//        //      //
						//        //      //
						//        //      //
						//  	 -180     //
						////////////////////

				frAngle -= 90;
				flAngle -= 90;
				brAngle -= 90;
				blAngle -= 90;


				/*
				// Multiply all by -1

				        ////////////////////
					    //        0	      //
						//        //      //
						//		  //      //
						//		  //      //
						//-90 or 270///90///
						//        //      //
						//        //      //
						//        //      //
						//  	 180     //
						////////////////////

				frAngle *= -1.0;
				flAngle *= -1.0;
				brAngle *= -1.0;
				blAngle *= -1.0;

				// if theta < 0, add 360

		        ////////////////////
			    //    360 or 0    //
				//        //      //
				//		  //      //
				//		  //      //
				//270///////////90//
				//        //      //
				//        //      //
				//        //      //
				//  	 180     //
				////////////////////


				if(frAngle < 0) {
					frAngle +=360;
				}
				if(flAngle < 0) {
					flAngle += 360;
				}
				if(brAngle < 0) {
					brAngle += 360;
				}
				if(blAngle < 0) {
					blAngle += 360;
				}
				*/
	} else {

		float setAngle = atan2(yInput, xInput) * 180 / M_PI;
		setAngle -= 90;

		frAngle = setAngle;
		flAngle = setAngle;
		blAngle = setAngle;
		brAngle = setAngle;

		float setSpeed = sqrt(pow(xInput,2) + pow(yInput,2)); // find the r of the joystick vector, if you think about it in polar coordinates

		frSpeed = setSpeed;
		flSpeed = setSpeed;
		blSpeed = setSpeed;
		brSpeed = setSpeed;
	}

	SmartDashboard::PutNumber("Front Right Theoretical Speed", frSpeed);
	SmartDashboard::PutNumber("Front Left Theoretical Speed", flSpeed);
	SmartDashboard::PutNumber("Back Right Theoretical Speed", brSpeed);
	SmartDashboard::PutNumber("Back Left Theoretical Speed", blSpeed);

	SmartDashboard::PutNumber("Front Right Theoretical Angle", frAngle);
		SmartDashboard::PutNumber("Front Left Theoretical Angle", flAngle);
		SmartDashboard::PutNumber("Back Right Theoretical Angle", brAngle);
		SmartDashboard::PutNumber("Back Left Theoretical Angle", blAngle);

	// FR 165.25 FL 254.18 BR 194.766 BL 279.85
	a_FrontRight.Set(frAngle, frSpeed, -15 );
	a_FrontLeft.Set(flAngle, flSpeed, -105);
	a_BackLeft.Set(blAngle, blSpeed, -80);
	a_BackRight.Set(brAngle, brSpeed, 15);
}
