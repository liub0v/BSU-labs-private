
#ifndef STUDENT1_H_INCLUDED
#define STUDENT1_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include "Player.h"

class Mag : public Player {
protected:
	int power;
	char* mag;
	Mag() : Player()
	{
		mag = 0;
		power = 0;
	}
public:
	Mag( Player& p, int power,const char* m) : Player(p)
	{
		char* mag1 = new char[10];//strlen(m) + 1];
		strcpy(mag1, m);
		this->power = power;
		this->mag = mag1;
	}
	// конструктор копироваия 
	Mag(const Mag& m) : Player(m), power(m.power),mag(m.mag) { }


	friend ostream& operator<<(ostream& os, Mag &m);

	void SetPower(int p)
	{
		power = p;
	}
	int GetPower()
	{
		return power;
	}
	void SetMag(char* m)
	{
		mag = m;
	}
	char* GetMag()
	{
		return mag;
	}
};
#endif
