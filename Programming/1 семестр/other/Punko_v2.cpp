/*
Тесты
Введите выражение для преобразования его в польскую инверсную запись
(32+654)*(54/(-54))
32 654 + 54 _54 / *
-686

Введите выражение для преобразования его в польскую инверсную запись
()+6
Неверная расстановка скобок

*/





#include<iostream>
#include<string.h>
#define MaxLen 80
using namespace std;



struct ListItem {
	char Data;
	double IntData;
	ListItem *Next;
};

struct Stuck {
	ListItem *First;
};

void Create(Stuck &aList) {
	aList.First = NULL;
}

void Push_front(Stuck &aList, char a) {
	ListItem *p = new ListItem;
	p->Data = a;
	p->Next = aList.First;
	aList.First = p;
}

void Pop_front(Stuck &aList) {
	if (aList.First != NULL) {
		ListItem* P = aList.First;
		aList.First = aList.First->Next;
		delete P;
	}
}

void Push_front(Stuck &aList, double a) {
	ListItem *p = new ListItem;
	p->IntData = a;
	p->Next = aList.First;
	aList.First = p;
}



bool IsBracketsGood(char *str) {
	Stuck s;
	Create(s);
	int i=0;
	bool err = true;
	while (i<strlen(str) && err)
	{
		if (str[i] == '('  || str[i] == '{' || str[i] == '[') Push_front(s, str[i]);
		else 
			switch (str[i]){
				case ')':	if (s.First != NULL && s.First->Data == '(') Pop_front(s);
							else err = 0; break;
				case '}':	if (s.First != NULL && s.First->Data == '{') Pop_front(s);
							else err = 0; break;
				case ']':	if (s.First != NULL && s.First->Data == '[') Pop_front(s);
							else err = 0; break;
				
			}
		i++;
	}
	if (s.First != NULL) err = 0;
	return err;
}


 double String_To_Int(char *str) {
	 int num = 0;
	int tmp = 0;
	int sign = 0;
	if (str[0] == '-')
	{
		sign = 1;
	}
	for ( int i = strlen(str) - 1, l = 1; i >= 0 + sign; --i, l *= 10) {
		if (str[i] >= '0' && str[i] <= '9') {
			tmp = str[i] - '0';
		}
		num += tmp * l;
	}
	if (sign == 1)
	{
		return -num;
	}
	else return num;

}

char *PolskaInversnaZapis(const char *str) {
	try {
		Stuck s;
		Create(s);
		int i = 0;
		int str_i = 0;
		char *strP = new char[strlen(str) * 2 + 2];
		while (i < strlen(str))
		{
			switch (str[i])
			{
			case '(':Push_front(s, str[i]); break;


			case ')':
				while (s.First->Data != '(')
				{
					strP[str_i] = s.First->Data; str_i++;
					strP[str_i] = ' ';  str_i++;
					Pop_front(s);
				}
				Pop_front(s); break;


			case'+': if (s.First == NULL) Push_front(s, str[i]);
					 else {
				do
				{
					if (s.First->Data == '(') {
						break;
					}
					else {
						strP[str_i] = s.First->Data; str_i++;
						strP[str_i] = ' ';  str_i++;
						Pop_front(s);
					}
				} while (s.First != NULL);
				Push_front(s, str[i]);
			} break;


			case'-':
				if (str[i - 1] == '(')
				{
					strP[str_i] = '_'; str_i++;
				}
				else {
					if (s.First == NULL) Push_front(s, str[i]);
					else {
						do
						{
							if (s.First->Data == '(') {
								break;
							}
							else {
								strP[str_i] = s.First->Data; str_i++;
								strP[str_i] = ' ';  str_i++;
								Pop_front(s);
							}
						} while (s.First != NULL);
						Push_front(s, str[i]);
					}
				}break;


			case'*':
				if (s.First == NULL) Push_front(s, str[i]);
				else {
					do
					{
						if (s.First->Data == '(' || s.First->Data == '+' || s.First->Data == '-') {
							break;
						}
						else {
							strP[str_i] = s.First->Data; str_i++;
							strP[str_i] = ' ';  str_i++;
							Pop_front(s);
						}
					} while (s.First != NULL);
					Push_front(s, str[i]);
				} break;


			case'/':
				if (s.First == NULL) Push_front(s, str[i]);
				else {
					do
					{
						if (s.First->Data == '(' || s.First->Data == '+' || s.First->Data == '-') {
							break;
						}
						else {
							strP[str_i] = s.First->Data; str_i++;
							strP[str_i] = ' ';  str_i++;
							Pop_front(s);
						}
					} while (s.First != NULL);
					Push_front(s, str[i]);
				} break;


			default:
				
				if (str[i]<'0' || str[i]>'9')
				{
					throw "Среди символов есть не числa и не знаки!!!";
				}
				while (str[i] >= '0' && str[i] <= '9') {
					strP[str_i] = str[i]; str_i++; i++;
				}
				i--; 
				strP[str_i] = ' '; 
				str_i++;
				break;
			}
			i++;
		}
		while (s.First != NULL) {
			strP[str_i] = s.First->Data; str_i++;
			Pop_front(s);
		}
		strP[str_i] = '\0';
		return strP;
	}
	catch (const char *str)
		{
		cout << str << endl;
		char *strP = new char[1]; strP[0] = '\0';
		return strP;
	}
	
}


double Accaunt(char *str) {
	try {
		if (strlen(str)==0)
		{
			throw "Нельзя вычислить значение выражения";
		}
		Stuck s;
		Create(s);
		char *tmp = new char[9];
		int i = 0;
		int tmp_i = 0;
		double  v1, v2;
		while (i < strlen(str))
		{

			switch (str[i])
			{

			case'+': v1 = s.First->IntData;
				Pop_front(s);
				v2 = s.First->IntData;
				Pop_front(s);
				Push_front(s, v1 + v2);
				i++;
				break;


			case'-':v1 = s.First->IntData;
				Pop_front(s);
				v2 = s.First->IntData;
				Pop_front(s);
				Push_front(s, v2 - v1);
				i++;

				break;

			case'*':v1 = s.First->IntData;
				Pop_front(s);
				v2 = s.First->IntData;
				Pop_front(s);
				Push_front(s, v1 * v2);
				i++;

				break;


			case'/':v1 = s.First->IntData;
				Pop_front(s);
				v2 = s.First->IntData;
				Pop_front(s);
				Push_front(s, v2 / v1);
				i++;
				break;


			default:
				tmp_i = 0;
				if (str[i] == '_') {
					tmp[tmp_i] = '-';
					tmp_i++;
					i++;
				}
				while (str[i] >= '0' && str[i] <= '9') {
					tmp[tmp_i] = str[i]; tmp_i++; i++;
				}
				tmp[tmp_i] = '\0';
				Push_front(s, String_To_Int(tmp));
				break;
			}
			i++;
		}

		return s.First->IntData;
	}
	catch (const char *str) {
		cout << str<<endl;
		return 0;
	}
}

int main() {
	setlocale(LC_ALL, ".1251");
	Stuck aStuck;
	int n, value;
	Create(aStuck);
	char *str = new char[MaxLen];
	
	cout << "Введите выражение для преобразования его в польскую инверсную запись" << endl; 
	cin.get(str, MaxLen);
	if (IsBracketsGood(str)) {
	cout << PolskaInversnaZapis(str) << endl;
	cout << Accaunt(PolskaInversnaZapis(str)) << endl;
	}
	else cout <<"Неверная расстановка скобок"<< endl;
	system("pause");
	return 0;
}