#ifndef SRC_SERIALULTRASONIC_H_
#define SRC_SERIALULTRASONIC_H_

#include <WPILib.h>
#include "Prefs.h"

class SerialUltrasonic // Used for a maxbotix serial ultrasonic, with an RS-232 data format of RXXXX\n, where XXXX has value from ~0300 to ~5000
{
public:
	SerialUltrasonic(int baudRate = 9600, SerialPort::Port port = SerialPort::kOnboard, int dataBits = 8, SerialPort::Parity parity = SerialPort::kParity_None, SerialPort::StopBits stopBits = SerialPort::kStopBits_One);
	virtual ~SerialUltrasonic() = default;
	int GetDistanceMm(); // returns distance in millimeters- "native" units, nice and round numbers
	float GetDistanceIn(); // returns distance in inches
private:
	SerialPort a_UltrasonicPort;
	char buff[256];
};



#endif
