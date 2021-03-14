#include <iostream>

using namespace std;

int main() {
	int n,ans=pow(2,31)-1;
	cin >> n;
	int* x = new int [n*n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) cin >> x[j+i*n];
	}
	_asm {
	mov ecx,n
	_Loop1:
		
		xor esi,esi
		lea ebx,[ecx-1]
		mov edi,x
		lea edi,[edi+ebx*4]

		_Loop1_1:
			add esi,[edi]
			mov eax,n
			lea ebx,[ebx+eax+1]
			mov eax,ebx
			xor edx,edx
			div n
			cmp edx,0
			je _LP11
			mov edx,n
			lea edi,[edi+edx*4+4]
			jmp _Loop1_1
		_LP11:
		mov ebx,ans
		cmp esi,ebx
		jae _LP1
		mov ans,esi
		_LP1:
		loop _Loop1

	mov ecx,n

	_Loop2 :

		xor esi, esi
		mov edx,n
		mov eax,edx
		mov edx,ecx
		sub edx,1
		imul eax,edx
		mov edi, x
		lea edi, [edi + eax * 4]

		_Loop2_2 :
			add esi, [edi]
			mov edx,n
			lea eax, [eax + edx + 1]
			mov ebx, edx
			imul ebx,edx
			cmp eax, ebx
			ja _LP22
			lea edi, [edi + edx * 4+4]
			jmp _Loop2_2
		_LP22:
		mov ebx, ans
		cmp esi, ebx
		jae _LP2
		mov ans, esi
		_LP2 :
		loop _Loop2

	}
	cout << ans;
}