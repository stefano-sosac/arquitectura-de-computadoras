# IEE240 GCC calling conventions 64 bits:
- Los archivos para el desarrollo del problema se encuentran dentro de la carpeta `codes`. Debe codificar la función en ensamblador (para Intel de 64 bits) en el archivo `effectASM.asm`. Además, completar el archivo `preg.c` con las indicaciones del enunciado del problema.

- El programa bash `test.sh` es referencial y puede modificarlo para su correcto funcionamiento. Validar la ejecución de sus programas en su ambiente de trabajo.

- **Las funciones a implementar en lenguaje ensamblador deben seguir las reglas definidas por "GCC Calling Conventions".**

# Ejercicio
La ecuación a continuación permite procesar dos imágenes (`A` y `B`) y obtener el efecto mostrado en la Figura 1 (imagen `C`). 
```
C = B + alpha * (B - A)
```
<img src="./imagesRepo/resultados.png" alt="drawing" width="900"/>

**Figura 1:** Imágenes `A` y `B` para el desarrollo del ejercicio y resultado esperado (`C`).

- Implementar una función en lenguaje C que permita obtener la imagen `C` según la ecuación definida al incio del enunciado. Codificar su función dentro del programa `preg.c`.
- Codificar una función en ASM (archivo `effectASM.asm`) que permita obtener la imagen `C` según la ecuación definida al inicio del enunciado. El prototipo de esta función debe ser igual al prototipo de la función implementada en lenguaje C.

- Consideraciones:
    - La imagen es una arreglo de enteros de 1 byte en memoria RAM. Sus valores estan en el rango `[0 - 255]`.
    - El parámetro `alpha` debe ser ingresado por línea de comandos. 
    - La imagen resultante de cada una de las funciones a codificar debe guardarse en un archivo diferente. Modificar el código en `preg.c` para cumplir esta condición.
    - Para la verificación de sus implementaciones, utilizar un valor de `alpha = 1.75`.
    - Modificar el archivo `test.sh` para poder verificar el funcionamiento de sus códigos ejecutando la siguiente línea:
```
$ bash ./codes/test.sh
```
- Considerando que su función en lenguaje C es su referencia, calcule el speed-up relativo de su implementación en ASM. Utilizar la función `clock_gettime()` para la medición de tiempos.
- Considerando que su función en lenguaje C es su referencia, calcule el speed-up relativo de su implementación en ASM. Utilizar la función `clock_gettime()` para la medición de tiempos.
- Utilizando la ley de Amdahl, ¿cuál de las dos mejoraras tiene un mejor overall speed-up? Justificar.

**NOTA: las métricas de speed-up y tiempos deben imprimirse y las respuestas adicionales colocarse dentro del archivo `preg.c` como comentarios. Para el calculo de la fracción de mejora, puede reportar las mediciones como comentarios.**