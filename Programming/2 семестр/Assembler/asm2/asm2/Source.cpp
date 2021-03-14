#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	unsigned _int16
		A1, B1, C1,
		A2, B2, C2,
		A3, B3, C3;
	cout << "Enter A1,A2,A3" << endl;
	cin >> A1 >> A2 >> A3;
	cout << "Enter B1,B2,B3" << endl;
	cin >> B1 >> B2 >> B3;

	unsigned _int32
		ex0;
	unsigned _int64
		ex,
		exf = 0;

	_asm
	{
		mov ax, A1
		add ax, B1

		mov C1, ax

		mov ax, A2
		adc ax, B2

		mov C2, ax

		mov ax, A3
		adc ax, B3

		mov C3, ax

		mov bx, C3
		mov word ptr ex + 4, bx

		mov bx, C3
		mov word ptr ex + 2, bx

		mov bx, C1
		mov word ptr ex, bx

		mov edx, 0
		mov ax, C3
		CWDE
		CDQ
		mov ebx, 100000
		imul ebx
		imul ebx

		mov dword ptr exf + 4, edx
		mov dword ptr exf, eax

		mov ax, C2
		CWDE
		CDQ
		imul ebx
		mov ecx, eax

		mov ax, C1
		CWDE
		add eax, ecx

		add dword ptr exf, eax


	}
	cout << "C3, C2, C1:" << endl;
	cout << hex << C3 << " ";
	cout << hex << C2 << " ";
	cout << hex << C1 << endl;
	cout << "number:" << endl;
	cout << dec << exf << endl;
	cout << hex << exf << endl;
	system("Pause");
	return 0;
}