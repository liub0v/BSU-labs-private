#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#define MAX 100

using namespace std;

void OPZ(char *str, char *outstr);
bool check2Brackets(char c1, char c2);
bool checkBrackets(char *str);
double solve(char *str);

void main()
{
	setlocale(LC_ALL, "rus");
	char *str = new char[MAX + 1], *outstr = new char[1], ch;
	cout << "Введите выражение: " << endl;
	cin.get(str, MAX + 1);
	if (checkBrackets(str))
	{
		OPZ(str, outstr);
		cout << "Значение выражения: " << endl;
		cout << solve(outstr) << endl;
	}
	else cout << "Скобки раставлены неверно" << endl;
	system("pause");
}


bool checkBrackets(char *str)
{
	int *stack = new int[MAX], top = 0, i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == '(')
		{
			stack[top++] = *(str + i);
		}
		else if (*(str + i) == ')')
		{
			if (top == 0) {
				return false;
			}
			else if (!check2Brackets(stack[--top], *(str + i)))
			{
				return false;
			}
		}
		i++;
	}
	return (top == 0 ? true : false);//?
}

bool check2Brackets(char c1, char c2)
{
	if (c1 == '(' && c2 == ')')
	{
		return true;
	}
	else return false;
}

double solve(char *str)
{
	double *stack = new double[MAX], a, b;
	int top = 0;
	char *token;
	token = strtok(str, " ");
	while (token != NULL) {
		if (*token == '+' || *token == '*' || *token == '/' || *token == '-')
		{
			switch (*token) {
			case ('+'):
				a = stack[--top];
				b = stack[--top];
				stack[top++] = b + a;
				break;
			case ('*'):
				a = stack[--top];
				b = stack[--top];
				stack[top++] = b * a;
				break;
			case '-':
				a = stack[--top];
				b = stack[--top];
				stack[top++] = b - a;
				break;
			case '/':
				a = stack[--top];
				b = stack[--top];
				stack[top++] = b / a;
				break;
			default:
				break;
			}
		}
		else
		{
			stack[top++] = atoi(token);
		}
		token = strtok(NULL, " ");
	}
	return stack[--top];
}

void OPZ(char *str, char *outstr)
{
	int i = 0, *stack = new int[MAX], top = 0, temp = 0;
	cout << "Обратная польская запись: " << endl;
	while (*(str + i) != '\0')
	{
		if (*(str + i) - 48 >= 0 && *(str + i) - 48 <= 9)
		{
			if (i == 0)
			{
				strncat(outstr, str + i, 1);
				cout << *(str + i);
			}
			else {
				if (*(str + i - 1) - 48 >= 0 && *(str + i - 1) - 48 <= 9)
				{
					strncat(outstr, str + i, 1);
					cout << *(str + i);
				}
				else
				{
					cout << " " << *(str + i);
					strncat(outstr, " ", 1);
					strncat(outstr, str + i, 1);
				}
			}
		}
		else {
			switch (*(str + i))
			{
			case '(':
				stack[top++] = *(str + i);
				break;
			case ')':
				while (true)
				{
					temp = stack[--top];
					if (temp != '(')
					{
						strncat(outstr, " ", 1);
						strncat(outstr, (char*)&temp, 1);
						cout << " " << (char)temp;
					}
					else break;
				}
				break;
			case ('+'):
				if (top == 0)
				{
					stack[top++] = *(str + i);
				}
				else
				{
					while (top != 0) {
						temp = stack[--top];
						if (temp == '(')
						{
							stack[top++] = temp;
							break;
						}
						else
						{
							strncat(outstr, " ", 1);
							strncat(outstr, (char*)&temp, 1);
							cout << " " << (char)temp;
						}
					}
					stack[top++] = *(str + i);
				}
				break;
			case '*':
				if (top == 0)
				{
					stack[top++] = *(str + i);
				}
				else {
					while (top != 0)
					{
						temp = stack[--top];
						if (temp == '(' || temp == '+' || temp == '-')
						{
							stack[top++] = temp;
							stack[top++] = *(str + i);
							break;
						}
						else
						{
							strncat(outstr, " ", 1);
							strncat(outstr, (char*)&temp, 1);
							cout << " " << (char)temp;
						}
					}

				}
				break;
			case '-':
				if (top == 0)
				{
					stack[top++] = *(str + i);
				}
				else
				{
					while (top != 0)
					{
						temp = stack[--top];
						if (temp == '(')
						{
							stack[top++] = temp;
							break;
						}
						else
						{
							strncat(outstr, " ", 1);
							strncat(outstr, (char*)&temp, 1);
							cout << " " << (char)temp;
						}
					}
					stack[top++] = *(str + i);
				}
				break;
			case '/':
				if (top == 0)
				{
					stack[top++] = *(str + i);
				}
				else {
					while (top != 0)
					{
						temp = stack[--top];
						if (temp == '(' || temp == '+' || temp == '-')
						{
							stack[top++] = temp;
							stack[top++] = *(str + i);
							break;
						}
						else
						{
							strncat(outstr, " ", 1);
							strncat(outstr, (char*)&temp, 1);
							cout << " " << (char)temp;
						}
					}

				}
				break;
			default:
				break;
			}
		}
		i++;
	}
	while (top != 0)
	{
		int o = stack[--top];
		strncat(outstr, " ", 1);
		strncat(outstr, (char*)&o, 1);
		cout << " " << (char)o;
	}
	cout << endl;
}