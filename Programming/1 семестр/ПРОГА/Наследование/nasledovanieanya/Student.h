#pragma once
#include <iostream>
using namespace std;
class Student
{
protected:
	const int ID;
	char* name;
	int course, group;
	const int n_creditcard;
	static int nextID;

	void Clone(char*);
	void Erase(char*);

	Student() : ID(nextID++), n_creditcard(0) { name = '\0', course = 0; group = 0;  }

public:

	Student(const char*, int, int, const int&);
	~Student();

	

	//конструктор копирования
	Student(const Student&);

	void setName(char*);
	void setCourse(int);
	void setGroup(int);
	//как сделать set-метод для const?

	//когда метод const?
	char* getName() const;
	int getCourse() const;
	int getGroup() const;
	const int getN_creditcard() const;
	const int getID() const;

	virtual double Average_Point();

	friend ostream& operator<<(ostream&,  const Student&);
	
	

};