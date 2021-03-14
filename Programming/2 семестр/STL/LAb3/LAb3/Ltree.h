#pragma once
#include "Tree.h"
class Ltree : private Tree
{
protected:
	int wood;
public:
	Ltree(string name, int age, Type1 type, int wood);
	~Ltree() {};
	Ltree() {};

	int getWood();
	void setWood(int wood);
	virtual void print();
	virtual Type2 getType2();
};

#pragma once
