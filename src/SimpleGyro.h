#ifndef SIMPLEGYRO_H
#define SIMPLEGYRO_H

#include <WPILib.h>
#include <I2C.h>

class SimpleGyro(){
public:
 SimpleGyro();
 
private:
 I2C m_I2C;
 
};

#endif
