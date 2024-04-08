# Checker

The `bonus` part of our `Push_Swap` project, named `checker`, works as a validator for operations input via the terminal, with the `goal` of verifying whether these operations lead to an ordered sequence. To implement this functionality, we integrate the use of our **`get_next_line`** function configured with `file descriptor 0`, permitting the reading of operations from the `standard input` until the end of input is signaled with `Ctrl + D`. Additionally, the program automatically terminates in situations where the supplied argument sequence is empty or contains a single number, in which case the confirmation OK is issued.

**[CHECKER.C](https://github.com/MiMendiola/Push_swap/blob/main/src/checker.c)**: The logic of `checker` is structured around three key functions:

- **void	execute_rotates(t_stack** ****stack_a, t_stack** ****stack_b, char** ***move)**: This function is responsible for executing rotation operations on stacks A and B, selecting the specific operation depending on the `move` argument provided.

- **void	execute_moves(t_stack** ****stack_a, t_stack** ****stack_b, char** ***move)**: Designed to implement the operations indicated by the **`get_next_line`** function on the stacks. This function is further broken down to specifically address rotations, both normal and reverse, facilitating the management of movements to the stacks.

- **int	main(int ac, char *av[])**: The main function of `checker` starts by allocating the necessary space for the stacks. If multiple arguments are received, it proceeds with creating the stack structure used in `Push_Swap`. Then, it sequentially reads operations from the terminal until the end of input is signaled with `Ctrl + D`, applying each read operation to the stacks via **`execute_moves`**. Finally, it checks whether the resulting sequence in the stack is ordered or if there is any error in the sequence.