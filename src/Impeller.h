#ifndef SRC_IMPELLER_H_
#define SRC_IMPELLER_H_

#include "CANTalon.h"
#include "Prefs.h"

class Impeller // Used in conjunction with collector to index balls for shooter
{
public:
	Impeller(int ImpellerPort);
	virtual ~Impeller() = default;
	void Update();
	void Set(float val);
	float GetSpeed();
private:
	CANTalon a_Impeller;
	float tState;
	float setVal;
};



#endif
