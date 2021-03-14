#include "Tree.h"

Tree::Tree(string name, int age, Type1 type)
{
	this->name = name;
	this->age = age;
	this->type = type;
}

Type1 Tree::getType()
{
	return type;
}


string Tree::getName()
{
	return name;
}

int Tree::getAge()
{
	return age;
}

void Tree::setName(string name)
{
	this->name = name;
}

void Tree::setAge(int age)
{
	this->age = age;
}

void Tree::setType(Type1 type)
{
	this->type = type;
}

Type2 Tree::getType2()
{
	return Type2 ::L;
}
