// реализовать картотеку на бинарном дереве 
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <io.h>
#include <math.h>
using namespace std;
const char* filename = "dbase.txt";

const double tarif = 12.34f;

struct node
{
	unsigned long tel;
	long time;
	char fio [64];
	node * r; // указатель на левого потомка
	node * l; // указатель на правого потомка
};


bool check(char * s) //проверка, является ли числом 
{
	int l = strlen(s);
	for (int i = 0; i < l; i++)
		if (!isdigit(s[i]))return false;
	return true;
}

node * find(node * root, unsigned long tel) //поиск  
{
	node * p = root;
	node * pv = root;
	int f = 0;
	while (pv && !f)
	{
		p = pv;
		if (tel == pv->tel)
		{
			f = 1;
		}

		if (pv && (tel < pv->tel)) pv = pv->l;
		else if (pv && (tel > pv->tel)) pv = pv->r;
	}

	if (f) return pv;
	return NULL;
}


node * add(node ** root, unsigned long tel, char * fio) // добавление  
{
	node * p = *root;
	node * pv = *root;
	bool f = 0;

	if (!pv)
	{
		node * t = new node;
		strcpy(t->fio, fio);
		t->tel = tel;
		t->l = 0;
		t->r = 0;
		t->time = 0;
		*root = t;
		return t;
	}

	while (pv && !f)
	{
		p = pv;
		if (tel == pv->tel)
		{
			f = 1;
			cout << "This user is already exists." << endl;
		}

		if (pv && (tel < pv->tel))
			pv = pv->l;
		else
			if (pv && (tel > pv->tel))
				pv = pv->r;
	}

	if (f) 
		return pv;

	node * pnew = new node;
	strcpy(pnew->fio, fio);
	pnew->tel = tel;
	pnew->l = 0;
	pnew->r = 0;
	pnew->time = 0;

	if (tel < p->tel) p->l = pnew;
	else if (tel > p->tel) p->r = pnew;

	return pnew;
}

int numCheck(int a)//проверка на корректность введенного номера 
{
	int c;
	c = 0;
	while (exp(c*log(10.0)) <= a)
		c++;
	return c;
}
unsigned long getnum() // ввод номера телефона
{
	char tel[128];
	unsigned long t;
	printf("Enter telephone number(Telephone number must consist of 7 digits): ");
	cin>>tel;
	if (strlen(tel) > 7) { printf("Telephone number must consist of 7 digits!\n"); return 0; }
	if (!check(tel)) { printf("Telephone number must consist of digits only!\n"); return 0; }
	tel[7] = '\0';
	sscanf(tel, "%d", &t);
	if (numCheck(t) < 7) { printf("Number can't start with zeros and be not 7 digits!\n"); return 0; }
	return t;
}
unsigned long gettimе() // ввод времени
{
	char tel[128];
	unsigned long t;
	printf("Enter time: ");
	cin>>tel;
	if (strlen(tel) > 7) { printf("Number is too big.\n"); return 0; }
	if (!check(tel)) { printf("Number must consist of digits only!\n"); return 0; }
	tel[7] = '\0';
	sscanf(tel, "%d", &t);
	return t;
}
void output(node * root) // вывод информации
{

	unsigned long t;

	if (!(t = getnum())) return;
	node * p = find(root, t);
	if (!p) { printf("There is no entry with number %d\n", t); return; }
	printf("Telephone number: %d\n", p->tel);
	printf("Name            : %s\n", p->fio);
	if (p->time >= 0)
	{
		printf("Time not paid   : %d\n", p->time);
		printf("Money to pay    : %3.3f $\n", p->time*tarif);
	}
	if (p->time < 0)
	{
		printf("Time  paid      : %d\n", abs(p->time));
		printf("Money paid      : %3.3f $\n", abs(p->time*tarif));
	}

}

void getname(node ** root) // ввод имени 
{
	char fio [64];
	unsigned long t;

	if (!(t = getnum())) 
		return;

	printf("Enter name (Surname_Name_Patronymic): ");
	cin>>fio;
	int l = strlen(fio);
	for (int i = 0; i < l; i++)
		if ((fio[i] == ' ') || (fio[i] > 0 && fio[i] < 10) || (l > 64))
			cout << "Mistake!";

	add(root, t, fio);
}


void print(node * t, int l) //вывод телефона
{
	if (!t)
		return;
	if (t->r)
		print(t->r, l + 1);

	for (int i = 0; i < l; i++) 
		cout << "";
	printf("%d\n", t->tel);

	if (t->l)
		print(t->l, l + 1);
}
 

void printTelFio(node * t, int l) // вывод телефона и фио
{
	if (!t)
		return;
	if (t->r)
		printTelFio(t->r, l + 1);

	printf("%d-%s\n", t->tel, t->fio);

	if (t->l) 
		printTelFio(t->l, l + 1);
}



void readFromFile(node ** root, const char * filename) // чтение из файла
{
	char ts[128], fio[32];
	unsigned long tel;
	long time;
	node * t;
	if (_access(filename, 0)) return;
	FILE * f = fopen(filename, "r");
	do
	{
		if (fgets(ts, 128, f)) {
			sscanf(ts, "%d %d %s\n", &tel, &time, fio);
			t = add(root, tel, fio);
			t->time = time;
		}
	} while (!feof(f));
	fclose(f);
}


void addtime(node * root) //добовление времени
{
	node * t;
	long num, tim;
	if (!(num = getnum())) return;
	if (!(tim = gettimе())) return;

	if (!(t = find(root, num))) printf("User with number %d doesn't exist.\n", num);

	t->time = t->time + tim;
}


void menu()
{
	printf("m - menu\n");
	printf("q or Q - quit\n");
	printf("1 - add user\n");
	printf("2 - print tree\n");
	printf("3 - print numbers and names\n");
	printf("4 - print detailed info on number\n");
	printf("5 - add unpaid call time to new user\n");
	
	
}

void outm(node*root)
{

}

void main()
{
	node * root = 0;
	printf("Telephone numbers in our base must be 7 digits long and not start with zeros.\n");
	printf("Enter m for menu\n");

	char t;
	int q = 0;
	readFromFile(&root, filename);
	while (!q)
	{
		printf("cmd:>");
		cin>>t;
		if ( ((t > '5') && (t<'10')) && (t != 'm') && (t != 'q') && (t != 'Q'))
		{
			cout << "Mistake!" << endl;
			system("pause");
			exit(0);
		}
		switch (t)
		{
		case 'q':
		case 'Q': q = 1; break;
		case 'm': menu(); break;
		case '1': getname(&root); break;
		case '2': print(root, 0); break;
		case '3': printTelFio(root, 0); break;
		case '4': output(root); break;
		case '5': addtime(root); break;
		}
	}

	system("pause");
}