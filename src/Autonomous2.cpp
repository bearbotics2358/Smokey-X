#include "Autonomous2.h"

Autonomous2::Autonomous2(Joystick &buttonBox, SwerveDrive &Drive, JrimmyGyro &Gyro, Shooter &Shooter)
: a_ButtonBox(buttonBox),
  a_Drive(Drive),
  a_Gyro(Gyro),
  a_Shooter(Shooter),
  a_BotPosition(kMiddle)
{
	driveDistance = 0;
}

void Autonomous2::Update(){
	bool side;
	// blue = true;
	// red = false;
	if(a_ButtonBox.GetRawButton(1)){
		side = true;
	}else{
		side = false;
	}
	if(a_ButtonBox.GetRawButton(2)&&side){
		Autonomous2::BlueLeft();
	}else if(!side){
		Autonomous2::RedLeft();
	}
	if(a_ButtonBox.GetRawButton(3)&&side){
		Autonomous2::BlueMiddle();
	}else if(!side){
		Autonomous2::RedMiddle();
	}
	if(a_ButtonBox.GetRawButton(4)&&side){
		Autonomous2::BlueRight();
	}else if(!side){
		Autonomous2::RedRight();
	}
}

void Autonomous2::MoveToBaseline(int i){
	driveDistance = a_Drive.GetDistanceX();
	if (driveDistance < a_BaselineDistances[a_BotPosition]) {
		a_Drive.Update(.5,0,0,0);
	} else {
		a_NeedsToRun[i] = false;
	}
}

void Autonomous2::MoveandTurnToPeg(int i){
	driveDistance = a_Drive.GetDistanceX();
	a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),a_PegAngles[a_BotPosition]);
	if ((driveDistance < a_BaselineDistances[a_BotPosition])&&(fabs(a_Gyro.GetAngle()) - fabs(a_PegAngles[a_BotPosition]) >3 )) {
		a_Drive.Update(.5,0,0,0);
		a_Drive.Update(0,0,0,a_Gyro.GetAngle());
	} else {
		a_NeedsToRun[i] = false;
	}
}

/*void Autonomous2::TurnToPeg(int i){
	a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),a_PegAngles[a_BotPosition]);
	a_NeedsToRun[i] = false;
}

void Autonomous2::TurnToPegWait(int i) {
	if(fabs(a_Gyro.GetAngle()) - fabs(a_PegAngles[a_BotPosition]) >3 ) {
		a_Drive.Update(0,0,0,a_Gyro.GetAngle());
	} else {
		a_NeedsToRun[i] = false;
	}
}

void Autonomous2::MoveToPeg(int i){
	driveDistance = a_Drive.GetDistanceX();
		if (driveDistance < a_PegDistances[a_BotPosition]) {
			a_Drive.Update(.5,0,0,0);
		} else {
			a_NeedsToRun[i] = false;
		}
}*/

void Autonomous2::ScoreGear(int i){
// ???
}

void Autonomous2::ClearShields(int i){
	driveDistance = a_Drive.GetDistanceY();
	if (driveDistance < a_ShieldsDistances[a_BotPosition]) {
		a_Drive.Update(-.5,0,0,0);
	} else {
		a_NeedsToRun[i] = false;
	}
}

void Autonomous2::MoveandTurnToBoiler(int i){
	driveDistance = a_Drive.GetDistanceY();
	a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),a_BoilerAngles[a_BotPosition]);
	if (driveDistance < a_BoilerDistances[a_BotPosition] && (fabs(a_Gyro.GetAngle()) - fabs(a_BoilerAngles[a_BotPosition]) >3 )) {
		a_Drive.Update(.5,0,0,0);
		a_Drive.Update(0,0,0,a_Gyro.GetAngle());
	} else {
		a_NeedsToRun[i] = false;
	}
}

/*void Autonomous2::TurnToBoiler(int i){
		a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),a_BoilerAngles[a_BotPosition]);
		a_NeedsToRun[i] = false;
}

void Autonomous2::TurnToBoilerWait(int i) {
	if(fabs(a_Gyro.GetAngle()) - fabs(a_BoilerAngles[a_BotPosition]) >3 ) {
		a_Drive.Update(0,0,0,a_Gyro.GetAngle());
	} else {
		a_NeedsToRun[i] = false;
	}
}

void Autonomous2::MoveToBoiler(int i){
	driveDistance = a_Drive.GetDistanceY();
	if (driveDistance < 0) {
		a_Drive.Update(.5,0,0,0);
	} else {
		a_NeedsToRun[i] = false;
	}
}*/

void Autonomous2::ShootFuel(int i){
	a_Shooter.Set(.5); // revised to follow adjustment
	a_NeedsToRun[i] = false;
}

void Autonomous2::AdjustOnWall(int i){
	driveDistance = a_Drive.GetDistanceX();
		if (driveDistance < a_WallDistances[a_BotPosition]) {
			a_Drive.Update(0,.5,0,0);
		} else {
			a_NeedsToRun[i] = false;
		}
	}

void Autonomous2::ClearBoiler(int i){
	if (driveDistance < 10) {
		a_Drive.Update(.5,0,0,0);
	} else {
		a_NeedsToRun[i] = false;
	}
}

void Autonomous2::TurnToFront(int i){
	a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),a_FrontAngles[a_BotPosition]);
	a_NeedsToRun[i] = false;
}

void Autonomous2::TurnToFrontWait(int i) {
	if(fabs(a_Gyro.GetAngle()) - fabs(a_FrontAngles[a_BotPosition]) >3 ) {
		a_Drive.Update(0,0,0,a_Gyro.GetAngle());
	} else {
		a_NeedsToRun[i] = false;
	}
}
// --------------------------------------------------------------------------------------------------------------

void Autonomous2::BlueLeft(){
	a_BotPosition = kBlueLeft;
	do {
		a_Gyro.Update();
		driveDistance = a_Drive.GetDistanceY();
		if(a_NeedsToRun[0]) {
			AdjustOnWall(0);
			break;
		}
		if(a_NeedsToRun[1]) {
			ShootFuel(1);
			break;
		}
		if(a_NeedsToRun[2]) {
			ClearBoiler(2);
			break;
		}
		if(a_NeedsToRun[3]) {
			TurnToFront(3);
			break;
		}
		if(a_NeedsToRun[4]) {
			TurnToFrontWait(4);
			break;
		}
		if(a_NeedsToRun[5]) {
			MoveToBaseline(5);
			break;
		}
		if(a_NeedsToRun[6]) {
			MoveandTurnToPeg(6);
			break;
		}
		if(a_NeedsToRun[7]) {
			ScoreGear(7);
			break;
		}
	} while (true);
}

void Autonomous2::BlueRight(){
	a_BotPosition = kBlueRight;
	do {
		a_Gyro.Update();
		driveDistance = a_Drive.GetDistanceY();
		if(a_NeedsToRun[0]) {
			MoveToBaseline(0);
			break;
		}
		if(a_NeedsToRun[1]) {
			MoveandTurnToPeg(1);
			break;
		}
		if(a_NeedsToRun[2]) {
			ScoreGear(2);
			break;
		}
		if(a_NeedsToRun[3]) {
			ClearShields(3);
			break;
		}
		if(a_NeedsToRun[4]) {
			MoveandTurnToBoiler(4);
			break;
		}
		if(a_NeedsToRun[5]) {
			ShootFuel(5);
			break;
		}
	} while (true);
}

void Autonomous2::BlueMiddle(){
	a_BotPosition = kMiddle;
	do {
		a_Gyro.Update();
		driveDistance = a_Drive.GetDistanceY();
		if(a_NeedsToRun[0]) {
			MoveToBaseline(0);
			break;
		}
		if(a_NeedsToRun[1]) {
			ScoreGear(1);
			break;
		}
		if(a_NeedsToRun[2]) {
			ClearShields(2);
			break;
		}
		if(a_NeedsToRun[3]) {
			MoveandTurnToBoiler(3);
			break;
		}
		if(a_NeedsToRun[4]) {
			ShootFuel(4);
			break;
		}
	} while (true);
}

void Autonomous2::RedLeft(){
	a_BotPosition = kRedLeft;
	do {
		a_Gyro.Update();
		driveDistance = a_Drive.GetDistanceY();
		if(a_NeedsToRun[0]) {
			MoveToBaseline(0);
			break;
		}
		if(a_NeedsToRun[1]) {
			MoveandTurnToPeg(1);
			break;
		}
		if(a_NeedsToRun[2]) {
			ScoreGear(2);
			break;
		}
		if(a_NeedsToRun[3]) {
			ClearShields(3);
			break;
		}
		if(a_NeedsToRun[4]) {
			MoveandTurnToBoiler(4);
			break;
		}
		if(a_NeedsToRun[5]) {
			ShootFuel(5);
			break;
		}
	} while (true);
}

void Autonomous2::RedRight(){
	a_BotPosition = kRedRight;
	do {
		a_Gyro.Update();
		driveDistance = a_Drive.GetDistanceY();
		if(a_NeedsToRun[0]) {
			AdjustOnWall(0);
			break;
		}
		if(a_NeedsToRun[1]) {
			ShootFuel(1);
			break;
		}
		if(a_NeedsToRun[2]) {
			ClearBoiler(2);
			break;
		}
		if(a_NeedsToRun[3]) {
			TurnToFront(3);
			break;
		}
		if(a_NeedsToRun[4]) {
			TurnToFrontWait(4);
			break;
		}
		if(a_NeedsToRun[5]) {
			MoveToBaseline(5);
			break;
		}
		if(a_NeedsToRun[6]) {
			MoveandTurnToPeg(6);
			break;
		}
		if(a_NeedsToRun[7]) {
			ScoreGear(7);
			break;
		}
	} while (true);
}

void Autonomous2::RedMiddle(){
	a_BotPosition = kMiddle;
	do {
		a_Gyro.Update();
		driveDistance = a_Drive.GetDistanceY();
		if(a_NeedsToRun[0]) {
			MoveToBaseline(0);
			break;
		}
		if(a_NeedsToRun[1]) {
			ScoreGear(1);
			break;
		}
		if(a_NeedsToRun[2]) {
			ClearShields(2);
			break;
		}
		if(a_NeedsToRun[3]) {
			MoveandTurnToBoiler(3);
			break;
		}
		if(a_NeedsToRun[4]) {
			ShootFuel(4);
			break;
		}
	} while (true);
}

/*
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
*/

/*
we have constructed global float variables called iAccumGyro and iAccumDrive.
void Autonomous::PIDMoveToSomethingExample(int i)
{
	float gyroError = SetAngle - a_Gyro.GetAngle;
	float driveError = targetDistance - a_Drive.GetDistanceY();

	iAccumGyro += gyroError;
	iAccumDrive += driveError;

	if(fabs(gyroError) < acceptableTurnError) {
		iAccumGyro = 0;
	}

	if(fabs(driveError) < acceptableDriveError) {
		iAccumDrive = 0;
	}

	a_Drive.Update(0, driveP * driveError + driveI * iAccumDrive, turnP * gyroError + turnI * iAccumGyro, a_Gyro.GetAngle());
	if(fabs(gyroError) < acceptableTurnError && fabs(driveError) < acceptableDriveError) {
		a_NeedsToRun[i] = false;
	}

}
*/


