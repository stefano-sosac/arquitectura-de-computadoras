    section .data
cinco dd 5
    global globalvar
    section .text
globalvar:
    enter 0,0
    mov eax, [rel cinco]
    leave
    ret
