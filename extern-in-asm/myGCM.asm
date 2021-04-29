segment .data
    SYS_EXIT equ 1
    SYS_READ equ 3
    SYS_WRITE equ 4
    STDIN equ 0
    STDOUT equ 1
    
    ; a dd 5 
    ; b dd 10
    msg db "Ingrese los valores a b", 10, 0
    message db "El GCM de %d y %d es: %d", 10
    ingresea db "%d %d", 0
    ingreseb db "%d", 0

segment .bss
    ; variables estaticas sin inicializacion
    a resb 4
    b resb 4
    result resb 4 

segment .text
    global main
    extern printf
    extern scanf
 
main: 
    push ebp
    mov ebp,esp

    xor eax,eax ; mov eax, 0
    xor ebx,ebx
    xor ecx,ecx
    xor edx,edx

    push msg
    call printf

break1:
    add esp,4
    push b
    push a
    push ingresea
    ;push ingresea
    call scanf

    ; add esp,8
    ; push msg
    ; call printf

    ; add esp,4
    ; push b
    ; push ingreseb
    ; call scanf

    mov eax,DWORD[a] ; r0 <- a
    mov ebx,DWORD[b] ; r1 <- b
    xor edx,edx

mygcm:
    div ebx     ; edx (r2) <- r0 mod r1
    mov eax,ebx ; r0 <- r1
    mov ebx,edx ; r1 <- r2
    xor edx,edx
    cmp ebx,0
    jnz mygcm     ; while some number (in ecx) != 0

    mov [result],eax

    push DWORD[result]
    push DWORD[b]
    push DWORD[a]
    push message
    call printf

exit:
    mov esp,ebp
    pop ebp
    mov eax,SYS_EXIT
    int 0x80

