/*
 Введите строку символов не более 80
54hbjh3543m38738738763n787
 Выделение чисел из строки:
54
787
3543
38738738763

 Введите строку символов не более 80
mhvjkgklh
 Выделение чисел из строки:
В исходной строке нет цифр

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <string.h>
#define MaxLength 80 
using namespace std;

bool isDigit(char c)
{
	return (c <= '9' && c >= '0');
}


char **mas_string(const char *str, char **&mass_s, int &k) {
	for (int i = 0; i < k; i++) {
		delete[] mass_s[i];
	}
	delete[] mass_s;
	char *str_copy = new char[strlen(str) + 1];
	char **mas_str = new char *[k];
	strcpy(str_copy, str);
	int i = 0;
	k = 0;
	while (i < strlen(str)){
		while (!isDigit(str[i]) && i < strlen(str)) i++;
		if (i < strlen(str)){
			mas_str[k] = &str_copy[i];
			k++;
			while (isDigit(str[i])) i++;
			str_copy[i] = '\0'; 
		}
	}

	if (k > 0){
		for (int i = k-1; i >=0; i--){
			for (int j = 0; j < i; j++)
				if (strlen(mas_str[j]) > strlen(mas_str[j + 1])){
					char*p = mas_str[j];
					mas_str[j] = mas_str[j + 1];
					mas_str[j + 1] = p;
				}
		}
	}
	else cout << "В исходной строке нет цифр"<<endl;
	mass_s = mas_str;
	return mass_s;
}






int main()
{
	setlocale(LC_ALL, ".1251");
	char str[MaxLength + 1];
	
	cout << " Введите строку символов не более " << MaxLength << endl;
	cin.get(str, MaxLength + 1);
	int len = strlen(str);
	int mass_size = len/2 + 1;
	char **mas_str1 = new char *[mass_size];
	for (int i = 0; i < mass_size; i++)
		mas_str1[i] = new char[len + 1];
	cout << " Выделение чисел из строки: " << endl;
	mas_str1 = mas_string(str, mas_str1,mass_size);
	cout << "\n";
	for (int i = 0; i < mass_size; i++)
		cout << mas_str1[i] << endl;

	delete[] mas_str1;
	system("pause");
	return 0;
}