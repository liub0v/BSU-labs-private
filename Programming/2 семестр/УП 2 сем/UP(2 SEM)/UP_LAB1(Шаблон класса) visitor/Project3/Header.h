#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;



class avto {
private:
	int number = 0;
	string data ;
	char* Name;
public:
	avto() { Name = new char[1]; };
	avto(int n, string d, char* Name);
	bool operator==(avto&x);
	bool operator>(avto&x);
	avto* operator=(const avto&x);
	friend ostream& operator<<(ostream& cout, const avto&x);
};

avto::avto(int n, string d, char*N) :number(n), data(d) {
	Name = new char[strlen(N)];
	strcpy_s(Name, strlen(N) + 1, N);
}

bool avto::operator==(avto& x) {
	return (number == x.number&&data == x.data && !strcmp(Name, x.Name));
}

bool avto::operator>(avto& x) {
	if (number > x.number) return true;
	if (number < x.number) return false;
	if (data > x.data) return true;
	if (data < x.data) return false;
	return (strcmp(Name, x.Name) > 0);
}

avto* avto::operator=(const avto& x) {
	Name = new char(strlen(x.Name));
	strcpy_s(Name, strlen(x.Name) + 1, x.Name);
	number = x.number;
	data = x.data;
	return this;
}

ostream& operator<<(ostream& cout, const avto&x) {
	cout << "Number: " << x.number <<" "<< " Brand: " << x.Name;
	return cout;
}