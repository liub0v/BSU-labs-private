#pragma once
#include "Student1.h"

class Student_2 : public Student_1
{
private:
	int* mas_2;
	Student_2() : Student_1()
	{
		for (int i = 0; i < 5; ++i)
			mas_2[i] = 0;
	}
	void Erase2(int*);
public:
	Student_2(const char*, int, int, const int&, int*, int*);
	~Student_2();

	//конструктор копирования
	Student_2(const Student_2&);

	void setMas_2(int*);
	int* getMas_2();
	int getMas_21();
	double Average_Point();

	friend ostream& operator<<(ostream&, const Student_2&);
};
