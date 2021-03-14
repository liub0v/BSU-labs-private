#pragma once
#include <iostream>

using namespace std;

class Game
{
public:
	enum HealthState { HEALTHY, PARALYZED, DEAD };
	enum Race{GNOME, HUMAN, ELF};

	Game();
	Game(Game & player);
	Game(char* name, HealthState healthCond, Race race, bool moveAbility);
	int getID();
	char* getName();
	HealthState getHealth();
	Race getRace();
	bool getMoveAb();
	void setHealth(HealthState state);
	void setMove(bool canMove);
	void operator =(Game & game);
	bool operator < (Game & game);
	void printInfo(ostream & out);
	~Game();
private:
	static int currentNumber;
	int id;
	char* name;
	HealthState healthCond;
	Race race;
	bool moveAbility;


};

