#include "K_tree.h"
#include "Tree.h"
#include<iostream>
#include <fstream>
#include <string>
using namespace std;

void count(K_tree treeVector)
{
	cout << "Количесво хвойных деревьев: " <<treeVector.countHv() << endl;
	cout << "Количесво лиственных деревьев:  " << treeVector.countList() << endl;
	cout << "Количесво лесных деревьев:  " << treeVector.countL() << endl;
	cout << "Количесво плодовых деревьев:  " << treeVector.countP() << endl;
}
int main()
{
	setlocale(LC_ALL, "rus");
	K_tree Vector;
	string str;
	ifstream file("Trees.txt");
	if (!file)
	{
		cout << "An error occurred opening the file" << endl;
		system("pause");
		exit(0);
	}
	if (file.peek() == EOF)
	{
		cout << "Empty file!" << endl;
		system("pause");
		exit(0);
	}
	string name;
	Type1 type;
	string typestr;
	int age;
	int wood;
	int harvest;
	int time;

	while (!file.eof()) {
		file >> str;
		if (str == "Лесное")
		{
			file >> name;
			file >> age;
			file >> typestr;
			if (typestr == "хвойное")
				type = Hv;
			else type = List;
			file >> wood;
			Vector.add((Tree *)(new Ltree(name, age, type, wood)));
		}
		if (str == "Плодовое")
		{
			file >> name;
			file >> age;
			file >> typestr;
			if (typestr == "хвойное")
				type = Hv;
			else type = List;
			file >> harvest;
			file >> time;
			Vector.add((Tree *)(new Ptree(name, age, type, harvest, time)));
		}

	}
	file.close();

	count(Vector);
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Полная инфорация о деревьях " << endl;
	cout << "-------------------------------------------------------------------" << endl;
	for (int i = 0; i < Vector.Ktrees.size(); i++)
	{
		Vector.Ktrees[i]->print();
	}
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Краткий отсортированный список " << endl;
	cout << "-------------------------------------------------------------------" << endl;
	Vector.printS();
	
	system("pause");
}