.486
PUBLIC _TestCdecl
.model flat
.code
_TestCdecl proc

local res: dword,
      i: dword,
	  hlp: dword,
	  n: dword,
	  a: dword,
	  b: dword
mov i, 0
mov a, esp

mov eax, [ebp + 8]
mov n, eax
mov eax, [ebp + 12]
mov res, eax
mov eax, [ebp + 16]
mov a, eax
xor eax, eax

mov		ebx, a
		mov		ecx, n
	cycle2:

		push	ecx
		mov		ecx, n
		xor		edi, edi
		cycle1:
		
			mov		eax, [ebx + edi]
			add		edi, 4
			mov		hlp, eax

			


			
			cmp		i, edi
		JL	higher
			mov		eax, res
			mul		hlp
			mov		res, eax

				
	
		higher:
			
		loop cycle1
			mov		eax, 4
			mul		n
			add		ebx, eax
			pop		ecx
			mov		eax, 4
			add		i, eax
	loop cycle2
	mov eax, res
	mov esp, a
ret
_TestCdecl endp
end