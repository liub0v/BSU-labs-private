#include <iostream>
#include <ctime>
#include "Student.h"
#include "Student1.h"
#include "Student2.h"
#include <typeinfo.h>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	char* name = new char[20];
	int course, group;
	Student s1("Иванов", 2, 1, 1823489), s2("Фихтенгольц", 1, 4, 1823568), s3("Петров", 1, 1, 1823265);
	cout << s1 << endl << s2 << endl << s3 << endl << endl;

	int* mark1 = new int[4];
	int* mark2 = new int[4];
	int* mark5 = new int[4];
	char* name1 = new char[20];
	for (int i = 0; i < 4; ++i)
	{
		mark1[i] = 1 + rand() % 10;
		mark2[i] = 1 + rand() % 10;
		mark5[i] = 1 + rand() % 10;
	}
	Student_1 s4("Пунько", 1, 2, 1823498, mark1), s5("Шнитко", 1, 2, 1823571, mark2);
	cout << "Студенты после первой сессии:\n";
	cout << s4 << endl << s5 << endl;
	cout << "Введите номер группы, в которой хотите посчитать средний балл\n";
	int n, k;
	double av = 0;
	cin >> n;
	if (s4.getGroup() == n)
	{
		av = s4.Average_Point();
		if (s5.getGroup() == n)
			av = (av + s5.Average_Point()) / 2;
	}
	else if (s5.getGroup() == n)
		av = s5.Average_Point();
	else if (s4.getGroup() != n && s5.getGroup() != n)
		cout << "Нет такой группы\n";
	cout << "Средний балл в указанной группе: " << av << endl << endl;

	int* mark3 = new int[5];
	int* mark4 = new int[5];
	char* name2 = new char[20];
	for (int i = 0; i < 5; ++i)
	{
		mark3[i] = 1 + rand() % 10;
		mark4[i] = 1 + rand() % 10;
	}
	Student_2 s7("Волынец", 2, 2, 1823421, mark2, mark3), s8("Бурко", 1, 4, 1823691, mark1, mark4);
	cout << "Студенты после второй сессии:\n";
	cout << "Введите фамилию, курс, номер группы, оценки после первой сессии и оценки после второй сессии\n";
	cin >> name2 >> course >> group;
	for (int i = 0; i < 4; ++i)
	{
		cin >> mark5[i];
	}
	for (int i = 0; i < 5; ++i)
	{
		cin >> mark4[i];
	}
	s8.setName(name2); s8.setCourse(course); s8.setGroup(group); s8.setMas_1(mark5); s8.setMas_2(mark4);
	cout << s7 << endl << s8 << endl;
	cout << "Введите номер группы, в которой хотите посчитать средний балл\n";
	cin >> n;
	if (s7.getGroup() == n)
	{
		av = s7.Average_Point();
		if (s8.getGroup() == n)
			av = (av + s8.Average_Point()) / 2;
	}
	else if (s8.getGroup() == n)
		av = s8.Average_Point();
	else if (s7.getGroup() != n && s8.getGroup() != n)
		cout << "Нет такой группы\n";
	cout << "Средний балл в указанной группе: " << av << endl << endl;

	Student* mas[5];
	mas[0] = new Student_2("Васьков", 1, 1, 1823274, mark2, mark4);
	mas[1] = &s5;
	mas[2] = &s7;
	mas[3] = &s4;
	mas[4] = &s8;
	double sum = 0;
	k = 0;
	for (int i = 0; i < 5; ++i)
	{
		if (typeid(*mas[i]) != typeid(s1))
		{
			if (typeid(*mas[i]) == typeid(s4))
			{
				sum += (*mas[i]).Average_Point() * 4;
				k += 4;
			}
			if (typeid(*mas[i]) == typeid(s7))
			{
				sum += (*mas[i]).Average_Point() * 9;
				k += 9;
			}
		}
	}
	cout << "Средний балл для массива равен " << sum / k << endl;

	system("pause");
	return 0;
}