# Push_swap

<div>

  ![Project](https://img.shields.io/badge/Project-Push_swap-blue)
  ![Licence](https://img.shields.io/badge/Licence-MIT-orange)
  ![Version](https://img.shields.io/badge/Version-1.0-green)
  <a href="https://github.com/MiMendiola/Push_swap/tree/main/Documentation/es/README.es.md" >
    <img src="https://img.shields.io/badge/Cambiar_Idioma-Español-purple" align="right">
  </a>

</div>

The `Push_swap` project revolves arround sorting a `list of numbers` using two stacks, A and B, with a `limited set of instructions` . The aim of this project is to sort the numbers in the `least amount of moves`. This will introduce us to some of the most common `sorting algorithms` and also how to effectively and fluidly use `structures` that will aid us in tackling future challenges we encounter.

The process starts by verifying the validity of the numerical sequence, which is stored in stack A. For unordered sequences of `two elements`, a simple swap with `SA` is used to sort them. With `three elements`, a specific sorting function is used. For larger sequences, a more complex algorithm suitable for larger volumes of data is adopted.

The **`Turk Algorithm`** involves organizing the numbers through an `analysis of the performance` associated with each move simultaneously. Initially, we will move the first two numbers to stack B, regardless of their value.

Subsequently, elements will be selectively chosen based on those with the `lowest cost of movements`, prioritizing the `largest number` that is `closest` in stack A. We will assign an index to each node to determine the most efficient operation to use. Necessary rotations will be performed to `place these elements at the top of the stack`, and then transfer them to stack B. 

We will proceed with sorting the three numbers in stack A. Upon completion,   `a target node from stack B` will be set to the `closest smaller number in stack A.` The goal here is to have these numbers at the top of stack B, and then move them to stack A. We will repeat this process until the `stack B` is completely `empty`.

Finally, we will identify the element with the `lowest value in the stack`, and depending on whether its `position` is in the `upper or lower half of the stack`, we will execute the `appropriate rotation` to position it at the beginning of the stack.

The `bonus` part of this project will be the creation of a `checker`, which will validate whether the given instructions determine if our stack of numbers is correctly sorted.

For a `detailed explanation` of each part of the project, including how the sorting algorithms work and how the stack operations are implemented, refer to the `Table of Contents` section below.

---

## **Table of Contents**

[MOVEMENTS](https://github.com/MiMendiola/Push_Swap/tree/main/Documentation/MOVEMENTS.md)

[STACK](https://github.com/MiMendiola/Push_Swap/tree/main/Documentation/STACK.md)

[CHECKER](https://github.com/MiMendiola/Push_Swap/tree/main/Documentation/CHECKER.md)

---

## **Recommendations**

Review algorithms to clearly understand which one you want to implement, and look for the efficiency of each.

Be clear about how far you want to go in the project, if you aim for the highest score I recommend reading about the Turk Algorithm.

Argument validation is a priority for the success of the project.

Efficient management of data structures is crucial, as we will work with doubly linked lists.

The use of debugging tools will facilitate problem-solving in instructions and structures.

---

## **Contact**

If you have any questions, suggestions, or comments about `Push_swap`, please feel free to contact me:

- **Email:** [mglmendiol@gmail.com](mailto:mglmendiol@gmail.com)
- **LinkedIn:** [https://www.linkedin.com/in/mimendiola/](https://www.linkedin.com/in/mimendiola/)