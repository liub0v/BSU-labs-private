#pragma once
#include "Tree.h"
class Ptree :public Tree
{
protected:
	int harvest;
	int bestbefore;
public:
	Ptree(string name, int age, Type1 type, int harvest, int bestbefore);
	~Ptree() {};
	Ptree() {};

	virtual void print();
	int getHarvest();
	int getBestbefore(); 
	virtual Type2 getType2();
};

#pragma once
