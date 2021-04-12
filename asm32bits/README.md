# IEE240 - Organización y Arquitectura de Computadoras

## Problema 1:
- Completar la función `asmMedia32.asm` en la sección entre comentarios. El código debe hallar la media aritmética de los números almacenados en un arreglo de **N** elementos que se encuentran en memoria. Revisar los comentarios en el archivo a modificar. 

- Para clonar el repositorio y trabajar de forma local, realizar lo siguiente en un Terminal de Linux. Dentro de `<carpeta-del-repositorio>` encontrará todos los archivos necesarios para el desarrollo del laboratorio.
```
$ git clone <link-repositorio-alumno>
$ cd <carpeta-del-repositorio>
```
- Para verificar el funcionamiento de su código, ejecute lo siguiente lo siguiente en un Terminal de Linux.
```
$ bash test1.sh
```
- Si todo esta correcto debería observar un mensage como el siguiente en la línea de comandos (Terminal).
```
9       10      15      2
La media del arreglo es: 9 
```
- Si desea cambiar los valores del arreglo, luego de ejecutado el comando `$ bash test1.sh`, ejecute lo siguiente en la línea de comandos (Terminal). Reemplazar `numX` por números enteros aleatorios. Puede ingresar un número variable de números.
```
$ ./labp1 num1 num2 num3 num4 num5 ... 
```
- Por ejemplo:
```
$ ./labp1 1 2 3 4 5 6 10  
```

## Problema 2:
- Completar el archivo `asmMedia32womin.asm` en la sección delimitada por los comentarios. El código debe encontrar el mínimo valor de un arreglo de enteros y hallar la media aritmética de los números restantes (i.e. sin considerar el mínimo valor). Puede utilizar y extender el código del problema anterior. 

- Para verificar el funcionamiento de su código, ejecute lo siguiente lo siguiente en un Terminal de Linux.
```
$ bash test2.sh
```
- Si todo esta correcto debería observar un mensage como el siguiente en la línea de comandos (Terminal).
```
9       10      15      2
La media del arreglo es: 9 

La media del arreglo sin el minimo es: 11 
```
- Si desea cambiar los valores del arreglo, luego de ejecutado el comando `$ bash test2.sh`, ejecute lo siguiente en la línea de comandos (Terminal). Reemplazar `numX` por números enteros aleatorios. Puede ingresar un número variable de números.
```
$ ./labp2 num1 num2 num3 num4 num5 ... 
```
- Por ejemplo:
```
$ ./labp1 1 2 3 4 5 6 10  
```

## Subir solución a GitHub Classroom para auto revisión.
Al terminar el laboratorio y luego de validar localmente la correcta ejecución de su programa, realizar un `push` de su solución a su repositorio para su corrección. Para ello ejecute los siguientes comandos en un Terminal de Linux. **NOTA:** Los comandos a continuación debe ejecutarlos dentro de la carpeta `<carpeta-del-repositorio>`.

- Verificar con el siguiente comando que se han modificado los archivos correctos. Debería aparecer en rojo los archivos `asmMedia32.asm` y `asmMedia32womin.asm`.
```
$ git status
```
- Para añadir los archivos a git:
```
$ git add asm32bits/asmMedia32.asm asm32bits/asmMedia32womin.asm
```
- Para subir sus códigos al repositorio remoto (GitHub):
```
$ git commit -m "<ponga-aqui-un-comentario-util>"
$ git push
```
- Finalmente revisar su nota en la página web del repositorio. Cualquier consulta comuníquese con su JP.
