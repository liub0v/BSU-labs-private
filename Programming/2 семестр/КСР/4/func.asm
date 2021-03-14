.486
public _f
.model flat

.code 
_f proc

;sin(x^2) + 5*x

fld st(0)
fmul st, st(1)
fsin
fxch st(1)
fmul st, st(2)
faddp st(1), st

ret
_f endp
end