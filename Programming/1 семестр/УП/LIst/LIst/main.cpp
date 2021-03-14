#include <iostream>
#include "List.h"
using namespace std;
void main()
{
	List <int> List_int;
	List <double> List_double;
	List <string> List_string;
	try {
		for (int i = 1; i < 10; ++i)
			List_double.add(i*0.002);
		List_double.print();
		for (int i = 0; i < 10; ++i)
			List_int.add(i + 2);
		List_int.print();
		List_string.add("string");
		List_string.add("string1");
		List_string.add("string2");
		List_string.print();
		cout <<endl<< "2:";
		cout << List_int.find(2) << endl;

	}
	catch (const char e)
	{
		cout << e << endl;
	}
	cout << endl;



	system("pause");
}