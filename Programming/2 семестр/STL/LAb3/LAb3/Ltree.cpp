#include "Ltree.h"

int Ltree::getWood()
{
	return wood;
}

void Ltree::print()
{
	cout << "Дерево: " << getName() << endl << "Возраст: " << getAge();
		
		cout  <<" лет; Объем древесины: "<< getWood() << " тонн;";
		cout << " Тип: ";
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

void Ltree::setWood(int wood)
{
	this->wood = wood;
}

Type2 Ltree::getType2()
{
	return Type2::L;
}


Ltree::Ltree(string name, int age, Type1 type, int wood) : Tree(name, age, type)
{
	this->wood = wood;
}



