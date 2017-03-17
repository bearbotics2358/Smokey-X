#include "Autonomous.h"

Autonomous::Autonomous(Joystick &buttonBox, SwerveDrive &Drive, JrimmyGyro &Gyro, Shooter &Shooter)
: a_ButtonBox(buttonBox),
  a_Drive(Drive),
  a_Gyro(Gyro),
  a_Shooter(Shooter),
  a_BotPosition(kMiddle)
{
	driveDistance = 0;
	tState = 0;
}

void Autonomous::Init()
{
	// blue = true;
	// red = false;
	// regular = true;
	// stupid = false;

	if(a_ButtonBox.GetRawButton(7)){
		level = true;
	}else{
		level = false;
	}

	if(a_ButtonBox.GetRawButton(1)){
		side = true;
	}else{
		side = false;
	}
	if(a_ButtonBox.GetRawButton(2)) {
		leftPos = true;
	} else if(a_ButtonBox.GetRawButton(4)) {
		rightPos = true;
	} else {
		midPos = true;
	}

	a_Drive.Zero();
}

void Autonomous::Update(){

	if(leftPos&&side&&level){
		a_Shooter.Set(0.75);
		BlueLeft();
	}else if(leftPos&&!side&&level){
		a_Shooter.Set(0.75);
		RedLeft();
	}else if(leftPos&&side&&!level){
		StupidBlueLeft();
	}else if(leftPos&&!side&&!level){
		StupidRedLeft();
	}

	if(midPos&&side&&level){
		a_Shooter.Set(0.75);
		BlueMiddle();
	}else if(midPos&&!side&&level){
		a_Shooter.Set(0.75);
		RedMiddle();
	}else if(midPos&&side&&!level){
		StupidBlueMiddle();
	}else if(midPos&&!side&&!level){
		StupidRedMiddle();
	}

	if(rightPos&&side&&level){
		a_Shooter.Set(0.75);
		BlueRight();
	}else if(rightPos&&!side&&level){
		a_Shooter.Set(0.75);
		RedRight();
	}else if(rightPos&&side&&!level){
		StupidBlueRight();
	}else if(rightPos&&!side&&!level){
		StupidRedRight();
	}

}

void Autonomous::MoveToBaseline(int i){
	driveDistance = a_Drive.GetDistanceY();
	if (-1.0 * driveDistance * 10 < a_BaselineDistances[a_BotPosition]) {
		a_Drive.Update(0,-0.5,0,0);
	} else {
		a_NeedsToRun[i] = false;
	}
}

void Autonomous::TurnToPeg(int i){
	a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),a_PegAngles[a_BotPosition]);
	a_NeedsToRun[i] = false;
}

void Autonomous::TurnToPegWait(int i) {
	if(fabs(a_Gyro.GetAngle()) - fabs(a_PegAngles[a_BotPosition]) >3 ) {
		a_Drive.Update(0,0,0,a_Gyro.GetAngle());
	} else {
		a_Drive.DisableTwist();
		a_NeedsToRun[i] = false;
	}
}

void Autonomous::MoveToPeg(int i){
	a_Drive.Zero();
	driveDistance = a_Drive.GetDistanceY();
	if (driveDistance < a_PegDistances[a_BotPosition]) {
		a_Drive.Update(0,0.5,0,0);
	} else {
		a_NeedsToRun[i] = false;
	}
	tState = Timer::GetFPGATimestamp();
}

void Autonomous::ScoreGear(int i){
	if(Timer::GetFPGATimestamp() >= tState + 3) {
		a_NeedsToRun[i] = false;
	}
}

void Autonomous::ClearShields(int i){
	a_Drive.Zero();
	driveDistance = a_Drive.GetDistanceY();
	if (driveDistance > a_ShieldsDistances[a_BotPosition]) {
		a_Drive.Update(0,0.5,0,0);
	} else {
		a_NeedsToRun[i] = false;
	}
}

void Autonomous::TurnToBoiler(int i){
	a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),a_BoilerAngles[a_BotPosition]);
	a_NeedsToRun[i] = false;
}

void Autonomous::TurnToBoilerWait(int i) {
	if(fabs(a_Gyro.GetAngle()) - fabs(a_BoilerAngles[a_BotPosition]) >3 ) {
		a_Drive.Update(0,0,0,a_Gyro.GetAngle());
	} else {
		a_Drive.DisableTwist();
		a_NeedsToRun[i] = false;
	}
}

void Autonomous::MoveToBoiler(int i){
	a_Drive.Zero();
	driveDistance = a_Drive.GetDistanceY();
	if (driveDistance < 0) {
		a_Drive.Update(0,0.5,0,0);
	} else {
		a_NeedsToRun[i] = false;
	}
}

void Autonomous::ShootFuel(int i){
	a_Shooter.Set(.5); // revised to follow adjustment
	a_NeedsToRun[i] = false;
}

void Autonomous::AdjustOnWall(int i){
	a_Drive.Zero();
	driveDistance = a_Drive.GetDistanceX();
	if (driveDistance < a_WallDistances[a_BotPosition]) {
		a_Drive.Update(0.5,0,0,0);
	} else {
		a_NeedsToRun[i] = false;
	}
}

void Autonomous::ClearBoiler(int i){
	a_Drive.Zero();
	driveDistance = a_Drive.GetDistanceY();
	if (driveDistance > -10) {
		a_Drive.Update(0,0.5,0,0);
	} else {
		a_NeedsToRun[i] = false;
	}
}

void Autonomous::TurnToFront(int i){
	a_Drive.SetTwistingRelAngle(a_Gyro.GetAngle(),a_FrontAngles[a_BotPosition]);
	a_NeedsToRun[i] = false;
}

void Autonomous::TurnToFrontWait(int i) {
	if(fabs(a_Gyro.GetAngle()) - fabs(a_FrontAngles[a_BotPosition]) >3 ) {
		a_Drive.Update(0,0,0,a_Gyro.GetAngle());
	} else {
		a_NeedsToRun[i] = false;
	}
}
// --------------------------------------------------------------------------------------------------------------

void Autonomous::BlueLeft(){
	a_BotPosition = kBlueLeft;
	driveDistance = a_Drive.GetDistanceY();
	if(a_NeedsToRun[0]) {
		AdjustOnWall(0);
		return;
	}
	if(a_NeedsToRun[1]) {
		ShootFuel(1);
		return;
	}
	if(a_NeedsToRun[2]) {
		ClearBoiler(2);
		return;
	}
	if(a_NeedsToRun[3]) {
		TurnToFront(3);
		return;
	}
	if(a_NeedsToRun[4]) {
		TurnToFrontWait(4);
		return;
	}
	if(a_NeedsToRun[5]) {
		MoveToBaseline(5);
		return;
	}
	if(a_NeedsToRun[6]) {
		TurnToPeg(6);
		return;
	}
	if(a_NeedsToRun[7]) {
		TurnToPegWait(7);
		return;
	}
	if(a_NeedsToRun[8]) {
		MoveToPeg(8);
		return;
	}
	if(a_NeedsToRun[9]) {
		ScoreGear(9);
		return;
	}

}

void Autonomous::BlueRight(){
	a_BotPosition = kBlueRight;


	driveDistance = a_Drive.GetDistanceY();
	if(a_NeedsToRun[0]) {
		MoveToBaseline(0);
		return;
	}
	if(a_NeedsToRun[1]) {
		TurnToPeg(1);
		return;
	}
	if(a_NeedsToRun[2]) {
		TurnToPegWait(2);
		return;
	}
	if(a_NeedsToRun[3]) {
		MoveToPeg(3);
		return;
	}
	if(a_NeedsToRun[4]) {
		ScoreGear(4);
		return;
	}
	if(a_NeedsToRun[5]) {
		ClearShields(5);
		return;
	}
	if(a_NeedsToRun[6]) {
		TurnToBoiler(6);
		return;
	}
	if(a_NeedsToRun[7]) {
		TurnToBoilerWait(7);
		return;
	}
	if(a_NeedsToRun[8]) {
		MoveToBoiler(8);
		return;
	}
	if(a_NeedsToRun[9]) {
		ShootFuel(9);
		return;
	}

}

void Autonomous::BlueMiddle(){
	a_BotPosition = kMiddle;


	driveDistance = a_Drive.GetDistanceY();
	if(a_NeedsToRun[0]) {
		MoveToBaseline(0);
		return;
	}
	if(a_NeedsToRun[1]) {
		ScoreGear(1);
		return;
	}
	if(a_NeedsToRun[2]) {
		ClearShields(2);
		return;
	}
	if(a_NeedsToRun[3]) {
		TurnToBoiler(3);
		return;
	}
	if(a_NeedsToRun[4]) {
		TurnToBoilerWait(4);
		return;
	}
	if(a_NeedsToRun[5]) {
		MoveToBoiler(5);
		return;
	}
	if(a_NeedsToRun[6]) {
		ShootFuel(6);
		return;
	}

}

void Autonomous::RedLeft(){
	a_BotPosition = kRedLeft;


	driveDistance = a_Drive.GetDistanceY();
	if(a_NeedsToRun[0]) {
		MoveToBaseline(0);
		return;
	}
	if(a_NeedsToRun[1]) {
		TurnToPeg(1);
		return;
	}
	if(a_NeedsToRun[2]) {
		TurnToPegWait(2);
		return;
	}
	if(a_NeedsToRun[3]) {
		MoveToPeg(3);
		return;
	}
	if(a_NeedsToRun[4]) {
		ScoreGear(4);
		return;
	}
	if(a_NeedsToRun[5]) {
		ClearShields(5);
		return;
	}
	if(a_NeedsToRun[6]) {
		TurnToBoiler(6);
		return;
	}
	if(a_NeedsToRun[7]) {
		TurnToBoilerWait(7);
		return;
	}
	if(a_NeedsToRun[8]) {
		MoveToBoiler(8);
		return;
	}
	if(a_NeedsToRun[9]) {
		ShootFuel(9);
		return;
	}

}

void Autonomous::RedRight(){
	a_BotPosition = kRedRight;


	driveDistance = a_Drive.GetDistanceY();
	if(a_NeedsToRun[0]) {
		AdjustOnWall(0);
		return;
	}
	if(a_NeedsToRun[1]) {
		ShootFuel(1);
		return;
	}
	if(a_NeedsToRun[2]) {
		ClearBoiler(2);
		return;
	}
	if(a_NeedsToRun[3]) {
		TurnToFront(3);
		return;
	}
	if(a_NeedsToRun[4]) {
		TurnToFrontWait(4);
		return;
	}
	if(a_NeedsToRun[5]) {
		MoveToBaseline(5);
		return;
	}
	if(a_NeedsToRun[6]) {
		TurnToPeg(6);
		return;
	}
	if(a_NeedsToRun[7]) {
		TurnToPegWait(7);
		return;
	}
	if(a_NeedsToRun[8]) {
		MoveToPeg(8);
		return;
	}
	if(a_NeedsToRun[9]) {
		ScoreGear(9);
		return;
	}

}

void Autonomous::RedMiddle(){
	a_BotPosition = kMiddle;


	driveDistance = a_Drive.GetDistanceY();
	if(a_NeedsToRun[0]) {
		MoveToBaseline(0);
		return;
	}
	if(a_NeedsToRun[1]) {
		ScoreGear(1);
		return;
	}
	if(a_NeedsToRun[2]) {
		ClearShields(2);
		return;
	}
	if(a_NeedsToRun[3]) {
		TurnToBoiler(3);
		return;
	}
	if(a_NeedsToRun[4]) {
		TurnToBoilerWait(4);
		return;
	}
	if(a_NeedsToRun[5]) {
		MoveToBoiler(5);
		return;
	}
	if(a_NeedsToRun[6]) {
		ShootFuel(6);
		return;
	}

}
// --------------------------------------------------------------------------------------------------------------------
void Autonomous::StupidBlueLeft(){
	a_BotPosition = kStupidLeft;


	driveDistance = a_Drive.GetDistanceY();
	if(a_NeedsToRun[0]) {
		MoveToBaseline(0);
		return;
	}
	if(a_NeedsToRun[1]) {
		TurnToPeg(1);
		return;
	}
	if(a_NeedsToRun[2]) {
		TurnToPegWait(2);
		return;
	}
	if(a_NeedsToRun[3]) {
		MoveToPeg(3);
		return;
	}
	if(a_NeedsToRun[4]) {
		ScoreGear(4);
		return;
	}
	if(a_NeedsToRun[5]) {
		ClearShields(5);
		return;
	}

}

void Autonomous::StupidBlueRight(){
	a_BotPosition = kBlueRight;


	driveDistance = a_Drive.GetDistanceY();
	if(a_NeedsToRun[0]) {
		MoveToBaseline(0);
		return;
	}
	if(a_NeedsToRun[1]) {
		TurnToPeg(1);
		return;
	}
	if(a_NeedsToRun[2]) {
		TurnToPegWait(2);
		return;
	}
	if(a_NeedsToRun[3]) {
		MoveToPeg(3);
		return;
	}
	if(a_NeedsToRun[4]) {
		ScoreGear(4);
		return;
	}
	if(a_NeedsToRun[5]) {
		ClearShields(5);
		return;
	}

}

void Autonomous::StupidBlueMiddle(){
	a_BotPosition = kMiddle;


	driveDistance = a_Drive.GetDistanceY();
	if(a_NeedsToRun[0]) {
		MoveToBaseline(0);
		return;
	}
	if(a_NeedsToRun[1]) {
		ScoreGear(1);
		return;
	}
	if(a_NeedsToRun[2]) {
		ClearShields(2);
		return;
	}
	if(a_NeedsToRun[3]) {
		TurnToBoiler(3);
		return;
	}

}

void Autonomous::StupidRedLeft(){
	a_BotPosition = kStupidLeft;


	driveDistance = a_Drive.GetDistanceY();
	if(a_NeedsToRun[0]) {
		MoveToBaseline(0);
		return;
	}
	if(a_NeedsToRun[1]) {
		TurnToPeg(1);
		return;
	}
	if(a_NeedsToRun[2]) {
		TurnToPegWait(2);
		return;
	}
	if(a_NeedsToRun[3]) {
		MoveToPeg(3);
		return;
	}
	if(a_NeedsToRun[4]) {
		ScoreGear(4);
		return;
	}
	if(a_NeedsToRun[5]) {
		ClearShields(5);
		return;
	}

}

void Autonomous::StupidRedRight(){
	a_BotPosition = kRedRight;


	driveDistance = a_Drive.GetDistanceY();
	if(a_NeedsToRun[0]) {
		MoveToBaseline(0);
		return;
	}
	if(a_NeedsToRun[1]) {
		TurnToPeg(1);
		return;
	}
	if(a_NeedsToRun[2]) {
		TurnToPegWait(2);
		return;
	}
	if(a_NeedsToRun[3]) {
		MoveToPeg(3);
		return;
	}
	if(a_NeedsToRun[4]) {
		ScoreGear(4);
		return;
	}
	if(a_NeedsToRun[5]) {
		ClearShields(5);
		return;
	}

}

void Autonomous::StupidRedMiddle(){
	a_BotPosition = kMiddle;


	driveDistance = a_Drive.GetDistanceY();
	if(a_NeedsToRun[0]) {
		MoveToBaseline(0);
		return;
	}
	if(a_NeedsToRun[1]) {
		ScoreGear(1);
		return;
	}
	if(a_NeedsToRun[2]) {
		ClearShields(2);
		return;
	}
	if(a_NeedsToRun[3]) {
		TurnToBoiler(3);
		return;
	}

}


void Autonomous::Stupid(){


	driveDistance = a_Drive.GetDistanceY();
	if (driveDistance < 100) {
		a_Drive.Update(.5,0,0,0);
	}


}


/*
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


