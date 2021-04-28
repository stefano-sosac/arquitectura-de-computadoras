global effectASM
  section .text
effectASM:
  xor  r8, r8
  xor  r9, r9
  xor   rax, rax
bucle:
  cmp  ecx, r8d
  jle  final
  mov  r9b, BYTE [rsi+r8]
  mov  al, BYTE [rdi+r8]
  mov  r10b, r9b
  cvtsi2ss  xmm2, r9
  sub  r10b, al
  cvtsi2ss  xmm1, r10
  mulss  xmm1, xmm0
  addss  xmm1, xmm2
  cvttss2si  eax, xmm1
  mov     [rdx+r8], al
  inc  r8
  jmp  bucle
final:
  ret