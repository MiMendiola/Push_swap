# Stack

Estos archivos están dedicados para facilitar la gestión de las pilas, organizando las funcionalidades según las operaciones que desees implementar.

**[STACK_CREATOR.C](https://github.com/MiMendiola/Push_swap/blob/main/src/stack/stack_creator.c)**: Este archivo contiene `funciones esenciales` para la inicialización y configuración de la pila de números.

- **void	stack_duplicate_arg(t_stack *stack)**: Esta función se encarga `comprobar` que `no` existan numeros `duplicados` en la pila.

- **void	stack_add_node(t_stack** ****stack, char** ****nums, int** ***index):** Dependiendo de la presencia de `múltiples números` en un único argumento, esta función añade nodos a la pila de manera distinta. Para la conversión de cadenas de texto a valores numéricos, se emplea la función **`ft_atol`**, la cual permite trabajar con el tipo de dato `long` para abarcar un rango mayor de números y gestionar adecuadamente los casos que excedan los límites definidos.

- **void	stack_creator(char** ***av[], t_stack** ****stack_a):** Esta función realiza la `creación de la pila de números`, verificando que reciba al menos un número como argumento. Posteriormente, iremos añadiendo números a la pila, comprobando que no haya elementos duplicados. Terminaremos liberando la memoria asignada a la estructura temporal que alacema los números, la cual se obtiene mediante la función **`ft_split`.**

**[STACK_PROPERTIES.C](https://github.com/MiMendiola/Push_swap/blob/main/src/stack/stack_properties.c)**: Este archivo contiene `funciones` diseñadas `para obtener o definir propiedades` específicas `de las pilas`, facilitando la gestión de sus características.

- **t_stack	*stack_max(t_stack *stack)**: Función dedicada a identificar y `retornar el nodo` contiene el `valor máximo` dentro de la pila.

- **t_stack	*stack_min(t_stack *stack)**: Función dedicada a identificar y `retornar el nodo` contiene el `valor mínimo` dentro de la pila.

- **int	stack_len(t_stack *stack)**: Proporciona la `longitud total de la pila`, ofreciendo una medida rápida de su tamaño.

- **int	stack_sorted(t_stack *stack)**: Realiza una `verificación` para determinar si la `pila` está `ordenada` de menor a mayor.

- **void	stack_above_half(t_stack *stack)**: Esta función `asigna un índice` a cada nodo mientras `determina si su posición es superior o inferior a la mitad de la pila` mediante un valor booleano. Este análisis permite tomar decisiones más efectivas en cuanto a las operaciones a realizar para su ordenación, especialmente en pilas con un número impar de elementos.

**[STACK_SETTERS.C](https://github.com/MiMendiola/Push_swap/blob/main/src/stack/stack_setters.c)**: Este archivo se encarga de `definir y ajustar propiedades específicas para los nodos` dentro de las estructuras de la pila, facilitando la gestión y optimización del proceso de ordenación.

- **t_stack**	***stack_set_min_cost(t_stack** ****stack_a, t_stack** ****stack_b):** Esta función se dedica a determinar el nodo con el menor coste de movimiento entre las dos pilas, empleando **`stack_set_push_cost`** para calcular dicho coste. El nodo seleccionado, que presenta el coste mínimo, se devuelve para su uso mas adelante.

- **void	stack_set_push_cost(t_stack *stack_a, t_stack *stack_b, t_stack *node_a, int *count)**: Esta función calcula el `coste de movimientos` necesarios para trasladar un nodo específico de la pila A a la pila B. Se identifica el `nodo objetivo en la pila B` y, en función de su posición relativa (por encima o por debajo de la mitad de la pila), se `emplea su identificador` para establecer el `conteo del coste` de movimientos.

- **void	stack_set_target_a(t_stack *main_stack, t_stack *stack_b)**: Establece el `nodo objetivo en la pila B` para un nodo dado de la pila A. El `criterio` de selección del objetivo se basa en encontrar el `número más grande en la pila B` que se encuentre `más cerca del valor del nodo en cuestión en la pila A`. Si el nodo representa el `valor mínimo` en la pila, el `objetivo` se convierte en el `número más grande de la pila B`, devolviendo el nodo objetivo correspondiente.

- **t_stack**	***stack_set_target_b(t_stack *node, t_stack *stack_a)**: Define el `nodo objetivo en la pila A` para un nodo específico de la pila B. El objetivo se selecciona como el `número más pequeño en la pila A` que `más se aproxime al valor del nodo en la pila B`. Si el `nodo` en cuestión es el `valor máximo`, el `objetivo` será el `número más pequeño de la pila A`, retornando el nodo objetivo.

- **void	stack_set_top_node(t_stack** ****stack_a, t_stack** ****stack_b, t_stack** ***min_cost)**: Con el conocimiento del `nodo` que posee el `coste mínimo` de traslado a la pila destino, y su `nodo objetivo`, se procede a realizar los `movimientos` necesarios `para posicionar estos nodos en la cima` de sus respectivas pilas. Este proceso `prioriza` las `rotaciones simultáneas` de ambas pilas para optimizar el número de movimientos requeridos.

**[STACK_SORT.C](https://github.com/MiMendiola/Push_swap/blob/main/src/stack/stack_sort.c)**: Este archivo contiene todas las funciones cruciales dedicadas a la ordenación de los nodos dentro de las pilas, asegurando un manejo eficiente y optimizado de los datos.

- **void	sort_stack_three(t_stack** ****stack):** Esta función se especializa en la `ordenación` de pilas que contienen `tres elementos`, ajustando su movimientos en función de su disposición actual dentro de la pila.

- **void	sort_push_b(t_stack** ****stack_a, t_stack** ****stack_b):** Su objetivo es `trasladar elementos de la pila A a la pila B`, siempre que la pila A contenga más de tres elementos y se encuentre desordenada. Durante este proceso, se evalúa la posición relativa de los elementos mediante **`stack_above_half`**, identificando aquellos cuyo reajuste resulte en el menor coste de movimiento con **`stack_set_min_cost`**. Posteriormente, se realizan las maniobras necesarias para posicionar adecuadamente los elementos seleccionados en la parte superior de las pilas, facilitando su transferencia de A a B.

- **void	sort_push_a(t_stack** ****stack_a, t_stack** ****stack_b):** Esta función se encarga de `mover los elementos de la pila B de vuelta a la pila A`. Inicia con la determinación de los objetivos en la pila B a través de **`stack_set_target_b`**, utilizando **`stack_above_half`** para evaluar su posición. Se procede con rotaciones en la pila A hasta alinear el elemento deseado en la parte superior, permitiendo su traslado desde la pila B.

- **void	sort_stack(t_stack** ****stack_a, t_stack** ****stack_b):** Actúa como la `función principal de ordenación`, implementando la estrategia global del algoritmo. Inicialmente, transfiere los `dos primeros elementos` a la pila B, seguido de un proceso iterativo con **`sort_push_b`** para reubicar los elementos en la pila B, dejando solamente tres en la pila A. Una vez alcanzado este estado, **`sort_push_a`** se encarga de reintegrar todos los elementos a la pila A. La fase final implica volver a establecer los indices y ajustar la posición del elemento más pequeño al principio de la pila A.

- **void	sort_end(t_stack** **stack_a, t_stack** ****stack_b):** Esta función `finaliza el proceso de ordenación` mediante rotaciones consecutivas en la pila A, asegurando que el elemento más pequeño quede posicionado en la parte superior de la pila, terminando así la secuencia de ordenación.

**[STACK_UTILS.C](https://github.com/MiMendiola/Push_swap/blob/main/src/stack/stack_utils.c)**: Este archivo es fundamental dentro del código, ya que contiene un conjunto de funciones esenciales para la manipulación y gestión de las estructuras de datos utilizadas.

- **void	free_list(t_stack** ****stack):** Esta función es crucial para la gestión de memoria, ya que se `encarga de liberar` todos los `datos` de una pila.

- **t_stack	*last_node(t_stack *lst)**: Proporciona un `acceso` directo al `último nodo de la lista`, optimizando operaciones que requieran referencia al final de la misma.

- **t_stack	*new_node(int id, long num)**: Es una función constructora que `genera` un nuevo `nodo con los parámetros especificados`. Este nodo recién creado está listo para ser integrado dentro de la estructura de datos según sea necesario.

- **void	add_node_back(t_stack** ****stack, t_stack** ***new):** Desempeña un papel fundamental, `permitiendo` la `adición` de un nuevo `nodo` al `final de la pila`. En casos donde la pila esté vacía, este nodo se establece como el elemento inicial, asegurando la flexibilidad en la gestión de la estructura de datos.

- **long	ft_atol_ps(char *str)**: Esta función nos ayuda `transformando` una `cadena de caracteres en un valor numérico largo`. Incorpora una verificación para asegurar que el número resultante se encuentre dentro de los límites permitidos, emitiendo un error en caso de un valor fuera del rango establecido, lo cual previene posibles comportamientos erróneos.
