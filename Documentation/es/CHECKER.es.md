# Checker

La parte `bonus` de nuestro proyecto `Push_Swap`, denominado `checker`, funciona como un validador de las operaciones suministradas a través de la terminal, con el `objetivo` de verificar si estas operaciones resultan en una secuencia ordenada. Para implementar esta funcionalidad, se integra el uso de nuestra función **`get_next_line`** configurada con el `descriptor de archivo 0`, lo que permite la lectura de operaciones desde la `entrada estándar` hasta que se señale el fin de la entrada con `Ctrl + D`. Además, el programa termina automáticamente en situaciones donde la secuencia de argumentos suministrada esté vacía o contenga un único número, en cuyo caso se emitirá la confirmación `OK`.

**[CHECKER.C](https://github.com/MiMendiola/Push_swap/blob/main/src/bonus/checker.c)**: La lógica del **`checker`** se estructura en torno a tres funciones clave:

- **void	execute_rotates(t_stack** ****stack_a, t_stack** ****stack_b, char** ***move)**: Esta función se encarga de ejecutar las operaciones de rotación en las pilas A y B, seleccionando la operación específica dependiendo del argumento `move` proporcionado.

- **void	execute_moves(t_stack** ****stack_a, t_stack** ****stack_b, char** ***move)**: Diseñada para implementar las operaciones indicadas por la función **`get_next_line`** sobre las pilas. Esta función se subdivide para tratar específicamente las rotaciones, tanto normales como inversas, facilitando la gestión de los movimientos a las pilas.

- **int	main(int ac, char *av[])**: La función principal del `checker` inicia reservando el espacio necesario para las pilas. En caso de recibir múltiples argumentos, procede con la creación de la estructura de pila empleada en el `Push_Swap`. A continuación, lee secuencialmente las operaciones desde la terminal hasta que se indica el fin de la entrada con `Ctrl + D`, aplicando cada operación leída a las pilas mediante **`execute_moves`**. Finalmente, comprobamos si la secuencia resultante en la pila está ordenada o si se presenta algun error en la secuencia.
