    global entre2
    section .text
entre2:
    enter 0,0
    mov eax, dword [ebp + 8]
    shr eax, 1
    leave 
    ret
