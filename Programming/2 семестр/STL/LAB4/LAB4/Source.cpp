#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
#include <functional>
#include <numeric>
using namespace std;

int compare(string s1, string s2)
{
	return s1 < s2;
}
void main()
{
	setlocale(LC_ALL, "rus");
	ifstream file("File.txt");
	if (!file)
	{
		cout << "An error occurred opening the file" << endl;
		system("pause");
		exit(0);
	}
	if (file.peek() == EOF)
	{
		cout << "Empty file!" << endl;
		system("pause");
		exit(0);
	}
	vector<string> v; 
	string str;
	while (file >> str)
	{
		v.push_back(str);

	}
	for (int i = 0; i<v.size(); i++)
	{
		cout << v[i] << endl;
	}
	cout << "--Отсортированный список--\n";
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i<v.size(); i++)
	{
		cout << v[i] << endl;
	}
	cout << endl << "Введите букву ";
	char s;
	cin >> s;
	int x = count_if(v.begin(), v.end(), [&](string str) {return str[0] == s; });
	if (x == 0)
		cout << "!Таких слов не найдено!";
	vector <string> ::iterator it;
	cout << "Слова начивающиеся с заданной буквы(B): \n ";
	for (int j = 0; j < x; j++)
	{
		it = find_if(v.begin(), v.end(), [&](string str) {return str[0] == s; });
		cout << *it << endl;
		v.erase(it);
	}
	cout << "\nСписок без этих слов:\n ";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	//////////////////////////////////////////////////////////
	ifstream file1("File1.txt");
	if (!file1)
	{
		cout << "An error occurred opening the file" << endl;
		system("pause");
		exit(0);
	}
	if (file1.peek() == EOF)
	{
		cout << "Empty file!" << endl;
		system("pause");
		exit(0);
	}
	vector<int> v1;
	int str1;
	while (file1 >> str1)
	{
		v1.push_back(str1);

	}
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}cout << endl;
	int n;
	cout << "Ввeдите число(6) \n";
	cin >> n;
	cout << "Количесвто повторений этого числа в файле: ";
	cout << count(v1.begin(), v1.end(), n) << endl;
	cout << "Количество чисел в векторе: "<<v1.size() << endl;
	cout << "Сумма чисел в файле: " << accumulate(v1.begin(), v1.end(), 0) << endl;
	cout << "Среднее ариметическое чисел: " << (double)(accumulate(v1.begin(), v1.end(), 0))/(v1.size()) << endl;
	cout << "Количество чисел, равных заданному : " << count_if(v1.begin(), v1.end(), [&](int a) {return a == n; }) << endl;
	cout << "Количесво чисел больших чем 15 : " << count_if(v1.begin(), v1.end(), [&](int a) {return a > 15; }) << endl;
	
	system("pause");
}
