    global suma2args
    section .text
suma2args:
    enter 0,0
    mov eax, [ebp + 8]
    add eax, [ebp + 12]
    leave 
    ret
