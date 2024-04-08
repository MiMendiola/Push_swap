# Movements

Las `operaciones` permitidas que tendremos seran:

- **PA**: Mover el elemento superior de la pila B a la cima de la pila A.
- **PB**: Mover el elemento superior de la pila A a la cima de la pila B.
- **SA**: Intercambia los dos primeros elementos en la cima de la pila A.
- **SB**: Intercambia los dos primeros elementos en la cima de la pila B.
- **SS**: Realiza SA y SB a la vez.
- **RA**: Mueve hacia arriba todos los elementos de la pila A , haciendo que el primer nodo sea el ultimo.
- **RB**: Mueve hacia arriba todos los elementos de la pila B , haciendo que el primer nodo sea el ultimo.
- **RR**: Realiza RA y RB a la vez.
- **RRA**: Mueve hacia abajo todos los elementos de la pila A , haciendo que el último nodo sea el primero.
- **RRB**: Mueve hacia abajo todos los elementos de la pila B , haciendo que el último nodo sea el primero.
- **RRR**: Realiza RRA y RRB a la vez.

Estos son los movimientos con los que ordenaremos nuestras pilas. Tengo dividido cada `movimiento por archivo`, promoviendo un codigo mas limpio y organizado para mejorar la comprension y mantenimiento del programa.

**[PUSH.C](https://github.com/MiMendiola/Push_swap/blob/main/src/movements/push.c)**: Contiene los movimientos de `transladar nodos` entre pilas.

- **void push_node(t_stack** ****stack, t_stack** ****node):** Esta función se encarga de `trasladar un nodo` de una pila a otra. Utilizaremos una variable temporal para guardar el `nodo a mover`. Si la pila de destino está vacía, el nodo a mover será el primer y único elemento, marcando su nodo siguiente como NULL para indicar el final de la lista. Si la pila de destino contiene nodos, el nodo a mover se añadirá al principio, ajustando las direcciones de los punteros para mantener la integridad de la información. Al final, `igualaremos la pila original al nodo a mover`, que será ahora el principio de nuestra pila, completando así el movimiento.
- **void	push(t_stack** ****stack_a, t_stack** ****stack_b, int move):** Esta función nos ayudará a determinar el movimiento a ejecutar. Dependiendo del movimiento (PA o PB), llamaremos a la función **`push_node`** con los parámetros correspondientes, ya sea para trasladar un nodo de B a A o viceversa. Tras realizar el movimiento, mostraremos por pantalla el movimiento realizado.

**[SWAP.C](https://github.com/MiMendiola/Push_swap/blob/main/src/movements/swap.c)**: Incluye las operaciones de `intercambiar` los `dos primeros elementos` de cualquier pila.

- **void	swap_node(t_stack** ****stack):** Encargada para `intercambiar` los `dos primeros elementos` de la pila especificada. Para optimizar el proceso optaremos por intercambiar únicamente sus valores. Esto se logra mediante `dos variable temporales`: una para almacenar el `primer elemento` y otra para el `segundo elemento` de la pila, ajustando asi los valores para poder hacer el intercambio y finalizar el movimiento sin alterar la estructura.
- **void	swap(t_stack** ****stack_a, t_stack** ****stack_b, int move):** Esta función nos ayudará a determinar el movimiento a ejecutar. Dependiendo del movimiento (SA, SB o SS), llamaremos a la función **`swap_node`**. En el caso de `SS`, ejecutaremos esta función `tanto a la pila A como a la B`. Una vez ejecutado el movimiento,  lo mostraremos por pantalla.

**[ROTATE.C](https://github.com/MiMendiola/Push_swap/blob/main/src/movements/rotate.c)**: Incluye los movimientos de `rotar` la pila, situando el `primer elemento como el último`.

- **void	rotate_node(t_stack** ****stack):** Designada para realizar la `rotación` de la pila especificada. Emplearemos `dos variables auxiliares`: una para almacenar el `segundo nodo` y otra para el `último nodo` de la pila. Si la pila contiene nodos, ajustaremos las direcciones de los punteros para preservar la integridad de la estructura. Finalmente, `reasignaremos` la pila al `segundo elemento`, completando así la rotación.
- **void	rotate(t_stack** ****stack_a, t_stack** ****stack_b, int move):** Esta función nos ayudará a determinar el movimiento a ejecutar. Dependiendo del movimiento (RA, RB o RR), llamaremos a la función **`rotate_node`**. En el caso de `RR`, ejecutaremos esta función `tanto a la pila A como a la B`. Una vez ejecutado el movimiento,  lo mostraremos por pantalla.

**[REVERSE_ROTATE.C](https://github.com/MiMendiola/Push_swap/blob/main/src/movements/reverse_rotate.c)**: Contiene las operaciones de `rotar` la pila, situando el `último elemento como el primero`.

- **void	reverse_rotate_node(t_stack** ****stack):** Designada para realizar la `rotación inversa` de la pila especificada. Emplearemos `dos variables auxiliares`: una para almacenar el `último nodo` y otra para el `penúltimo nodo` de la pila. Si la pila contiene nodos, ajustaremos las direcciones de los punteros para preservar la integridad de la estructura. Finalmente, `reasignaremos` la pila al `último elemento`, completando así la rotación inversa.
- **void	reverse_rotate(t_stack** ****stack_a, t_stack** ****stack_b, int move):** Esta función nos ayudará a determinar el movimiento a ejecutar. Dependiendo del movimiento (RRA, RRB o RRR), llamaremos a la función **`reverse_rotate_node`**. En el caso de `RRR`, ejecutaremos esta función `tanto a la pila A como a la B`. Una vez ejecutado el movimiento,  lo mostraremos por pantalla.