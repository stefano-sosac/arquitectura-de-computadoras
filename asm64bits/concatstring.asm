;nasm -f elf64 -g concatstring.asm -o concatstring.o
;gcc -m64 concatstring.o -o concatstring
;./concatstring

    extern printf       ; scanf, malloc, calloc

section .datad
cadena1 db "hola",0     ; dw: 16 bits, dd: 32 bits, dq: 64 bits
cadena2 db " mundo",0

section .bss
cadena3 resb 30         ; resw, resd, resq
;cadena4 resw 30        ; uint_16 

section .text
    global main ; _start

main: ; _start

cpystr1:
    mov rax, cadena1
    mov rbx, 0

bucle1:
    mov r8, cadena3
    add r8, rbx

    mov r9b, [rax]
    mov [r8], r9b

    inc rax 
    inc rbx

    cmp r9b, 0
    jne bucle1

cpystr2:
    mov rax, cadena2
    mov rbx, 0

bucle2:
    mov r10, r8 
    add r10, rbx

    mov r9b, [rax]
    mov [r10], r9b

    inc rax
    inc rbx
    cmp r9b, 0
    jne bucle2

colocar_salto_linea:
    mov al, 10
    mov [r10], al

imprimir:
    mov rdi, cadena3
    mov rax, 0
    call printf wrt ..plt

final:
    mov rax, 0
    ret


