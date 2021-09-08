    global ecoarg
    section .text
ecoarg:
    enter 0,0
    mov eax, [ebp + 8]
    leave 
    ret
