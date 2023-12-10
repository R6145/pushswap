
**The Push Swap algorithm** is a sorting technique designed to arrange a stack of numbers in ascending order, using two stacks and a specific set of operations.

**How It Works:**
Initial Setup: The algorithm takes a list of numbers as input and places them onto a stack (Stack A) while keeping the other stack (Stack B) empty initially.

**Sorting Operations:** 
It uses a defined set of operations (such as swapping elements, rotating the stack, and pushing elements between stacks) to reorder the numbers in Stack A to achieve the desired sorted order.

**Minimizing Operations:** 
The goal of the push swap algorithm is not only to sort the numbers but also to do it efficiently with the minimum number of operations.

**Optimization:** 
Various strategies and algorithms can be employed to minimize the number of operations required to sort the stack efficiently.

**Allowed Operations:**
**sa (swap a):** Swap the first 2 elements at the top of stack a.
**sb (swap b):** Swap the first 2 elements at the top of stack b.
**ss :** sa and sb at the same time.
**pa (push a):** Take the first element at the top of b and put it at the top of a.
**pb (push b):** Take the first element at the top of a and put it at the top of b.
**ra (rotate a):** Shift up all elements of stack a by 1.
**rb (rotate b):** Shift up all elements of stack b by 1.
**rr :** ra and rb at the same time.
**rra (reverse rotate a)**: Shift down all elements of stack a by 1.
**rrb (reverse rotate b):** Shift down all elements of stack b by 1.
**rrr :** rra and rrb at the same time.

**Sorting:**
The code sorts by :-

 - First chunck the numbers by pushing them to stack b (stack b becomes
    semi sorted). 
 - Then use the mechanical turk algorithm to return the numbers to stack a sorted.

**Bugs and faults:**

 - The parsing of the code fails when "12-42" is typed.
 - Sometime the code goes over the 700 mark (up to 720) when testing 100 numbers.
 - The code works using arrays instead of linked lists which make use of much more memory. 


