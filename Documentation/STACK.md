# Stack

These files are dedicated to facilitating the management of stacks by organizing functionalities according to the operations you wish to implement.

**[STACK_CREATOR.C](https://github.com/MiMendiola/Push_swap/blob/main/src/stack/stack_creator.c)**: This file contains `essential functions` for initializing and setting up the number stack.

- **void	stack_duplicate_arg(t_stack *stack)**: This function is responsible for `checking` that there are `no duplicate numbers` in the stack.

- **void	stack_add_node(t_stack** ****stack, char** ****nums, int** ***index):** Depending on the presence of `multiple numbers` in a single argument, this function adds nodes to the stack differently. For converting strings to numeric values, the **`ft_atol`** function is used, which allows working with the `long` data type to cover a broader range of numbers and manage cases that exceed defined limits properly.

- **void	stack_creator(char** ***av[], t_stack** ****stack_a):** This function carries out the `creation of the number stack`, ensuring at least one number is received as an argument. Then, numbers will be added to the stack, checking for duplicate elements. Finally, the memory allocated to the temporary structure holding the numbers, obtained through the **`ft_split`** function, will be freed.

**[STACK_PROPERTIES.C](https://github.com/MiMendiola/Push_swap/blob/main/src/stack/stack_properties.c)**: This file contains `functions` designed `to obtain or define specific properties` of stacks, easing the management of their characteristics.

- **t_stack *stack_max(t_stack *stack)**: A function dedicated to identifying and `returning the node` that contains the `maximum value` within the stack.

- **t_stack *stack_min(t_stack *stack)**: A function dedicated to identifying and `returning the node` that contains the `minimum value` within the stack.

- **int stack_len(t_stack *stack)**: Provides the `total length of the stack`, offering a quick measure of its size.

- **int stack_sorted(t_stack *stack)**: Conducts a `check` to determine if the `stack` is `sorted` from smallest to largest.

- **void stack_above_half(t_stack *stack)**: This function `assigns an index` to each node while `determining if its position is above or below the midpoint of the stack` through a boolean value. This analysis enables more effective decision-making regarding the operations to perform for sorting, especially in stacks with an odd number of elements.

**[STACK_SETTERS.C](https://github.com/MiMendiola/Push_swap/blob/main/src/stack/stack_setters.c)**: This file is tasked with `defining and adjusting specific properties for nodes` within the stack structures, facilitating the management and optimization of the sorting process.

- **t_stack**	***stack_set_min_cost(t_stack** ****stack_a, t_stack** ****stack_b):** This function is dedicated to determining the node with the lowest movement cost between the two stacks, using **`stack_set_push_cost`** to calculate this cost. The selected node, presenting the minimum cost, is returned for later use.

- **void	stack_set_push_cost(t_stack *stack_a, t_stack *stack_b, t_stack *node_a, int *count)**: This function calculates the `cost of movements` required to transfer a specific node from stack A to stack B. It identifies the `target node in stack B` and, based on its relative position (above or below the stack's midpoint), `uses its identifier` to establish the `movement cost count`.

- **void stack_set_target_a(t_stack *main_stack, t_stack *stack_b)**: Sets the `target node in stack B` for a given node in stack A. The `selection criterion` for the target is based on finding the `largest number in stack B` that is `closest to the value of the node in question in stack A`. If the node represents the `minimum value` in the stack, the `target` becomes the `largest number in stack B`, returning the corresponding target node.

- **t_stack**	***stack_set_target_b(t_stack *node, t_stack *stack_a)**: Defines the `target node in stack A` for a specific node in stack B. The target is chosen as the `smallest number in stack A` that `most closely approximates the value of the node in stack B`. If the `node` is the `maximum value`, the `target` will be the `smallest number in stack A`, returning the target node.

- **void	stack_set_top_node(t_stack** ****stack_a, t_stack** ****stack_b, t_stack** ***min_cost)**: With knowledge of the `node` possessing the `minimum transfer cost` to the destination stack, and its `target node`, the necessary `movements` are executed `to position these nodes at the top` of their respective stacks. This process `prioritizes` the `simultaneous rotations` of both stacks to optimize the number of required movements.

**[STACK_SORT.C](https://github.com/MiMendiola/Push_swap/blob/main/src/stack/stack_sort.c)**: This file contains all the critical functions dedicated to sorting nodes within the stacks, ensuring an efficient and optimized handling of data.

- **void	sort_stack_three(t_stack** ****stack):** This function specializes in the `sorting` of stacks containing `three elements`, adjusting their movements based on their current arrangement within the stack.

- **void	sort_push_b(t_stack** ****stack_a, t_stack** ****stack_b):** Its goal is to `transfer elements from stack A to stack B`, provided stack A contains more than three elements and is unordered. During this process, the relative position of elements is evaluated using **`stack_above_half`**, identifying those whose adjustment results in the least movement cost with **`stack_set_min_cost`**. Subsequently, maneuvers are executed to appropriately position the selected elements at the top of the stacks, facilitating their transfer from A to B.

- **void	sort_push_a(t_stack** ****stack_a, t_stack** ****stack_b):** This function is responsible for `moving elements from stack B back to stack A`. It begins by determining the targets in stack B through **`stack_set_target_b`**, using **`stack_above_half`** to assess their position. Rotations in stack A are then conducted until the desired element is aligned at the top, allowing its transfer from stack B.

- **void	sort_stack(t_stack** ****stack_a, t_stack** ****stack_b):** Serves as the `main sorting function`, implementing the algorithm's overall strategy. Initially, it transfers the `first two elements` to stack B, followed by an iterative process with **`sort_push_b`** to relocate elements to stack B, leaving only three in stack A. Once this state is reached, **`sort_push_a`** takes over to reintegrate all elements to stack A. The final phase involves re-establishing the indices and adjusting the position of the smallest element to the beginning of stack A.

- **void	sort_end(t_stack** **stack_a, t_stack** ****stack_b):** This function `concludes the sorting process` through consecutive rotations in stack A, ensuring that the smallest element is positioned at the top of the stack, thus completing the sorting sequence.

**[STACK_UTILS.C](https://github.com/MiMendiola/Push_swap/blob/main/src/stack/stack_utils.c)**: This file is fundamental within the code, as it houses a set of essential functions for the manipulation and management of the utilized data structures.

- **void	free_list(t_stack** ****stack):** This function is crucial for memory management, as it `takes care of freeing` all the `data` from a stack.

- **t_stack *last_node(t_stack *lst)**: Provides `direct access` to the `last node of the list`, optimizing operations that require reference to the end of it.

- **t_stack *new_node(int id, long num)**: This constructor function `creates` a new `node with the specified parameters`. This newly created node is ready to be integrated into the data structure as needed.

- **void	add_node_back(t_stack** ****stack, t_stack** ***new):** Plays a fundamental role, `allowing` the `addition` of a new `node` to the `end of the stack`. In cases where the stack is empty, this node is established as the initial element, ensuring flexibility in the data structure management.

- **long ft_atol_ps(char *str)**: This function aids in `transforming` a `string of characters into a long numerical value`. It incorporates a check to ensure that the resulting number falls within the allowed limits, issuing an error if the value is outside the established range, which prevents potential erroneous behaviors.