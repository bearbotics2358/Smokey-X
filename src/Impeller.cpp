#include <WPILib.h>
#include "Impeller.h"

Impeller::Impeller(int ImpellerPort)
: a_Impeller(ImpellerPort)
{

}

void Impeller::Update(float val, uint8_t syncGroup)
{
	a_Impeller.Set(val);
}
