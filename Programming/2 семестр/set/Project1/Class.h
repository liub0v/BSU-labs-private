
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
//---------------------------------------------------------------------------
//Объявление класса "Множество":
template <class T>
class set
{
private:
	T *a;
	int max_size;
	int size;
public:
	//Конструкторы:
	set(int maxim);
	set(set <T> &x);
	//Деструктор:
	~set();
	void add(T x);//добавление эл-та в мнохество
	void del(T &x);//удаление эл-та из множества
	bool check_in(T x);//проверка вхождения эл-та в множество
	void output();//Вывод множества на экран
	//void input();//Ввод множества на экран
	set<T> operator= (const set <T> &s);//операция: присвоение одного множества другому
	set<T> operator* (const set <T> &s2);//операция: пересечение двух множеств
	set<T> operator+ (const set <T> &s2);//операция: объединение двух множеств
	set<T> operator- (set <T> s2);//операция: разность двух множеств
	//friend bool operator== (set <T> s1, set <T> s2);//операция: сравнение двух множеств
	
};

template <class T>
void set<T> ::add(T x)
{
	if (size < max_size)
	{
		if (!check_in(x))
		{
			a[size] = x;
			size += 1;
			cout << "Добавление прошло успешно";
		}
		else
			cout << "Добавление невозможно";
	}
	else
		cout << "Добавление невозможно";
}
template <class T>
void set <T>::del(T &x)
{
	bool ok;
	ok = false;
	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (a[i] == x)
			{
				for (int j = i; j < size; j++)
				{
					a[j] = a[j + 1];
				}
				size -= 1;
				ok = true;;
			}
		}
		if (ok)
			cout << "Удаление прошло успешно";
	}
	else
		cout << "Удаление невозможно";
}
template <class T>
bool set <T>::check_in(T x)
{
	for (int i = 0; i < size; i++)
		if (a[i] == x)
			return true;
	return false;
}
template <class T>
void set<T>::output()
{
	if (size == 0)
	{
		cout << "{}";
		return;
	}
	cout << "{" << a[0];
	for (int i = 1; i < size; i++)
		cout << ", " << a[i];
	cout << "}";
}
//template<class T>
//inline void set<T>::input()

template <class T>
set<T> set<T>:: operator* (const set <T> &s2)
{
	int k;
	k = 0;
	set <T> s3(max_size);
	s3.size = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < s2.size; j++)
			if (s2.a[j] == a[i])
			{
				s3.a[k] = a[i];
				k++;
				s3.size += 1;
			}
	return s3;
}
template <class T>
set<T> set<T>::operator+ (const set <T> &s2)
{
	bool in;
	set <T> s3(size + s2.size);
	for (int i = 0; i < size; i++)
	{
		s3.a[i] = a[i];
		s3.size += 1;
	}
	for (int i = 0; i < s2.size; i++)
	{
		in = s3.check_in(s2.a[i]);
		if (!in)
		{
			s3.a[size] = s2.a[i];
			s3.size += 1;
		}
	}
	return s3;
}
template <class T>
set<T> set<T>::operator- (set <T> s2)
{
	set <T> s3(s2);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < s2.size; j++)
			if (a[i] == s2.a[j])
				for (int k = i; k < s3.size; k++)
				{
					s3.a[i] = s3.a[i + 1];
					size -= 1;
				}
	return s3;
}
template <class T>
set<T> set<T>:: operator= (const set <T> &s)
{
	if (this == &s)
		return *this;
	if (max_size != s.max_size)
	{
		delete[]a;
		a = new T[s.max_size];
		size = 0;
		max_size = s.max_size;
	}
	for (int i = 0; i < max_size; i++)
	{
		a[i] = s.a[i];
	}
	size = s.size;
	return *this;
}
//template <class T>
//bool operator== (set <T> s1, set <T> s2)
//{
//
//	bool ok;
//	ok = false;
//	for (int i = 0; i < s1.size; i++)
//	{
//		for (int j = 0; j < s2.size; j++)
//			if (a[i] == a[j])
//				ok = true;
//	}
//	return ok;
//}
template <class T>
set<T>::set(int maxim)
{
	a = new T[maxim];
	for (int i = 0; i < maxim; i++)
		a[i] = 0;
	max_size = maxim;
	size = 0;
}
template <class T>
set<T>::set(set<T> &x)
{
	max_size = x.max_size;
	a = new T[max_size];
	for (int i = 0; i < max_size; i++)
		a[i] = x.a[i];
}
template <class T>
set<T>::~set()
{
	delete[]a;
}


