section .text
    global testShufps

testShufps:
    movaps xmm1, [rdi]   ; u
    movaps xmm2, [rsi]   ; v

    ;shufps xmm1, xmm1, 0h
    
    shufps xmm1, xmm2, 01111001b

    ;shufps xmm2, xmm1, 01111001b

    ;shufps xmm1, xmm1, 10001100b

    movaps [rdi], xmm1

exit:
    mov rax, 0
    ret