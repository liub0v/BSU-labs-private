.486
public _funk
.model flat

.code 
_funk proc

;-2.4x^2-2.5/(x+11)+4.1=0

fmul st, st(4)
fmul st, st(4)
fadd st, st(1)
fxch st(4)
fadd st, st(2)
fxch st(3)
fdiv st, st(3)
fadd st, st(4)
 
ret
_funk endp
end