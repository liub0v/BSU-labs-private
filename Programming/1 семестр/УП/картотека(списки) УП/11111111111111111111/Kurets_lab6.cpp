#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;
const int l_name = 10;
struct kartoteka
{
	char name[l_name];
	long int number;
	int time;
	kartoteka* next;
};
kartoteka* read_dbase(const char* filename);
kartoteka* add(kartoteka* beg, const kartoteka &kar);
int edit(kartoteka* beg);
kartoteka* find(kartoteka* pv, char* name, kartoteka** prev);
void find_kar(kartoteka* beg);
void get_name(char* name);
int menu();
void print_dbase(kartoteka* beg);
kartoteka new_element();
kartoteka* remove(kartoteka* beg);


int main()
{
	kartoteka* beg;
	beg = read_dbase("dbase.txt");
	while (true)
	{
		switch (menu())
		{
		case 1: add(beg, new_element()); break;
		case 2: beg = remove(beg); break;
		case 3: find_kar(beg); break;
		case 4: edit(beg); break;
		case 5: print_dbase(beg); break;
		case 6: return 0;
		case 7: puts("only 1-6"); break;
		}
	}
	return 0;
	system("pause");
}
kartoteka* add(kartoteka* beg, const kartoteka &kar)// ввести пустое имя невозможно
{
	kartoteka* pv = new kartoteka;
	pv->next = 0;
	strcpy(pv->name, kar.name);
	pv->number = kar.number;
	pv->time=kar.time;

	if (beg)
	{
		kartoteka* temp = beg;
		while (temp->next)
			temp = temp->next;
		temp->next = pv;
	}
	else
		beg = pv;
	return beg;
}
kartoteka* read_dbase(const char* filename)
{
	FILE* fin;
	kartoteka kar, *beg = 0;
	if ((fin = fopen(filename, "r")) == 0)
	{
		printf(("no file %s\n"), filename);
		return 0;
	}
	while (!feof(fin))
	{
		fgets(kar.name, l_name, fin);
		fscanf(fin, "%i %i",&kar.number, &kar.time);
		beg = add(beg, kar);
	}
	fclose(fin);
	return beg;
}

int edit(kartoteka* beg)
{
	char name[l_name], buf[80];
	get_name(name);
	kartoteka* prev;
	kartoteka* pv = find(beg, name, &prev);
	if (!pv) return 1;
	do
	{
		cout << "Enter new numder: ";
		cin >> buf;
	} while (!(pv->number = (int)atof(buf)));
	return 0;
}
kartoteka* find(kartoteka* pv, char* name, kartoteka** prev)
{
	*prev = 0;
	while (pv)
	{
		if (strstr(pv->name, name))
		{
			printf("%30s%11i%10i\n", pv->name, pv->number, pv->time);
			return pv;
		}
			
		*prev = pv;
		pv = pv->next;
	}
	cout << "Not found\n";
	return 0;
}
void get_name(char* name)
{
	while (true)
	{
		cout << " Entrer the name: ";
		cin >> name;
		if (strlen(name) <= 10)
			break;
		cout << "only 10 characters!" << endl;
		
	}
}
int menu()
{
	char buf[10];
	int option;
	do {
		cout << "------------------------" << endl;
		cout << "1 - add" << endl;
		cout << "2 - remove " << endl; 
		cout << "3 - find" << endl;
		cout << "4 - edit " << endl;
		cout << "5 - output the base" << endl;
		cout << "6 - exit" << endl;
		cout << "------------------------" << endl;
		cin >> buf;
		option = atoi(buf);
	} while (!option);
	return option;
}
kartoteka new_element()// ввод информации о сотруднике
{
	kartoteka kar; char buf[80];
	get_name(kar.name);
	for (int i = strlen(kar.name); i < l_name; i++)
		kar.name[i] = ' ';
	kar.name[l_name - 1] = '\0';
	do
	{
		cout << "Enter the number: ";
		cin >> buf;
	} while (!(kar.number = atoi(buf)));
	do
	{
		cout << "Enter the time: ";
		cin >> buf;
	} while (!(kar.time = atof(buf)));

	return kar;
}
void find_kar(kartoteka* beg)
{
	char buf[l_name];
	int numder, time, pay;
	get_name(buf);
	kartoteka *prev;
	kartoteka *pv = find(beg, buf, &prev);
}
kartoteka* remove(kartoteka* beg)
{
	char name[l_name];
	get_name(name);
	kartoteka* prev;
	kartoteka*pv = find(beg, name, &prev);
	if (pv)
	{
		if (pv == beg)
			beg = beg->next;
		else
			prev->next = pv->next;
		delete pv;
	}
	return beg;
}


void print_dbase(kartoteka* beg)
{
	cout << "The call rate is 3$ per minute\n";
	cout << "Name      Number  Time Payment\n";
	kartoteka* pv = beg;
	while (pv)
	{
		printf("%s %i %4i %7i\n", pv->name, pv->number, pv->time, pv->time*3);
		pv = pv->next;
	}
}