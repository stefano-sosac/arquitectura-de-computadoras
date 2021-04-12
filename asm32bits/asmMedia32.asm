global asmMedia32

section	.text

asmMedia32:
    ; Prólogo para calling conventions en 32 bits
    push ebp
    mov ebp, esp
    push esi
    push edi
    push ebx

    ; Limpiar los registros a utilizar
    xor eax,eax
    xor ebx,ebx
    xor ecx,ecx
    xor edx,edx

    ; Punteros iniciales (esto se inicializa en el archivo laboratorio0.c)
	mov edi,[ebp + 8]   ; edi <- *arr
    mov ecx,[ebp + 12]  ; ecx <- N

; -------------------------------------------- ;
; -------------------------------------------- ;
; ---------- Escriba aqui su código ---------- ;
; -------------------------------------------- ;
; -------------------------------------------- ;

    mov eax,[edi]   ; eax <- arr[0] cargamos en eax la primera posición del arreglo
    mov ebx,ecx
    dec ecx         ; ecx tiene el valor del tamaño del arreglo por lo que lo usamos de contador decreciente 
    jz exit         ; saltamos hacia exit en caso el tamaño del arreglo de datos sera cero

suma:
    add edi,4       ; incrementamos la posición del puntero. Recordar que un entero tiene 4 bytes
    add eax,[edi]   ; leemos el siguiente valor y almacenamos la suma acumulada en eax
    loop suma       ; loop para leer todos los valores del arreglo. La instrucción loop trabaja con el registro ecx para saber cuando saltar. Revisar ISA

exit:
    cdq              ; extender el signo de eax hacia edx 
    idiv ebx         ; cociente: eax <- (edx:eax)/ebx ---- residuo: edx

; -------------------------------------------- ;
; -------------------------------------------- ;
; ------------- Fin de su código ------------- ;
; -------------------------------------------- ;
; -------------------------------------------- ;
    
    ; Epílogo de calling conventions de 32 bits
    pop ebx
    pop edi
    pop esi 
    mov esp,ebp
    pop ebp
    ret
