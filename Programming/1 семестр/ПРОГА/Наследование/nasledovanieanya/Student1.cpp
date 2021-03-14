#include "Student1.h"

void Student_1::Erase(int* mas)
{
	if (mas)
		delete[]mas;
}

Student_1::Student_1(const char* name, int course, int group, const int& n_creditcard, const int* mas1) : Student(name, course, group, n_creditcard)
{
	mas_1 = new int[4];
	for (int i = 0; i < 4; ++i)
		this->mas_1[i] = mas1[i];
}

Student_1::~Student_1()
{
	Erase(mas_1);
}

Student_1::Student_1(const Student_1& s) : Student(s), mas_1(s.mas_1) { }

void Student_1::setMas_1(int* mas1)
{
	delete this->mas_1;
	this->mas_1 = new int[20];
	for (int i = 0; i < 4; ++i)
		this->mas_1[i] = mas1[i];
}

int* Student_1::getMas_1()
{
	return mas_1;
}

int Student_1::getMas11()
{
	return mas_1[0];
}

double Student_1::Average_Point()
{
	double sum = 0;
	for (int i = 0; i < 4; ++i)
		sum += mas_1[i];
	return sum / 4;
}

ostream& operator<<(ostream& OS, const Student_1& s1)
{
	OS << (Student&)s1;
	OS << endl << "ќценки за первый семестр: ";
	for (int i = 0; i < 4; ++i)
		OS << s1.mas_1[i] << " ";
	return OS;
}

