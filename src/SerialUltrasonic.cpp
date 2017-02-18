
#include <math.h>
#include "SerialUltrasonic.h"

SerialUltrasonic::SerialUltrasonic(int baudRate, SerialPort::Port port, int dataBits, SerialPort::Parity parity, SerialPort::StopBits stopBits)
: a_UltrasonicPort(baudRate, port, dataBits, parity, stopBits)
{

}

int SerialUltrasonic::GetDistanceMm() {
	int initialPosition = 1;
	int result = -99;
	a_UltrasonicPort.Read(buff,6); // I could probably read less, but I wanted to be absolutely sure I get a full data set and I'm tired right now
	std::string stringBuff = buff;
	/*
	int firstRPos = stringBuff.find_first_of("R");
	int lastRPos = stringBuff.find_last_of("R");
	if(lastRPos <= 7) {
		initialPosition = lastRPos + 1;
	} else {
		initialPosition = firstRPos + 1;
	}
	*/
	for(int i = 0; i < 4; i++) {
		result += std::stoi(stringBuff.substr(initialPosition + i, 1)) * (1000 * pow(10, -i));
	 }
	// If we don't want to loop it, the less nice way is below
	// result = std::stoi(stringBuff.substr(initialPosition,1)) * 1000 + std::stoi(stringBuff.substr(initialPosition + 1,1)) * 100 + std::stoi(stringBuff.substr(initialPosition + 2,1)) * 10 + std::stoi(stringBuff.substr(initialPosition + 3,1));
	return result;
}

float SerialUltrasonic::GetDistanceIn()
{
	int distanceMm = GetDistanceMm();
	if(distanceMm <0) {
		return -99;
	}
	return  distanceMm * 1 / 25.4; // conversion factor is 1 inch / 25.4 mm
}



