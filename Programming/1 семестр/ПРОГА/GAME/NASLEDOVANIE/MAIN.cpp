// main.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mag.h"
#include "Player.h"
using namespace std;
const int n = 5;

int main()
{
	setlocale(LC_ALL, "rus");

	Player *student[n];
	Player s0("Dumbldor", Race :: gnome, Status::dead,0);
	student[0] = &s0;
	Player s1("Harry Poter", Race::human,Status::healthy,1);
	student[1] = &s1;
	Player s2("dnvdnbnb", Race::gnome, Status::dead, 0);
	student[2] = &s2;
	Player s3("Idfbfdfd", Race::gnome, Status::dead, 0);
	student[3] = &s3;
	Player s4("dfbdbbbg", Race::gnome, Status::dead, 0);
	student[4] = &s4;
	//output
	
	// генерирование оценок
	int* power = new int[n];
	for (int i = 0; i < n; ++i)
	{
		power[i] = 1 + rand() % 99;
	}
	// первая сессия
	Mag *students1[n];

	Mag fs0(s0, power[0],  " magic1 ");
	students1[0] = &fs0;
	Mag fs1(s1, power[1]," magic2" );
	students1[1] = &fs1;
	Mag fs2(s2, power[2]," magic3");
	students1[2] = &fs2;
	Mag fs3(s3, power[3],"dfnb ");
	students1[3] = &fs3;
	Mag fs4(s4, power[4],"dnb ");
	students1[4] = &fs4;

	for (int i = 0; i < n; ++i)
	{
		cout << (*student[i]);
		cout << (*students1[i]) << endl;
	}
	/*for (int i = 0; i < n; ++i)
	{
		cout << (*students1[i]) << endl;
	}
	cout << endl;*/
	
	


	

		system("pause");
		return 0;
	
}