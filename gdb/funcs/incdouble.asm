; funcion que incrementa en una unidad un double
	global incdouble
	section .data
uno	dq	1.0
	section .text
incdouble:
	addsd	xmm0,	[rel uno]
	ret
