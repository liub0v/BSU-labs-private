#pragma once
#include "Student.h"
#include <iostream>

using namespace std;

class Student_1 : public Student
{
protected:
	//int mas_1[4];
	int* mas_1;
	Student_1() : Student() 
	{
		for (int i = 0; i < 4; ++i)
			mas_1[i] = 0;
	}
	void Erase(int*);
public:
	Student_1(const char*, int, int, const int&, const int*);
	~Student_1();
	//конструктор копирования
	Student_1(const Student_1&);
	

	void setMas_1(int*);
	int* getMas_1();
	int getMas11();

	virtual double Average_Point();

	friend ostream& operator<<(ostream&, const Student_1&);

};
