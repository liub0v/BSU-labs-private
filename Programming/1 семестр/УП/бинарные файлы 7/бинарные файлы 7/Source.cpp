//Вариант 9 "Владелец телефона"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>  
#include <cstdlib> 
#include<Windows.h>

using namespace std;
void Change(char* filename, int s);
void addFromFile(char* filename);
void createFile(char *filename);
void print(char *filename);
void add(char *filename);
void del(char *filename, int);
void sortFile(char *filename);

struct base
{
	int key;
	char Name[15];
	char SurName[15];
	char DadName[15];
	char HomeAdress[300];
	int Phone;
};

int K = 0, n = sizeof(base);


int main()
{
	setlocale(LC_ALL, ".1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int c;
	char filename[20];
	int s;
	while (true)
	{
		cout << "Для начала создайте файл, дайте ему имя и считайте данные из файла \"input.txt\"" << endl;
		cout << "Введите номер пункта меню:" << endl;
		cout << "1. Создание файла" << endl;
		cout << "2. Считать данные из файла \"input.txt\"" << endl;
		cout << "3. Добавить новую запись" << endl;
		cout << "4. Редактировать запись по ключу" << endl;
		cout << "5. Посмотреть файл" << endl;
		cout << "6. Удалить элемент по ключу" << endl;
		cout << "7. Сортировать файл по сумме баллов за экзамены" << endl;
		cout << "8. Выход" << endl;
		cin >> c;
		cin.seekg(0, cin.beg);
		switch (c)
		{
		case 1:

			cout << "Введите имя файла, котoрый хотите создать" << endl;
			cin >> filename;
			createFile(filename);
			break;
		case 2:
			addFromFile(filename);
			break;
		case 3:
			add(filename);
			break;
		case 4:
			cout << "Введите Ключ элемена, который хотите изменить" << endl;
			cin >> s;
			Change(filename, s);
			break;
		case 5:
			print(filename);
			break;
		case 6:
			cout << "Введите Ключ элемена, который хотите удалить" << endl;
			cin >> s;
			del(filename, s);
			break;
		case 7:
			sortFile(filename);
			break;
		case 8:
			return 0;
		}
	}
}

void createFile(char *filename)
{

	ofstream f(filename, ios::out | ios::trunc);
	if (!f)
	{
		cout << "Ошибка при создании файла!" << filename << endl;
		return;
	}
	f.close();
	cout << "Файл создан успешно!" << endl;
	return;
}

void print(char* filename)
{
	ifstream f(filename, ios::in | ios::binary);
	if (!f)
	{
		cout << "Ошибка при открытии файла!" << filename << endl;
		return;
	}
	base *zap = new base;
	int k = 1;

	while (f.read((char*)zap, n))
	{
		cout << "№:" << k << endl;
		cout << "Ключ: " << zap->key << endl
			<< "Фамилия: " << zap->Name << endl
			<< "Имя: " << zap->SurName << endl
			<< "Отчество: " << zap->DadName << endl
			<< "Домашний адрес: " << zap->HomeAdress << endl
			<< "Номер телефона: " << zap->Phone << endl;
		k++;
	}
	if (k == 1)
		cout << "Нет записей в файле!" << endl;
	f.close();
	delete zap;
}

void addFromFile(char* filename)
{

	fstream f(filename, ios::app | ios::binary);
	ifstream f1("input.txt");
	if (!f || !f1 || !f1.is_open())
	{
		cout << "Ошибки при открытии файла!" << filename << endl;
		return;
	}
	base *zap = new base;
	while (!f1.eof())
	{
		K++;
		zap->key = K;
		f1 >> zap->Name;
		f1 >> zap->SurName;
		f1 >> zap->DadName;
		f1.getline(zap->HomeAdress, 300);
		f1 >> zap->Phone;
		f.write((char*)zap, n);
	}
	//f.close();
	delete zap;
	cout << "Информация добавлена" << endl;
}


void add(char* filename)
{

	fstream f(filename, ios::app | ios::binary);
	if (!f)
	{
		cout << "Ошибки при открытии файла!" << filename << endl;
		return;
	}
	base *zap = new base;
	cout << "Добавьте информацию о владельце" << endl;
	cout << "Фамилия: ";
	cin >> zap->Name;
	cout << "Имя: ";
	cin >> zap->SurName;
	cout << "Отчество: ";
	cin >> zap->DadName;
	char c;
	cin.get(c);
	cout << "Домашний адрес: ";
	cin.getline(zap->HomeAdress, 300);
	cout << "Номер телефона: ";
	cin >> zap->Phone;
	K++;
	zap->key = K;
	f.write((char*)zap, n);
	f.close();
	delete zap;
}

void Change(char* filename, int s)
{
	ifstream f(filename, ios::in | ios::binary);
	if (!f)
	{
		cout << "Ошибки открытия файла!" << filename << endl;
		return;
	}

	ofstream f1("temp", ios::out | ios::trunc | ios::binary);
	char str[100];
	int l;
	base *zap = new base;
	int k = 0;
	int c;
	char c1;
		
		cout << "Введите номер пункта меню, в соответствии с которым хотите заменить данные" << endl;
		cout << "1. Изменить фамилию" << endl;
		cout << "2. Изменить имя" << endl;
		cout << "3. Изменить отчество" << endl;
		cout << "4. Изменить адрес" << endl;
		cout << "5. Изменить номер телефона" << endl;
		cin >> c;


	cin.seekg(0, cin.beg);
	switch (c)
	{
	case 1:
		cout << "Введите Фамилию" << endl;

		cin.get(c1);
		cin.get(str, 15);
		cin.seekg(0, cin.beg);
		while (f.read((char*)zap, n))
		{
			if (s != zap->key)
				f1.write((char*)zap, n);
			else {
				strcpy(zap->Name, str);
				f1.write((char*)zap, n);
				k++;
			}

		}
		break;
	case 2:
		cout << "Введите Имя" << endl;
		cin.get(c1);
		cin.get(str, 15);
		cin.seekg(0, cin.beg);

		while (f.read((char*)zap, n))
		{
			if (s != zap->key)
				f1.write((char*)zap, n);
			else {
				strcpy(zap->SurName, str);
				f1.write((char*)zap, n);
				k++;
			}
		}
		break;
	case 3:
		cout << "Введите Отчество" << endl;
		cin.get(c1);
		cin.get(str, 15);
		cin.seekg(0, cin.beg);
		while (f.read((char*)zap, n))
		{
			if (s != zap->key)
				f1.write((char*)zap, n);
			else {
				strcpy(zap->DadName, str);
				f1.write((char*)zap, n);
				k++;
			}
		}
		break;
	
	
	
	case 4:
		cout << "Введите адрес" << endl;
		cin.get(c1);
		cin.get(str, 300);
		cin.seekg(0, cin.beg);
		while (f.read((char*)zap, n))
		{
			if (s != zap->key)
				f1.write((char*)zap, n);
			else {
				strcpy(zap->HomeAdress, str);
				f1.write((char*)zap, n);
				k++;
			}
		}
		break;
	case 5:
		cout << "Введите Номер телефона" << endl;
		int b; cin >> b;

		while (f.read((char*)zap, n))
		{
			if (s != zap->key)
				f1.write((char*)zap, n);
			else {
				zap->Phone = b;
				f1.write((char*)zap, n);
				k++;
			}
		}
		break;
	default:
		cout << "Неверный номер поля ключа" << endl;
		break;
	}

	f.close(); f1.close();
	if (k != 0)
	{
		remove(filename);
		rename("temp", filename);
	}
	delete zap;
}


void del(char* filename, int s)
{
	if (s<1 || s>K)
	{
		cout << "Неверный номер поля ключа" << endl;
	}
	else {
		ifstream f(filename, ios::in | ios::binary);
		if (!f)
		{
			cout << "Ошибка открытия файла!" << filename << endl;
			return;
		}
		ofstream f1("temp", ios::out | ios::trunc | ios::binary);
		base *zap = new base;
		int k = 0;
		while (f.read((char*)zap, n))
		{
			if (s != zap->key)
				f1.write((char*)zap, n);
			else
				k++;
		}
		f.close(); f1.close();
		if (k != 0)
		{
			remove(filename);
			rename("temp", filename);
		}
		delete zap;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
int Name_comp(const base* el1, const base* el2)
{
	return (strcmp(el2->Name, el1->Name));
}

int SurName_comp(const base* el1, const base* el2)
{
	return (strcmp(el2->SurName, el1->SurName));
}

int DadName_comp(const base* el1, const base* el2)
{
	return (strcmp(el2->DadName, el1->DadName));
}

int HomeAdress_comp(const base* el1, const base* el2)
{
	return (strcmp(el2->HomeAdress, el1->HomeAdress));
}

int Phone_comp(const base* el1, const base* el2)
{
	return (el2->Phone - el1->Phone > 0);
}

void sortFile(char *filename)
{
	fstream f(filename, ios::in | ios::out | ios::binary);
	if (!f)
	{
		cout << "Error opening file!" << filename << endl;
		return;
	}
	//Найдем количество записей в файле, переместив указатель текущей записи на конец
	f.seekg(0, ios::end);
	int n_record = f.tellg() / n; //возвращаем текущую позицию указателя ввода
	base x, y;
	short pcs;
	cout << "Введите признак для сортировки" << endl;
	cout << "1. Фамилия" << endl;
	cout << "2. Имя" << endl;
	cout << "3. Отчество" << endl;
	cout << "4. Домашний адрес" << endl;
	cout << "5. Номер телефона" << endl;
	cin >> pcs;
	while ((pcs < 1) || (pcs > 8))
	{
		cout << "Введите число от 1 до 8!" << endl;
		cin >> pcs;
	}
	int(*pointer) (const base*, const base*);
	pointer = NULL;
	switch (pcs)
	{
	case 1:
		pointer = Name_comp;
		break;
	case 2:
		pointer = SurName_comp;
		break;
	case 3:
		pointer = DadName_comp;
		break;
	case 4:
		pointer = HomeAdress_comp;
		break;
	case 5:
		pointer = Phone_comp;
		break;
	}
	for (int i = 0; i < n_record; i++)
	{
		f.seekg(0, ios::beg);
		for (int j = 0; j < n_record - i - 1; j++)
		{
			f.seekg(j * n, ios::beg);
			f.read((char*)&x, n);
			f.read((char*)&y, n);
			const base *a = &x;
			const base *b = &y;
			if (pointer != NULL)
			{
				if (pointer(a, b) > 0)
				{
					f.seekg(j * n, ios::beg);
					f.write((char*)&y, n);
					f.write((char*)&x, n);
				}
			}
		}
	}
	cout << "Сортировка выполнена" << endl;
	f.close();
}



