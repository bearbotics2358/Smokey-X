#include "Autonomous2.h"

Autonomous2::Autonomous2(Joystick &buttonBox, SwerveDrive &Drive, JrimmyGyro &Gyro, Shooter &Shooter)
: a_ButtonBox(buttonBox),
  a_Drive(Drive),
  a_Gyro(Gyro),
  a_Shooter(Shooter),
  a_BotPosition(kMiddle)
{
	driveDistance = 0;
	acceptableDriveError = 3;
	acceptableTurnError = 3;

	driveP = 0;
	turnP = 0;

	tState = 0;
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

void Autonomous2::MoveToBaselineandTurnToPeg(int i){
	float gyroError = a_PegAngles[a_BotPosition] - a_Gyro.GetAngle();
	float driveError = a_BaselineDistances[a_BotPosition] - a_Drive.GetDistanceY();

	a_Drive.Update(0, driveP * driveError, turnP * gyroError, a_Gyro.GetAngle());
	if(fabs(gyroError) < acceptableTurnError && fabs(driveError) < acceptableDriveError) {
		a_NeedsToRun[i] = false;
	}
}

void Autonomous2::MoveToPeg(int i){
	driveDistance = a_Drive.GetDistanceY();
		if (driveDistance < a_PegDistances[a_BotPosition]) {
			a_Drive.Update(0,0.5,0,0);
		} else {
			a_NeedsToRun[i] = false;
		}
}

void Autonomous2::ScoreGear(int i){
	if(Timer::GetFPGATimestamp() >= tState + 3) {
		a_NeedsToRun[i] = false;
	}
}

void Autonomous2::ClearShieldsandTurnToBoiler(int i){
	float gyroError = a_BoilerAngles[a_BotPosition] - a_Gyro.GetAngle();
	float driveError = a_BoilerDistances[a_BotPosition] - a_Drive.GetDistanceY();

	a_Drive.Update(0, -driveP * driveError, turnP * gyroError, a_Gyro.GetAngle());
	if(fabs(gyroError) < acceptableTurnError && fabs(driveError) < acceptableDriveError) {
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
}*/

void Autonomous2::MoveToBoiler(int i){
	driveDistance = a_Drive.GetDistanceY();
	if (driveDistance < 0) {
		a_Drive.Update(.5,0,0,0);
	} else {
		a_NeedsToRun[i] = false;
	}
}

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
			MoveToBaselineandTurnToPeg(5);
			break;
		}
		if(a_NeedsToRun[6]) {
			MoveToPeg(6);
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
			MoveToBaselineandTurnToPeg(0);
			break;
		}
		if(a_NeedsToRun[1]) {
			MoveToPeg(1);
			break;
		}
		if(a_NeedsToRun[2]) {
			ScoreGear(2);
			break;
		}
		if(a_NeedsToRun[3]) {
			ClearShieldsandTurnToBoiler(3);
			break;
		}
		if(a_NeedsToRun[4]) {
			MoveToBoiler(4);
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
			MoveToBaselineandTurnToPeg(0);
			break;
		}
		if(a_NeedsToRun[1]) {
			ScoreGear(1);
			break;
		}
		if(a_NeedsToRun[2]) {
			ClearShieldsandTurnToBoiler(2);
			break;
		}
		if(a_NeedsToRun[3]) {
			MoveToBoiler(3);
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
			MoveToBaselineandTurnToPeg(0);
			break;
		}
		if(a_NeedsToRun[1]) {
			MoveToPeg(1);
			break;
		}
		if(a_NeedsToRun[2]) {
			ScoreGear(2);
			break;
		}
		if(a_NeedsToRun[3]) {
			ClearShieldsandTurnToBoiler(3);
			break;
		}
		if(a_NeedsToRun[4]) {
			MoveToBoiler(4);
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
			MoveToBaselineandTurnToPeg(5);
			break;
		}
		if(a_NeedsToRun[6]) {
			MoveToPeg(6);
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
			MoveToBaselineandTurnToPeg(0);
			break;
		}
		if(a_NeedsToRun[1]) {
			ScoreGear(1);
			break;
		}
		if(a_NeedsToRun[2]) {
			ClearShieldsandTurnToBoiler(2);
			break;
		}
		if(a_NeedsToRun[3]) {
			MoveToBoiler(3);
			break;
		}
		if(a_NeedsToRun[4]) {
			ShootFuel(4);
			break;
		}
	} while (true);
}



