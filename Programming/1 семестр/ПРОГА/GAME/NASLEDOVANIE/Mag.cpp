#include "Mag.h"

ostream& operator<<(ostream& os, Mag &m)
{
	//os << m.GetName() << endl;
	os << "MAGIC: " << m.GetMag() << endl;
	os << "POWER: " << m.GetPower() << endl;
	return os;
}