#include "Game.h"
#include <iostream>
#include <string.h>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;

//сортировка массива объектов в алфавитном порядке
void sort(vector<Game *> & vec) {
	for (int i = 0; i < vec.size(); i++)
		for (int g = i + 1; g < vec.size(); g++)
			if (strcmp(vec[i]->getName(), vec[g]->getName())) {
				swap(vec[i], vec[g]);
			}
}

//вывести инфу обо всех объектах
void printInfo(vector <Game *> & vec) {
	for (int i = 0; i < vec.size(); i++)
		vec[i]->printInfo(cout);
}

//подсчитать количество объектов класса без магии
int countNonMagic(vector <Game *> & vec) {
	int k = 0;
	for (int i = 0; i < vec.size(); i++)
		if (typeid(Game *) == typeid(vec[i]))
			k++;
	return k;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int item = 10;
	char * gandalf = new char[20];
	strcpy(gandalf, "Gandalf");
	char * bilbo = new char[20];
	strcpy(bilbo, "Bilbo");
	char * frodo = new char[20];
	strcpy(frodo, "Frodo");
	char * legolas = new char[20];
	strcpy(legolas, "Legolas");
	char* name = new char[item];
	/*while (name != nullptr)
	{
		switch (item)
		{
			cout << "Выберите имя персонажа: " << endl;
			cout << "1.Гэндальф" << endl;
			cout << "2.Бильбо" << endl;
			cout << "3.Фродо" << endl;
			cout << "4.Леголас" << endl;
		case 1:
			name = gandalf;
			break;
		case 2:
			name = bilbo;
			break;
		case 3:
			name = frodo;
			break;
		case 4:
			name = legolas;
			break;
		}
	}*/
	vector <Game *> vec;
	Game * c1 = new Game(gandalf, Game::HEALTHY, Game::HUMAN, true);
	Game * c2 = new Game(gandalf, Game::DEAD, Game::HUMAN, true);
	Game * c3 = new Game(legolas, Game::HEALTHY, Game::ELF, true);
	Game * c4 = new Game(frodo, Game::PARALYZED, Game::GNOME, false);
	Game * c5 = new Game(bilbo, Game::HEALTHY, Game::GNOME, true);

	c1->printInfo(cout);
	c1 = c2;
	c1->printInfo(cout);
	cin.get();
	return 0;
}