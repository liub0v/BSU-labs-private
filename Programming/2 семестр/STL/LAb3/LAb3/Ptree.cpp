#include "Ptree.h"
void Ptree::print()
{
	cout << "Дерево: " << getName() << endl << "Возраст: " << getAge() << " лет; Урожай: " << getHarvest()<<" кг; Время хранения плодов: "<<getBestbefore() << " месяцев;\n";
	cout << "Тип: ";
	switch (getType())
	{
	case 0:cout << "хвойное, ";
		break;
	case 1:cout << "лиственное, ";
		break;
	}
	//cout << " Тип: ";
	switch (getType2())
	{
	case 0: cout << "плодовое ";
		break;
	case 1: cout << "лесное ";

	}
	cout << endl;
}

int Ptree::getHarvest()
{
	return harvest;
}

int Ptree::getBestbefore()
{
	return bestbefore;
}

Type2 Ptree::getType2()
{
	return Type2::P;
}

Ptree::Ptree(string name, int age, Type1 type, int cropWeight, int averageStTime) :Tree(name, age, type)
{
	this->harvest = cropWeight;
	this->bestbefore = averageStTime;
}


