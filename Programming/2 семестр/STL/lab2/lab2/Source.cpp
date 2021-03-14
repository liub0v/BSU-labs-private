#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
	string name;
	int cr;
	int gr;
};

int compareName(Student s1, Student s2)
{
	return s1.name < s2.name;
}

int compareGroup(Student s1, Student s2)
{
	if (s1.cr == s2.cr)
	{
		if (s1.gr == s2.gr)
		{
			return s1.name < s2.name;
		}
		else
			return s1.gr < s2.gr;
	}
	else
		return s1.cr < s2.cr;
}

int main()
{
	ifstream file("Students.txt");
	ofstream Fio("FIO.txt");
	ofstream Group("Group.txt");
	if (!file)
	{
		cout<< "An error occurred opening the file"<< endl;
		system("pause");
		exit(0);
	}
	if (file.peek() == EOF)
	{
		cout<< "Empty file!"<< endl;
		system("pause");
		exit(0);
	}
	int course, group;
	vector <Student> Vst;
	Student st;
	string FIO;
	const int line = 20;
	while (file >> FIO && file >> course && file >> group)
	{
		st.name = FIO;
		st.cr = course;
		st.gr = group;
		Vst.push_back(st);
	}
	
	file.close();
	
	sort(Vst.begin(), Vst.end(), compareName);
	for (auto student = Vst.begin(); student != Vst.end(); student++)
		Fio << student->name << " " << student->cr << " " << student->gr << endl;

	sort(Vst.begin(), Vst.end(), compareGroup);
	for (auto student = Vst.begin(); student != Vst.end(); student++)
		Group << student->name << " " << student->cr << " " << student->gr << endl;


	system("pause");
	return 0;
}