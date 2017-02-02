#include <SimpleGyro.h>
#include <Prefs.h>
#include <WPILib.h>

SimpleGyro::SimpleGyro()
	:m_I2C(I2C::kMXP, 0x68){


}
