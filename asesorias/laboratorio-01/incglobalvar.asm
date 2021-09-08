    section .data
cinco dd 5
    global incglobalvar
    section .text
incglobalvar:
    enter 0,0
    mov eax, [rel cinco]
    inc eax
    leave
    ret
