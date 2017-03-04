#ifndef PRACTICEPREFS_H
#define PRACTICEPREFS_H

#define FRONT_RIGHT_TURN_OFFSET 0
#define FRONT_LEFT_TURN_OFFSET 0
#define BACK_RIGHT_TURN_OFFSET 0
#define BACK_LEFT_TURN_OFFSET 0

#define FRONT_RIGHT_TURN_PID 0,0,0 // 40,0,75
#define FRONT_RIGHT_DRIVE_PIDF 1.2,0,35,1.6275 // 2.5,0,25,1.6
#define FRONT_LEFT_TURN_PID 0,0,0 // 60,0,75
#define FRONT_LEFT_DRIVE_PIDF 3.3,0,30,1.6 // 3.5,0,45,1.6
#define BACK_RIGHT_TURN_PID 0,0,0 // 33,0,50
#define BACK_RIGHT_DRIVE_PIDF 0,0,0,0
#define BACK_LEFT_TURN_PID 0,0,0 // 33,0,150
#define BACK_LEFT_DRIVE_PIDF 2.4,0,15,1.6 // 3.25,0,45,1.6

#define COLLECTOR_ONE_PID 0.04,0,0.005 // 0.145,0,0.5
#define COLLECTOR_ONE_F 0.133 // 0.12
#define COLLECTOR_TWO_PID 0.42,0,0.2 // 0.4,0,0.2
#define COLLECTOR_TWO_F 0.605 // 0.095

#define IMPELLER_P 0.45 // 0.25
#define IMPELLER_I 0
#define IMPELLER_D 0.01 // 1.5
#define IMPELLER_F 0.63 // 0.65

#define TURN_ENCODER_TYPE CANTalon::AnalogEncoder // actually analog now- need to update later- got an odd error
#define ABSOLUTE_CONV_FACTOR (1024 / 360.0)

#endif
