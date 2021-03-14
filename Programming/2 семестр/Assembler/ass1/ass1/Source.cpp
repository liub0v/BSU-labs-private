#include <iostream>
using namespace std;
void main() {
	/*int a,b,res;
	cout << "enter a,b>";
	cin >> a >> b;
	__asm
	{
		mov eax, a
		add eax, b
		mov res, eax
	}
	cout << res << endl;*/
	__int64 a = 2549768595467333, b = -1;
	cout << "a=" << a << ", b=" << b << endl;
	__asm 
	{
		mov eax, dword ptr a
		XCHG eax, dword ptr b
		mov dword ptr a, eax

		mov eax, dword ptr a+4
		XCHG eax, dword ptr b+4
		mov dword ptr a+4, eax
	}

	cout << "a=" << a << ", b=" << b << endl;

	system("pause");
 }