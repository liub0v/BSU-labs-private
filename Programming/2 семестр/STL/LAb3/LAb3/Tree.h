#include <string>
#include<iostream>
using namespace std;

enum Type1 { Hv, List };
enum Type2 { P, L };

#pragma once
class Tree
{
public:
	Tree(string name, int age, Type1 type);
	~Tree() {};
	Tree() {};

	Type1 getType();
	string getName();
	int getAge();
	void setName(string name);
	void setAge(int age);
	void setType(Type1 type);
	virtual void print() {};
	virtual Type2 getType2();

protected:
	string name;
	int age;
	Type1 type;
};
#pragma once
