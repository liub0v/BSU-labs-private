/*Обратная польская запись реализованная на стеке через массив*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>

#define MaxLength 300
using namespace std;

bool BalanceBrackets(char *s, int top, int *staсk)
{

	for (int i = 0; i < strlen(s); i++)
	{
		switch (s[i])
		{
		case '(': { staсk[top] = s[i]; top++; } break;
		case '{': { staсk[top] = s[i]; top++; } break;
		case '[': { staсk[top] = s[i]; top++; } break;
		case ')': if (top == 0 || staсk[top - 1] == '{' || staсk[top - 1] == '[')  return false;
				  else { top--; } break;
		case '}': if (top == 0 || staсk[top - 1] == '[' || staсk[top - 1] == '(')  return false;
				  else { top--; } break;
		case ']': if (top == 0 || staсk[top - 1] == '{' || staсk[top - 1] == '(')   return false;
				  else { top--; }break;
		}

	}
	if (top != 0)  return false;

}
bool isOperation(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}
bool isDigit(char c)
{
	return  (c >= '0' && c <= '9');
}
int Calculate(int a, int b, char c)
{
	switch (c)
	{
	case('+'): return a + b;
	case('-'):return a - b;
	case('*'):return a * b;
	case('/'): return a / b;
	}
}
int Priority(char operation)
{
	return
		operation == '+' || operation == '-' ? 1 : operation == '*' || operation == '/' ? 2 : -1;
}
void OPZ(char *str, char*s, int *staсk)
{
	char *endptr;
	int j = 0;
	int top = 0;
	for (int i = 0; i < strlen(s); i++)
	{

		if (s[i] == '(')
		{

			staсk[top] = s[i];
			top++;
		}
		if (s[i] == ')')
		{
			while (staсk[top - 1] != '(') { str[j] = staсk[top - 1];  j++; str[j] = ' '; j++; top--; }
			top--;
		}
		if (isDigit(s[i]))
		{
			while (isDigit(s[i])) { str[j] = s[i]; j++; i++; }
			str[j] = ' ';
			i--;
			j++;
		}
		if (isOperation(s[i]))
		{
			while (top > 0 && (staсk[top - 1] != '(' && Priority(s[i]) <= Priority(staсk[top - 1]))) { str[j] = staсk[top - 1]; top--; j++; str[j] = ' '; j++; }
			staсk[top] = s[i]; top++;
		}
	}
	if (top != 0)
	{
		while (top > 0)
		{
			if (staсk[top - 1] == '(') top--;
			str[j] = staсk[top - 1]; j++; str[j] = ' '; j++; top--;
		}
	}
	cout << "Обратная польская запись: " << endl;
	for (int i = 0; i <= j - 1; i++)
		cout << str[i];
	cout << endl;


}
void Calculation(char *str, double *digits)
{
	int top = 0;
	double z;
	char *endptr;
	char *ptr;
	ptr = strtok(str, " ");
	for (; ptr != NULL; ptr = strtok(NULL, " "))
	{
		if (isDigit(*ptr))
		{

			digits[top] = strtol(ptr, &endptr, 10); top++;
		}
		if (isOperation(*ptr))
		{
			z = Calculate(digits[top - 2], digits[top - 1], ptr[0]);
			top--;
			digits[top - 1] = z;
		}
	}

}
int main()
{
	setlocale(LC_ALL, "rus");
	int *staсk, top = 0;
	double *digits = new double[MaxLength];
	char *s = new char[MaxLength + 1];
	staсk = new int[strlen(s)];
	char *str = new char[strlen(s)];
	cout << "Введите выражение(не более 300 символов):" << endl;
	cin.getline(s, MaxLength);
	char mas[] = { '(','{','[',')',']','}','+','-','*','/','1','2' ,'3' ,'4' ,'5','6' ,'7' ,'8' ,'9','0' };
	int k = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (s[i] == mas[j]) k++;
		}

	}
	if (k < strlen(s)) { cout << "Некорректно задана операция" << endl; system("pause"); return 0; }
	else
	{
		if (BalanceBrackets(s, top, staсk))
		{
			cout << "Cкобки расставлены правильно" << endl;
			for (int i = 0; i < strlen(s); i++)
			{
				if (s[i] == '{' || s[i] == '[') s[i] = '(';
				if (s[i] == '}' || s[i] == ']') s[i] = ')';
			}
		}
		else { cout << "Расставьте скобки правильно!" << "\n"; system("pause"); return 0; }

		if (BalanceBrackets(s, top, staсk))
		{
			OPZ(str, s, staсk);
			Calculation(str, digits);
			cout << "Результат: " << "\n";
			cout << digits[top] << "\n";
		}
	}
	delete[] staсk;
	delete[] s;
	delete[] str;
	system("pause");
	return 0;
}