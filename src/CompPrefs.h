#ifndef COMPPREFS_H
#define COMPPREFS_H

#define FRONT_RIGHT_TURN_OFFSET 0
#define FRONT_LEFT_TURN_OFFSET 0
#define BACK_RIGHT_TURN_OFFSET 0
#define BACK_LEFT_TURN_OFFSET 0

#define FRONT_RIGHT_TURN_PID 20,0,75
#define FRONT_RIGHT_DRIVE_PIDF 0.75,0.00005,0,1.55
#define FRONT_RIGHT_IZONE 0
#define FRONT_LEFT_TURN_PID 20,0,75
#define FRONT_LEFT_DRIVE_PIDF 0.75,0.00005,0,1.55
#define FRONT_LEFTT_IZONE 0
#define BACK_RIGHT_TURN_PID 16.5,0,50
#define BACK_RIGHT_DRIVE_PIDF 1.5,0.001,0,1.45
#define BACK_RIGHT_IZONE 0
#define BACK_LEFT_TURN_PID 15,0,150
#define BACK_LEFT_DRIVE_PIDF 1,0.0005,0,1.47
#define BACK_LEFT_IZONE 0

#define COLLECTOR_ONE_PID 0.145,0,0.5
#define COLLECTOR_ONE_F 0.12
#define COLLECTOR_TWO_PID 0.4,0,0.2
#define COLLECTOR_TWO_F 0.095

#define IMPELLER_P 0.25
#define IMPELLER_I 0
#define IMPELLER_D 1.5
#define IMPELLER_F 0.65

#define SHOOTER_P 0.095
#define SHOOTER_I 0
#define SHOOTER_D 1
#define SHOOTER_F 0.029
#define SHOOTER_IZONE 0

#define TURN_ENCODER_TYPE CANTalon::PulseWidth
#define ABSOLUTE_CONV_FACTOR (1 / 360.0)

#endif
