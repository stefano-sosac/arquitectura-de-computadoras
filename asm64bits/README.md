# IEE240 - Organización y Arquitectura de Computadoras
# Lenguaje ensamblador x86-64

## Problema 1:
Codificar un programa en lenguaje ensamblador de 64 bits que realice lo siguiente:

- En la sección de datos debe declarar una cadena de 8 caracteres que corresponda
a su código de alumno.
- La función `bswap` tiene como funcionalidad invertir el orden de los bytes de un
registro (ver [link](https://www.felixcloutier.com/x86/bswap) . Se le pide utilizar dicha instrucción para invertir la cadena que se ha generado en memoria e imprimirla en pantalla.
- Extender su código de tal forma que determine si el número ingresado en memoria es capicúa o no. Realizar este procedimiento utilizando operaciones lógicas entre la cadena invertida con bswap y la cadena original en memoria.
- Finalmente, su programa debe imprimir el número original e invertido, ası́ como los mensajes según sea el caso.
```
$ El numero en memoria es capicua
```
```
$ El numero en memoria no es capicua
```
- Para verificar el funcionamiento de su código, ejecute lo siguiente lo siguiente en un Terminal de Linux.
```
$ bash sol1.sh
```
- Si todo esta correcto debería observar un mensage como el siguiente en la línea de comandos (Terminal).
```
El numero no es capicua
```

## Problema 2:
Para estar experiencia usted deberá presentar cuatro archivos, cada uno con unpro-
grama en lenguaje ensamblador de 64 bits.
- Un programa que imprima un caracter de una cadena.
    - El archivo se deberá llamar `getchar.asm`
    - La cadena se deberá encontrar en el segmento de datos.
    - La posición del caracter que debe imprimir se deberá encontrar en el  segmento `.data`
    - El caracter a imprimir deberá ser guardado en el segmento `.bss`

- Un programa que copia una cadena de caracteres.
    - El archivo se deberá llamar `copystring.asm`
    - La cadena se deberá encontrar en el segmento de datos.
    - La copia de la cadena deberá ser guardada en el segmento .bss
    - Asuma que las cadenas tendrán un máximo de 30 caracteres.

- Un programa que concatena dos cadenas de caracteres.
    - El archivo se deberá llamar `concatstring.asm`
    - Las cadenas se deberán encontrar en el segmento de datos.
    - La concatenación de la cadena deberá ser guardada en el segmento .bss
    - Asuma que las cadenas tendrán un máximo de 30 caracteres.

- Un programa que separa las palabras de un texto almacenado en memoria.
    - El archivo se deberá llamar `splitstring.asm`
    - La cadena se deberá encontrar en el segmento de datos.
    - Cada palabra separada se debe guardar en el segmento .bss
    - Asuma que las palabras tendrán un máximo de 10 caracteres y el texto tendrá como máximo 4 palabras.
    - Imprimir cada una de las palabras separadas.

- Para verificar el funcionamiento de su código, ejecute lo siguiente lo siguiente en un Terminal de Linux.
```
$ bash sol2.sh
```

## Subir solución a GitHub Classroom para auto revisión.
Al terminar el laboratorio y luego de validar localmente la correcta ejecución de su programa, realizar un `push` de su solución a su repositorio para su corrección. Para ello ejecute los siguientes comandos en un Terminal de Linux. **NOTA:** Los comandos a continuación debe ejecutarlos dentro de la carpeta `<carpeta-del-repositorio>`.

- Verificar con el siguiente comando que se han modificado los archivos correctos. Debería aparecer en rojo el archivo `solucion1.asm`
```
$ git status
```
- Para añadir los archivos a git:
```
$ git add asm64bits/solucion1.asm
```
- Para subir sus códigos al repositorio remoto (GitHub):
```
$ git commit -m "<ponga-aqui-un-comentario-util>"
$ git push
```
- Finalmente revisar su nota en la página web del repositorio. Cualquier consulta comuníquese con su JP.
