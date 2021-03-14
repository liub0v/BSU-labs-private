#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
#include <stdlib.h>

using namespace std;
char *_strcat(char *strDestination, const char *strSource)
{
	char* A = strDestination;
	while (*strDestination)
		strDestination++;
	while(*strSource)
	{
		*strDestination = *strSource;
		*strDestination++;
		*strSource++;
	}
	*strDestination = '\0';
	return A;
}
void main()
	{
	char *s1;
	int n;
	cout << " n = ";
	cin >> n;
	s1 = new char[n + 1];
    char *s2;
	int m;
	cout << " m = ";
	cin >> m;
	s2 = new char[m + 1];
	//cin >> s1 >> s2;
	cin.getline(s1, n);
	cin.getline(s2, m);
	cout << strcat(s1, s2) << endl;
	cout << _strcat(s1, s2) << endl; 
	system("pause");
	}
