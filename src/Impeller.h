#ifndef SRC_IMPELLER_H_
#define SRC_IMPELLER_H_

#include "CANTalon.h"

class Impeller
{
public:
	Impeller(int ImpellerPort);
	virtual ~Impeller() = default;
	void Update(float val, uint8_t syncGroup = 0);
private:
	CANTalon a_Impeller;
};



#endif
