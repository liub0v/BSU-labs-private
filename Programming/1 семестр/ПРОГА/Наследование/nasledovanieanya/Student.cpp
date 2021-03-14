#include "Student.h"
#include <string>

int Student::nextID = 1000;

void Student::Clone(char* name)
{
	this->name = new char[20];
	strcpy_s(this->name, 20, name);
}

void Student::Erase(char* name)
{
	if (name)
		delete[]name;
}

Student::Student(const char* name, int course, int group, const int& n_creditcard) : ID(nextID++), n_creditcard(n_creditcard)
{
	char* n = const_cast<char*>(name); 
	Clone(n);
	this->course = course;
	this->group = group;
}

Student::Student(const Student& s) : ID(s.ID), n_creditcard(s.n_creditcard)
{
	Clone(name);
	course = s.course;
	group = s.group;
}
Student::~Student()
{
	Erase(name);
}

void Student::setName(char* name)
{
	delete this->name;
	this->name = new char[20];
	this->name = name;
}
void Student::setCourse(int course)
{
	this->course = course;
}
void Student::setGroup(int group)
{
	this->group = group;
}

char* Student::getName() const
{
	return name;
}
int Student::getCourse() const
{
	return course;
}
int Student::getGroup() const
{
	return group;
}
const int Student::getN_creditcard() const
{
	return n_creditcard;
}
const int Student::getID() const
{
	return ID;
}

double Student::Average_Point()
{
	return 0;
}

ostream& operator<<(ostream& OS, const Student& s)
{
	OS << s.name << " ";
	OS << s.course << " курс " << s.group << " группа. Номер зачетки: " << s.n_creditcard << " ID " << s.ID;
	return OS;
}


