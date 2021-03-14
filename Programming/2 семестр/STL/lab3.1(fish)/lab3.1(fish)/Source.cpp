#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <set>
#include <string>
#include <iterator>
using namespace std;

void main() {
	ifstream fin("file.txt");
	if (!fin) {
		cerr << "File is not found";
		system("pause");
		exit(0);
	}
	if (fin.peek() == EOF) {
		cerr << "File is empty";
		system("pause");
		exit(0);
	}
	set<string> lake, fm1, fm2, fm3;
	string str;
	getline(fin, str);
	while (str != "") 
	{
		lake.insert(str);
		getline(fin, str);
	}
	getline(fin, str);
	while (str != "")
	{
		fm1.insert(str);
		getline(fin, str);
	}
	getline(fin, str);
	while (str != "") 
	{
		fm2.insert(str);
		getline(fin, str);
	}
	while (getline(fin, str))
	{
		fm3.insert(str);
	}

	set<string> tmp2, tmp1, result3, result1, result2;
	set<string>::iterator it;
	cout << "Fish that every fishman has:" << endl;
	set_intersection(fm1.begin(), fm1.end(), fm2.begin(), fm2.end(),
		inserter(tmp1, tmp1.begin()));
	set_intersection(tmp1.begin(), tmp1.end(), fm3.begin(), fm3.end(),
		inserter(result1, result1.begin()));
	for (it = result1.begin(); it != result1.end(); ++it) {
		cout << *it << " ";
	}
	cout <<endl<< "Fish that at least one fishman caught:"<<endl;
	set_union(fm1.begin(), fm1.end(), fm2.begin(), fm2.end(),
		inserter(tmp2, tmp2.begin()));
	set_union(tmp2.begin(), tmp2.end(), fm3.begin(), fm3.end(),
		inserter(result2, result2.begin()));
	for (it = result2.begin(); it != result2.end(); ++it) {
		cout << *it << " ";
	};
	cout <<endl<< "Fish that no one caught:"<<endl;
	set_difference(lake.begin(), lake.end(), result2.begin(), result2.end(),
		inserter(result3, result3.begin()));
	for (it = result3.begin(); it != result3.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	system("pause");

}

