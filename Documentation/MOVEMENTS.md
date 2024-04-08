# Movements

The allowed operations are:

- **PA**: Move the top element from stack B to the top of stack A.
- **PB**: Move the top element from stack A to the top of stack B.
- **SA**: Swap the first two elements at the top of stack A.
- **SB**: Swap the first two elements at the top of stack B.
- **SS**: Perform SA and SB simultaneously.
- **RA**: Move up all elements of stack A, making the first node the last one.
- **RB**: Move up all elements of stack B, making the first node the last one.
- **RR**: Perform RA and RB simultaneously.
- **RRA**: Move down all elements of stack A, making the last node the first one.
- **RRB**: Move down all elements of stack B, making the last node the first one.
- **RRR**: Perform RRA and RRB simultaneously.

These are the moves with which we will order our stacks. I have divided each `move by file`, promoting a cleaner and more organized code to improve understanding and program maintenance.

**[PUSH.C](https://github.com/MiMendiola/Push_swap/blob/main/src/movements/push.c)**: Contains the movements for `transferring nodes` between stacks.

- **void push_node(t_stack** ****stack, t_stack** ****node):** This function is responsible for `transferring a node` from one stack to another. We will use a temporary variable to save the `node to move`. If the destination stack is empty, the node to move will be the first and only element, marking its next node as NULL to indicate the end of the list. If the destination stack contains nodes, the node to move will be added to the beginning, adjusting the pointers' directions to maintain information integrity. In the end, `we will equal the original stack to the node to move`, which will now be the beginning of our stack, thus completing the move.
- **void	push(t_stack** ****stack_a, t_stack** ****stack_b, int move):** This function will help us determine the move to execute. Depending on the move (PA or PB), we will call the **`push_node`** function with the corresponding parameters, either to transfer a node from B to A or vice versa. After making the move, we will display the move performed on the screen.

**[SWAP.C](https://github.com/MiMendiola/Push_swap/blob/main/src/movements/swap.c)**: Includes operations to `swap` the `first two elements` of any stack.

- **void	swap_node(t_stack** ****stack):** Responsible for `swapping` the `first two elements` of the specified stack. To optimize the process, we will choose to swap only their values. This is achieved by using `two temporary variables`: one to store the `first element` and another for the `second element` of the stack, thus adjusting the values to be able to make the swap and complete the move without altering the structure.
- **void	swap(t_stack** ****stack_a, t_stack** ****stack_b, int move):** This function will help us determine the move to execute. Depending on the move (SA, SB, or SS), we will call the **`swap_node`** function. In the case of `SS`, we will execute this function `for both stack A and B`. Once the move is executed, we will display it on the screen.

**[ROTATE.C](https://github.com/MiMendiola/Push_swap/blob/main/src/movements/rotate.c)**: Includes movements to `rotate` the stack, placing the `first element as the last`.

- **void	rotate_node(t_stack** ****stack):** Designated to perform the `rotation` of the specified stack. We will use `two auxiliary variables`: one to store the `second node` and another for the `last node` of the stack. If the stack contains nodes, we will adjust the pointers' directions to preserve the integrity of the structure. Finally, `we will reassign` the stack to the `second element`, thus completing the rotation.
- **void	rotate(t_stack** ****stack_a, t_stack** ****stack_b, int move):** This function will help us determine the move to execute. Depending on the move (RA, RB, or RR), we will call the **`rotate_node`** function. In the case of `RR`, we will execute this function `for both stack A and B`. Once the move is executed, we will display it on the screen.

**[REVERSE_ROTATE.C](https://github.com/MiMendiola/Push_swap/blob/main/src/movements/reverse_rotate.c)**: Contains operations to `rotate` the stack, placing the `last element as the first`.

- **void	reverse_rotate_node(t_stack** ****stack):** Designated to perform the `reverse rotation` of the specified stack. We will use `two auxiliary variables`: one to store the `last node` and another for the `penultimate node` of the stack. If the stack contains nodes, we will adjust the pointers' directions to preserve the integrity of the structure. Finally, `we will reassign` the stack to the `last element`, thus completing the reverse rotation.
- **void	reverse_rotate(t_stack** ****stack_a, t_stack** ****stack_b, int move):** This function will help us determine the move to execute. Depending on the move (RRA, RRB, or RRR), we will call the **`reverse_rotate_node`** function. In the case of `RRR`, we will execute this function `for both stack A and B`. Once the move is executed, we will display it on the screen.