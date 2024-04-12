# Push_swap

<div>

  ![Proyecto](https://img.shields.io/badge/Proyecto-Push_swap-blue)
  ![Licencia](https://img.shields.io/badge/Licencia-MIT-orange)
  ![Versión](https://img.shields.io/badge/Versión-1.0-green)
  <a href="https://github.com/MiMendiola/Push_swap/tree/main/README.md" >
    <img src="https://img.shields.io/badge/Change_Language-English-purple" align="right">
  </a>

</div>

El proyecto `Push_swap` se basa en ordenar una `pila de numeros` con una pila A y otra pila B, con un conjunto de `instrucciones limitadas`, utilizandolas de la forma mas eficiente posible para conseguir el `menor numero de movimientos`. Esto nos enseñara algunos de los `algoritmos de ordenacion` mas comunes y ademas a utilizar `estructuras` de manera efectiva y fluida que nos ayudara para afrontar los siguientes retos que nos encontremos.

El proceso comienza verificando la validez de la secuencia numérica, que se almacena en la pila A. Para secuencias desordenadas de `dos elementos`, se emplea un simple intercambio con `SA` para ordenarlos. Con `tres elementos`, se utiliza una función específica de ordenación. Para secuencias mayores, se adopta un algoritmo más complejo adecuado para volúmenes más grandes de datos.

El **`Algoritmo Turco`** consiste en ir organizando los numeros mediante un `análisis del rendimiento` asociado a cada movimiento al mismo tiempo.  Inicialmente, moveremos los dos primeros números a la pila B, sin distinción de su valor. Posteriormente, se iran moviendo elementos selectivamente, manteniendo solamente `tres números en la pila A`. Iremos asignando un índice a cada nodo, para determinar la operación más eficiente que debamos emplear.

Dicha selección de elementos para mover a la pila B se basa en los que resulten con `menor coste de movimientos`, dando prioridad al `número más grande` que se encuentre `más próximo` en la pila A. Se realizarán las rotaciones necesarias para `colocar estos elementos en la parte superior de la pila`, para luego trasladarlos a la pila B.

Proseguiremos ejecutando la ordenacion de los tres numeros en la pila A. Al finalizar esto lo que haremos sera plantear `un objetivo del nodo de la pila B` que sera el `numero menor mas cercano en la pila A`, donde iremos ajustando las posiciones para tener estos numeros en la cima, para luego moverlos a la pila A. Repetiremos este proceso hasta `vaciar` completamente la `pila B`.

Finalmente, identificaremos el elemento de menor valor en la pila, y en función de si su posición se encuentra en la mitad superior o inferior de la misma, ejecutaremos la rotación apropiada para posicionarlo al principio de la pila.

La parte `bonus` de este proyecto sera la creacion de un `checker`, el cual validara si las instrucciones dadas determina si nuestra pila de numeros se logra ordenar correctamente.

Para una `explicación detallada` de cada parte del proyecto, incluyendo cómo funcionan los algoritmos de ordenamiento y cómo se implementan las operaciones de pila, consulta la sección `Tabla de Contenidos` a continuación.

---

## **Tabla de Contenidos**
[MOVEMENTS](https://github.com/MiMendiola/Push_Swap/tree/main/Documentation/es/MOVEMENTS.es.md)

[STACK](https://github.com/MiMendiola/Push_Swap/tree/main/Documentation/es/STACK.es.md)

[CHECKER](https://github.com/MiMendiola/Push_Swap/tree/main/Documentation/es/CHECKER.es.md)

---

## **Recomendaciones**

Consultar algoritmos para tener claro cual deseas realizar, y busca la eficiencia de cada uno.

Tener claro hasta que punto quieres llegar en el proyecto, si quieres conseguir la maxima nota te recomiendo que leas Algoritmo Turko.

La validación de los argumentos es una prioridad para el éxito del proyecto.

El manejo eficiente de estructuras de datos es crucial, ya que trabajaremos con listas doblemente enlazadas.

El uso de herramientas de depuración facilitara la resolucion de problemas en las instrucciones y estructuras.

---

## **Contacto**

Si tienes alguna pregunta, sugerencia o comentario sobre `Push_swap`, no dudes en ponerte en contacto conmigo:

- **Correo Electrónico:** [mglmendiol@gmail.com](mailto:mglmendiol@gmail.com)
- **LinkedIn:** [https://www.linkedin.com/in/mimendiola/](https://www.linkedin.com/in/mimendiola/)
