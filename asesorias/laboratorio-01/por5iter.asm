    section .data
cinco dd 5
    global por5iter
    section .text
por5iter:
    enter 4,0
    push ebx
    mov eax, [rel cinco]
    mov ebx, [ebp + 8]
    mov dword [ebp - 4], 0
bucle:
    add [ebp - 4],ebx
    dec eax
    jnz bucle
    mov eax, [ebp - 4]
    pop ebx
    leave 
    ret
