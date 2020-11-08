# stack_based_postfix_calculator

Implementation of the stack data structure to create a post-fix notation calculator which should be able to work for arbitrary data types (char, int, double, etc.). 
Normally, infix notation is used in regular calculations like 2+4*3, while its postfix notation is 2 4 3 * +.

The algorithm works as follows:

- Read a line from terminal as the user input.
- If the input is a valid integer, you push that integer onto the stack.
- If the input is a valid operator (+, *, /, - ), pop two integers off the stack, perform the requested operation, and push the result back onto the stack.
- If there were less than 2 integers remained in the stack, print a meaningful error message.
- If the user enters “c”, you need to print the final result. If the user input line was not in a correct format, print a meaningful message.
- If the user enters “H”, you halt the program without performing any additional computations.
- For any other input characters, print a meaningful error message.
