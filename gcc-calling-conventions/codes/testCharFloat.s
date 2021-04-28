	.file	"testCharFloat.c"
	.intel_syntax noprefix
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 48
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -8[rbp], rax
	xor	eax, eax
	mov	BYTE PTR -38[rbp], 0
	mov	BYTE PTR -37[rbp], 1
	mov	BYTE PTR -36[rbp], 2
	mov	BYTE PTR -35[rbp], 3
	mov	BYTE PTR -34[rbp], 4
	mov	BYTE PTR -33[rbp], 5
	mov	BYTE PTR -32[rbp], 6
	mov	BYTE PTR -31[rbp], 7
	mov	BYTE PTR -30[rbp], 8
	mov	BYTE PTR -29[rbp], 9
	mov	BYTE PTR -28[rbp], 0
	mov	BYTE PTR -27[rbp], 1
	mov	BYTE PTR -26[rbp], 2
	mov	BYTE PTR -25[rbp], 3
	mov	BYTE PTR -24[rbp], 4
	mov	BYTE PTR -23[rbp], 5
	mov	BYTE PTR -22[rbp], 6
	mov	BYTE PTR -21[rbp], 7
	mov	BYTE PTR -20[rbp], 8
	mov	BYTE PTR -19[rbp], 9
	movss	xmm0, DWORD PTR .LC0[rip]
	movss	DWORD PTR -44[rbp], xmm0
	mov	DWORD PTR -48[rbp], 0
	jmp	.L2
.L3:
	mov	eax, DWORD PTR -48[rbp]
	cdqe
	movzx	eax, BYTE PTR -28[rbp+rax]
	movzx	eax, al
	cvtsi2ss	xmm1, eax
	mov	eax, DWORD PTR -48[rbp]
	cdqe
	movzx	eax, BYTE PTR -28[rbp+rax]
	movzx	edx, al
	mov	eax, DWORD PTR -48[rbp]
	cdqe
	movzx	eax, BYTE PTR -38[rbp+rax]
	movzx	eax, al
	sub	edx, eax
	mov	eax, edx
	cvtsi2ss	xmm0, eax
	mulss	xmm0, DWORD PTR -44[rbp]
	addss	xmm0, xmm1
	cvttss2si	eax, xmm0
	mov	edx, eax
	mov	eax, DWORD PTR -48[rbp]
	cdqe
	mov	BYTE PTR -18[rbp+rax], dl
	add	DWORD PTR -48[rbp], 1
.L2:
	cmp	DWORD PTR -48[rbp], 9
	jle	.L3
	mov	eax, 0
	mov	rcx, QWORD PTR -8[rbp]
	xor	rcx, QWORD PTR fs:40
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC0:
	.long	1071644672
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
