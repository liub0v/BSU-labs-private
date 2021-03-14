#include "Student2.h"

void Student_2::Erase2(int* mas)
{
	if (mas)
		delete[]mas;
}

Student_2::Student_2(const char* name, int course, int group, const int& n_creditcard, int* mas1, int* mas2) : Student_1(name, course, group, n_creditcard, mas1)
{
	mas_2 = new int[5];
	for (int i = 0; i < 5; ++i)
		this->mas_2[i] = mas2[i];
}

Student_2::~Student_2()
{
	Erase2(mas_2);
}

Student_2::Student_2(const Student_2& s) : Student_1(s), mas_2(s.mas_2) { }

void Student_2::setMas_2(int* mas2)
{
	delete this->mas_2;
	this->mas_2 = new int[20];
	for (int i = 0; i < 5; ++i)
		this->mas_2[i] = mas2[i];
}

int* Student_2::getMas_2()
{
	return mas_2;
}

int Student_2::getMas_21()
{
	return mas_2[0];
}

double Student_2::Average_Point()
{
	double sum = 0;
	for (int i = 0; i < 4; ++i)
		sum += mas_1[i];
	for (int i = 0; i < 5; ++i)
		sum += mas_2[i];
	return sum / 9;
}

ostream& operator<<(ostream& OS, const Student_2& s1)
{
	OS << (Student_1&)s1;
	OS << endl << "ќценки за второй семестр: ";
	for (int i = 0; i < 5; ++i)
		OS << s1.mas_2[i] << " ";
	return OS;
}