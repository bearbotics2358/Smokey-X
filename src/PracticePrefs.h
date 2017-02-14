#ifndef PRACTICEPREFS_H
#define PRACTICEPREFS_H



#define FRONT_RIGHT_TURN_OFFSET 0
#define FRONT_LEFT_TURN_OFFSET 0
#define BACK_RIGHT_TURN_OFFSET 0
#define BACK_LEFT_TURN_OFFSET 0

#define FRONT_RIGHT_TURN_PID 0,0,0 // 40,0,75
#define FRONT_RIGHT_DRIVE_PIDF 0,0,0,0 // 1,0,0,1
#define FRONT_LEFT_TURN_PID 0,0,0 // 60,0,75
#define FRONT_LEFT_DRIVE_PIDF 0,0,0,0 // 1,0,0,1
#define BACK_RIGHT_TURN_PID 0,0,0 // 33,0,50
#define BACK_RIGHT_DRIVE_PIDF 0,0,0,0 // 1,0,0,0.6
#define BACK_LEFT_TURN_PID 0,0,0 // 33,0,150
#define BACK_LEFT_DRIVE_PIDF 0,0,0,0 // 1,0,0,0.6

#define TURN_ENCODER_TYPE CANTalon::PulseWidth
#define ABSOLUTE_CONV_FACTOR 1.0 / 360.0

#endif
