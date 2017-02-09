#include "Autonomous.h"

Autonomous::Autonomous(Joystick &buttonBox, SwerveDrive &Drive, JrimmyGyro &Gyro)
: a_ButtonBox(buttonBox),
  a_Drive(Drive),
  a_Gyro(Gyro),
  a_BotPosition

{
	driveDistance = 0;
}

driveDistance = a_Drive.GetDistance; // already converts to inches
void MoveToBaseline(){
	if (driveDistance < BASELINE_DISTANCE) {
		a_Drive.Update(.5,0,0,0);
	}
}

void TurnToPeg(float position){

}

void MoveToPeg(){

}

void ScoreGear(){

}

void ClearShields(){

}

void TurnToBoiler(){

}

void MoveToShootingDistance(float position){

}

void ShootFuel(){

}

/**


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
