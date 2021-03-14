#include "Game.h"

int Game::currentNumber = 0;

//конструктор без параметров
Game::Game()
{
	id = currentNumber;
	currentNumber++;
}

//конструктор копирования
Game::Game(Game & player) : Game()
{
	name = player.name;
	healthCond = player.healthCond;
	moveAbility = player.moveAbility;
	race = player.race;
	id = player.id;
}

//конструктор с параметрами
Game::Game(char * name, HealthState healthCond, Race race, bool moveAbility) : Game()
{
	this->name = name;
	this->healthCond = healthCond;
	this->race = race;
	this->moveAbility = moveAbility;
}

//get-методы для всех неизменных полей
int Game::getID() 
{
	return id;
}

char * Game::getName()
{
	return nullptr;
}

Game::HealthState Game::getHealth()
{
	return HealthState();
}

Game::Race Game::getRace()
{
	return Race();
}

bool Game::getMoveAb()
{
	return false;
}

//set-методы для изменяемых полей
void Game::setHealth(HealthState healthCond)
{
	this->healthCond = healthCond;
}

void Game::setMove(bool moveAbility)
{
	this->moveAbility = moveAbility;
}

//перегрузка оператора присваивания
void Game::operator=(Game & game)
{
	id = game.id;
	name = game.name;
	healthCond = game.healthCond;
	race = game.race;
	moveAbility = game.moveAbility;
}

//перегрузка оператора сравнения
bool Game::operator<(Game & game)
{
	return id < game.id;
}

//вывод сведений об объекте через выходной поток
void Game::printInfo(ostream & out)
{
	out << "id: " << id << endl;
	out << "name: " << name << endl;
	out << "health condition: ";
	switch (healthCond)
	{
	case DEAD:
		out << "Dead" << endl;
		break;
	case PARALYZED:
		out << "Paralyzed" << endl;
		break;
	default:
		out << "Healthy" << endl;
		break;
	}
	out << "Race: ";
	switch (race)
	{
	case HUMAN:
		out << "Human" << endl;
		break;
	case ELF:
		out << "Elf" << endl;
	default:
		out << "Gnome" << endl;
		break;
	}
	out << "Can move: " << moveAbility ? "Yes" : "No";
	out << endl;
}

Game::~Game()
{
}
