# Valgrind y mayoría de edad

En este ejercicio se trabajará con el archivo de C [mayores.c](mayores.c). Este archivo contiene la implementación de lo que podría ser un TP1 de la materia (o más bien una parte de dicho TP).

Este programa lee una lista de personas en formato CSV y, a partir de sus fechas de nacimiento, imprime por pantalla aquellas que son mayores de edad. Se incluye, al final de este documento, la consigna completa por si fuera necesaria; pero el programa ya está implementado.

La implementación que se proporciona es correcta en cuanto a comportamiento (esto es, hace lo que pide la consigna), pero tiene defectos importantes en el manejo de memoria dinámica. En particular, al ejecutar el programa con cierta entrada bajo Valgrind, se reportan un número de errores del tipo:

```
Conditional jump or move depends on uninitialised value(s)
  ...
Invalid free() / delete / delete[] / realloc()
  ...
Invalid read of size 1
  ...
6 bytes in 1 blocks are definitely lost
  ...

ERROR SUMMARY: 7 errors from 6 contexts (suppressed: 0 from 0)
```

La salida completa de Valgrind se encuentra en el archivo [`valgrind_01.txt`](valgrind_01.txt). Como referencia, con el archivo CSV apropiado se puede regenerar la salida con el comando:

```sh
$ valgrind --leak-check=full --track-origins=yes --show-reachable=yes \
            ./mayores personas_01.csv 2>valgrind_01.txt
```

### Lo que se pide

En este ejercicio, se pide:

1.  Un documento de texto (en formato Markdown, texto plano o PDF) en el
    que se explique la génesis  de cada error de Valgrind, esto es: la
    cadena causal completa que conlleva a él o, dicho de otro modo, el
    flujo de ejecución responsable.

    Esta explicación debe ser completa. Por ejemplo, para un error del
    tipo _Invalid read of size 1 in line 17_, no es suficiente decir “se
    leyó en la línea 17 un byte sin inicializar”. Se debe incluir dónde
    se creó ese byte, qué función lo lee y, sobre todo, **qué
    condiciones se tuvieron que cumplir para que ese byte llegara sin
    inicializar a la línea 17**. (La excepción es si _siempre_ llega sin
    inicializar, en cuyo caso basta con remarcar ese hecho.)

2.  Junto con las descripciones de los errores, se pide un archivo en
    formato CSV que permita reproducir, con la versión de _mayores.c_
    proporcionada, la misma secuenca de errores que se encuentra en
    `valgrind_01.txt`. Dicho de otra manera, tras entender los flujos de
    ejecución que condujeron a cada error, componer una entrada que fuerce
    todos esos flujos en secuencia.

### Importante: Lo que _no_ se pide

El objetivo del ejercicio es poder utilizar la información de Valgrind para _encontrar_ errores y entender sus causas. _No se pide en este ejercicio modificar el programa ni corregir los errores encontrados_.

La implementación que aquí se proporciona tiene ciertos aspectos bien diseñados, pero es importante entender que **muchos de los errores de memoria corresponden a una mala organización del código, o secuencias de condiciones confusas y difíciles de seguir**. El programa partió de una estructura inicial sólida, pero en su versión actual se empieza a adentrar en territorio [spaghetti code](https://es.wikipedia.org/wiki/C%C3%B3digo_espagueti).

Lo que siempre se debe intentar es **no corregir código espagueti con más código espagueti** (lo cual es muchas veces imposible, sobre todo si se trabaja con prisas). Es esta la razón por la que no se pide modificar el código. Una vez entregado el ejercicio, sí se realizará un taller donde, en común, se solucionarán los problemas que exhibe el programa de la manera más limpia posible: subsanando errores a la par que simplificando la lógica de validación del programa.

## Consigna original mayores.c

`TODO`
