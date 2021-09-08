    section .data
cinco dd 5
    global por5dir
    section .text
por5dir:
    enter 0,0
    push ebx
    mov eax, [rel cinco]
    mov ebx, [ebp + 8]
    imul ebx
    pop ebx
    leave 
    ret
