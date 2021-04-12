section .data
	mensaje1 db "El numero es capicua",10
	len1 equ $-mensaje1     ; calculamos la longitud del mensaje anterior

	mensaje2 db "El numero no es capicua",10
	len2 equ $-mensaje2     ; calculamos la longitud del mensaje anterior
    
    datos db "20084503"	; guardamos en memoria nuestro código

section .bss
	datos2 resb 8	; reservamos 8 bytes para guardar la cadena invertida
					; este espacio de memoria NO esta inicializado

section .text
	global _start

_start:

	mov rbx, QWORD[datos]	    ; cargar toda la frase de 8 caracteres
	bswap rbx			        ; invertimos la cadena entera en el registro de 64 bits (8 numeros cada uno de 1 byte)
	mov QWORD[datos2], rbx		; guardamos la nueva cadena en el espacio de memoria reservado
    mov r13, QWORD[datos]       ; cargo en r13 la cadena original
    xor r13, rbx                ; si ambas cadenas son iguales (es decir capicua), el xor debe ser igual a cero
    jz capicua

nocapicua:
	; ----- Codigo para impresión en pantalla ----- ;
	mov rax, 1		    ; función a utilizar (printf)
	mov rdi, 1		    ; imprimir en pantalla: 1
	mov rsi, mensaje2	; rsi debe contener el puntero hacia el arreglo a imprimir
	mov rdx, len2		; numero de elementos a imprimir
	syscall			    ; system call --> llamadas a funciones del sistema (SO)
	; --------------------------------------------- ;
    jmp exit            ; si no es capicua debemos terminar el programa

capicua:
	; ----- Codigo para impresión en pantalla ----- ;
	mov rax, 1		    ; función a utilizar (printf)
	mov rdi, 1		    ; imprimir en pantalla: 1
	mov rsi, mensaje1	; rsi debe contener el puntero hacia el arreglo a imprimir
	mov rdx, len1	    ; numero de elementos a imprimir
	syscall			    ; system call --> llamadas a funciones del sistema (SO)
	; --------------------------------------------- ;
	
exit:
    ; ---- return 0 ---- ;
	mov rax, 60		; función para terminar la ejecución del programa. Similar a int 21h
	mov rdi, 0
	syscall
    ; ------------------ ;