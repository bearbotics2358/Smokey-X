#include "Autonomous.h"

Autonomous::Autonomous(Joystick &buttonBox, SwerveDrive &Drive, JrimmyGyro &Gyro)
: a_ButtonBox(buttonBox),
  a_Drive(Drive),
  a_Gyro(Gyro),
  a_BotPosition(kMiddle)
{
	driveDistance = 0;
}

// float baselineDistance = 93.3;

void Autonomous::MoveToBaseline(){
	driveDistance = a_Drive.GetDistance();
	switch (a_BotPosition){
	case kBlueLeft:
		if (driveDistance < 32.308) {
			a_Drive.Update(.5,0,0,0);
		}
		break;
	case kBlueRight:
		if (driveDistance < 105.953) {
			a_Drive.Update(.5,0,0,0);
		}
		break;
	case kRedLeft:
		if (driveDistance < 105.953) {
			a_Drive.Update(.5,0,0,0);
		}
		break;
	case kRedRight:
		if (driveDistance < 32.308) {
			a_Drive.Update(.5,0,0,0);
		}
		break;
	case kMiddle:
		if (driveDistance < 93.33) {
			a_Drive.Update(.5,0,0,0);
		}
		break;
	}
}

void Autonomous::TurnToPeg(){
	switch (a_BotPosition){
	case kBlueLeft:
		a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),60);
		break;
	case kBlueRight:
		a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),-60);
		break;
	case kRedLeft:
		a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),60);
		break;
	case kRedRight:
		a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),-60);
		break;
	default:
		break;
	}
}

void Autonomous::MoveToPeg(){
	driveDistance = a_Drive.GetDistance();
	switch (a_BotPosition){
	case kBlueLeft:
		if (driveDistance < 78.98) {
			a_Drive.Update(.5,0,0,0);
		}
		break;
	case kBlueRight:
		if (driveDistance < 19.39) {
			a_Drive.Update(.5,0,0,0);
		}
		break;
	case kRedLeft:
		if (driveDistance < 19.39) {
			a_Drive.Update(.5,0,0,0);
		}
		break;
	case kRedRight:
		if (driveDistance < 78.98) {
			a_Drive.Update(.5,0,0,0);
		}
		break;
	default:
		break;
	}
}

void Autonomous::ScoreGear(){
// ???
}

void Autonomous::ClearShields(){
	driveDistance = a_Drive.GetDistance();
	switch (a_BotPosition){
	case kBlueRight:
		if (driveDistance < 19.39) {
			a_Drive.Update(-.5,0,0,0);
		}
		break;
	case kRedLeft:
		if (driveDistance < 19.39) {
			a_Drive.Update(-.5,0,0,0);
		}
		break;
	default:
		break;
	}
}

void Autonomous::TurnToBoiler(){
	switch (a_BotPosition){
	case kBlueRight:
		a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),-30+24.55);
		break;
	case kRedLeft:
		a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),30+24.55);
		break;
	case kMiddle:
		a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),27.97);
		break;
	default:
		break;
	}
}

void Autonomous::MoveToBoiler(){
	driveDistance = a_Drive.GetDistance();
	switch (a_BotPosition){
	case kBlueRight:
		if (driveDistance < 182.83) {
			a_Drive.Update(.5,0,0,0);
		}
		break;
	case kRedLeft:
		if (driveDistance < 182.83) {
			a_Drive.Update(.5,0,0,0);
		}
		break;
	case kMiddle:
		if(driveDistance < 182.83){
			a_Drive.Update(.5,0,0,0);
		}
		break;
	default:
		break;
	}
}

void Autonomous::ShootFuel(){
// ???
}

void Autonomous::AdjustOnWall(){
	driveDistance = a_Drive.GetDistance();
	switch(a_BotPosition){
	case kBlueLeft:
		if (driveDistance < 1.25) {
			a_Drive.Update(0,.5,0,0);
		}
		break;
	case kRedRight:
		if (driveDistance < 1.25) {
			a_Drive.Update(0,-.5,0,0);
		}
		break;
	default:
		break;
	}
}

void Autonomous::ClearBoiler(){
	if (driveDistance < 10) {
		a_Drive.Update(.5,0,0,0);
	}
}

void Autonomous::TurnToFront(){
	switch(a_BotPosition){
	case kBlueLeft:
		a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),45);
		break;
	case kRedRight:
		a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),-45);
		break;
	default:
		break;
	}
}
// -------------------------------------------------------

void Autonomous::BlueLeft(){
	a_BotPosition = kBlueLeft;
	AdjustOnWall();
	ShootFuel();
	ClearBoiler();
	TurnToFront();
	MoveToBaseline();
	TurnToPeg();
	MoveToPeg();
	ScoreGear();
}

void Autonomous::BlueRight(){
	a_BotPosition = kBlueRight;
	MoveToBaseline();
	TurnToPeg();
	MoveToPeg();
	ScoreGear();
	ClearShields();
	TurnToBoiler();
	MoveToBoiler();
	ShootFuel();
}

void Autonomous::BlueMiddle(){
	a_BotPosition = kMiddle;
	MoveToBaseline();
	ScoreGear();
	ClearShields();
	TurnToBoiler();
	MoveToBoiler();
	ShootFuel();
}

void Autonomous::RedLeft(){
	a_BotPosition = kRedLeft;
	AdjustOnWall();
	ShootFuel();
	ClearBoiler();
	TurnToFront();
	MoveToBaseline();
	TurnToPeg();
	MoveToPeg();
	ScoreGear();
}

void Autonomous::RedRight(){
	a_BotPosition = kRedRight;
	AdjustOnWall();
	ShootFuel();
	ClearBoiler();
	TurnToFront();
	TurnToPeg();
	MoveToPeg();
	ScoreGear();
}

void Autonomous::RedMiddle(){
	a_BotPosition = kMiddle;
	MoveToBaseline();
	ScoreGear();
	ClearShields();
	TurnToBoiler();
	MoveToBoiler();
	ShootFuel();
}

/**
 *
---------------------------------------------------------------------------------------------------------------
void driveForward(float distance){
	if (driveDistance < distance) {
		a_Drive.Update(.5,0,0,0);
	}
}

void driveBackward(float distance){
	if (driveDistance < distance) {
		a_Drive.Update(-.5,0,0,0);
	}
}

void driveRight(float distance){
	if (driveDistance < distance) {
		a_Drive.Update(0,.5,0,0);
	}
}

void driveLeft(float distance){
	if (driveDistance < distance) {
		a_Drive.Update(0,-.5,0,0);
	}
}

void turnRight(float angle){
	SetTwistingRelAngle(a_Gyro.GetAngle(),angle);
}

void turnLeft(float angle){
	SetTwistingRelAngle(a_Gyro.GetAngle(),-angle);
}

void Autonomous::Left(){
	driveRight(1.25); // driveLeft(1.25);
	ShootFuel();
	driveBackward(10);
	turnRight(45); // turnRight(45);
	driveForward(32.308);
	turnRight(60); // turnLeft(60);
	driveForward(78.98);
	ScoreGear();
}

void Autonomous::Right(){
	driveForward(105.953);
	turnLeft(60); // turnRight(60);
	driveForward(19.39);
	ScoreGear();
	driveBackward(19.39);
	turnLeft(30+24.55); // turnLeft(30+24.55);
	driveForward(182.83-10);
	turnLeft(45-24.55); // turnRight(45-24.55);
    // driveForward(28.28-???);
	ShootFuel();
}

void Autonomous::Middle(){
	driveForward(93.3);
	ScoreGear();
	driveBackward(20);
	turnLeft(27.97); // turnRight(27.97);
	driveForward(156.259);
	ShootFuel();
}

---------------------------------------------------------------

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
}
*/
