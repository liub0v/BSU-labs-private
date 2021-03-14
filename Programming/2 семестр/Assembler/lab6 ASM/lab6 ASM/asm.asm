.386
.MODEL FLAT, stdcall
;
INCLUDE \Masm32\Include\Kernel32.inc
INCLUDELIB \Masm32\Lib\Kernel32.lib
;
.CODE
public spaceasm
 
spaceasm PROC s:dword, e:dword
    mov cx, 41
    lea esi, S
    lea edi, E
    xor ebx, ebx
    xor eax, eax
    xor edx, edx
    jmp mark3
mark1 :
    mov[edi], al
    inc di
    jmp mark2
mark2 :
    inc si
    dec cx
    cmp cx, 0
    je mark4
mark3 :
    mov bl, al
    mov al, [esi]
    cmp al, 32
    jne mark1
    cmp al, bl
    jne mark1
    jmp mark2
mark4 :
    ret
spaceasm ENDP
END