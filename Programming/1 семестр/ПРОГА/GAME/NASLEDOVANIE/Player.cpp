#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Player.h"
using namespace std;
ostream &operator<<(ostream& os, const Player & p)
 {
	os << p.GetName() << endl
		<< "RACE: ";
	switch (p.GetRace())
	{
	case human:
		os << "Human" << endl;
		break;
	case elf:
		os << "Elf" << endl;
	default:
		os << "Gnome" << endl;
		break;
	}
	
	os << "STATUS: ";
	switch (p.GetStatus())
	{
	case dead:
		os << "Dead" << endl;
		break;
	case paralyzed:
		os << "Paralyzed" << endl;
		break;
	default:
		os << "Healthy" << endl;
		break;
	}
	os << "MOVE (1-yes,0-no): " << p.GetIsMove() << endl;
	os << "ID: " << p.GetID() << endl;
	 return os;

 }
int Player::nextID = 1000;

void  Player::operator=(const Player & p)
{
	name = p.name;
	status = p.status;
	isMove = p.isMove;
}

bool Player::operator>(const Player & p) const
{
	if (ID != p.ID)
		return false;

	return true;
}
