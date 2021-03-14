#include <iostream>
using namespace std;

int main()
{
	short num;
	cout << "Enter num"<<endl;
	cin >> hex >> num;
	
	
		num = ((num << 1) & 0xAAAA) | ((num >> 1) & 0x5555);
		num = ((num << 1) & 0x7777) | ((num >> 1) & 0x8888);
		num = ((num << 2) & 0xCCCC) | ((num >> 2) & 0x3333);
		num = ((num << 4) & 0x0F0F) | ((num >> 4) & 0xF0F0);
		
	
		cout << "result " << hex << num << "\n";

	system("pause");
	return 0;
}