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
