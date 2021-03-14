
#ifndef Student_H_INCLUDED
#define Student_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
using namespace std;
enum Race { gnome, elf, human };
enum Status { healthy, paralyzed, dead };
class Player
{
protected:
	const Race race;
	Status status;
	char* name;
	bool isMove;
	static int nextID;
	const int ID;

	virtual void clone(const Player& p)
	{
		char* name = new char[10];//strlen(p.name) + 1];
		strcpy(name, p.name);
		status = p.status;
		isMove = p.isMove;
	}
	virtual void erase()
	{
		delete[] name;
	}
	Player() : ID(nextID++), race(), status() { name = 0, isMove = 0; }
public:
	// Конструктор класса player
	Player(const char* n, const Race r,Status s , bool is) : ID(++nextID),race(r)
	{
		char* name1 = new char[10];//[strlen(n) + 1];
		strcpy(name1, n);
		this->name = name1;
		this->status = s;
		this->isMove = is;
	}
	//конструктор копирования
	Player(const Player &p) : ID(++nextID),race(p.race)
	{
		//name = p.GetName; status = p.GetStatus; isMove = p.GetIsMove;
		clone(p);
	}
	//деструктор
	~Player()
	{
		erase();
	}

	friend ostream &operator<<(ostream&, const Player &);
	void operator = (const Player& pl);
	bool operator > (const Player &player) const;

	void SetName(char* n)
	{
		name = n;
	}

	void SetStatus(Status s)
	{
		status = s;
	}

	void SetIsMove(bool is)
	{
		isMove = is;
	}

	char* GetName() const
	{
		return name;
	}

	Status GetStatus() const
	{
		return status;
	}

	Race GetRace() const
	{
		return race;
	}

	bool GetIsMove() const
	{
		return isMove;
	}

	/*~Player()
	{
		this->nextID--;
	}*/

	const int GetID() const
	{
		return ID;
	}
};

#endif 
