; para ensamblar:
; nasm -f elf64 -g ejemplo_gdb.asm -o ejemplo_gdb.o
; para enlazar:
; ld ejemplo_gdb.o -o ejemplo_gdb
        segment .data
a       dd      4   
b       dd      4.4 
c       dw      1,2 
e       db      "hola mundo",10,0
f       equ     $-e 

        segment .bss
g       resb    1   
h       resw    10  
i       resq    100 

        segment .text
        global _start

_start:
    
        mov     rax, 1
        mov     rdi, 1
        mov     rsi, e
        mov     rdx, f
        syscall
    
        mov     rax, 60
        mov     rdi, 0
        syscall
