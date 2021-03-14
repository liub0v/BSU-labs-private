#include <iostream>
using namespace std;
void main()
{
	int x;
	cin >> x;
	int res1,res2,res3;
	
	_asm
	{
		mov eax, x
		imul x
		imul x
		imul x
		imul x

		mov ebx, eax

		mov eax, x
		imul x
		sub eax, 4
		mov ecx, 2
		imul ecx
		add ebx, eax

		add ebx, x

		mov eax, x
		imul x
		imul x


		mov ecx, eax
		mov eax, ebx

		idiv ecx
		mov res1, eax
	}
	_asm
	{
		mov eax, x
		imul x

		mov ecx, 4
		imul ecx

		sub eax, 1
 
		mov ebx, eax
		mov eax, x
		add eax, 3
		imul ebx
		
		mov ecx, eax
		mov eax, 2
		imul eax, x
		mov ebx, eax
		mov eax, ecx
		div ebx
		mov res2, eax
	}
	_asm
	{
		mov eax, 16
		imul x
		imul x
		sub eax, 1

		mov ebx, 4
		idiv ebx
		mov res3, eax

	}
	cout << "Assembler:" << endl;
	cout << "result1: " << res1 << endl;
	cout << "result2: " << res2 << endl;
	cout << "result3: " << res3 << endl;
	res1 = (x*x*x*x*x + 2 * (x*x - 4) + x) / (x*x*x);
	res2 = (2 * x - 1)*(2 * x + 1)*(x + 3) / (2 * x);
	res3 = (4 * x - 1)*(4 * x + 1) / 4;
	cout << "C++:" << endl;
	cout << "result1: " << res1 << endl;
	cout << "result2: " << res2 << endl;
	cout << "result3: " << res3 << endl;
	system("pause");

 }