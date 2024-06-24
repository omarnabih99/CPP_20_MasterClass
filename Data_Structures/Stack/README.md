# Stacks

- Stack is a linear data structure that follows Last In First Out `LIFO` principle.

- A real-life example of a stack is book stack, stack tower, ..., etc.

- Inserting in a stack is called `push`.

- `Push` means adding to the top of the stack.

- Removing from a stack is called `pop`.

- `Pop` means removing from stack top.

- Any stack is charactrized by it's size and top.

## Push operation

- Push means adding at the top of the stack.

- example: A stack is represented by an array of 10 integers:

    - At first, the stack is empty. So, the top is -1.

    - On the first push, the top will increment to 0( stack[0] ) then stores the data in the first place.

    - On the second push, the top will increment to 1 and stores the data in the second place and so on.

    - This operation will continue till reaching stack[9]. The top now points to the last place in the stack which means that the stack is full.

    - Steps to push data into the stack:

        1. Check if the stack is full.

        2. If full -> print stack overflow error.

        3. If not full -> increment the top.

        4. Store the data.

## Pop operation

- Pop means removing from stack top.

- Steps to pop data from stack:

    1. Check if the stack is empty.

    2. If empty -> print stack is empty error.

    3. If not empty -> read data from the stack array.

    4. Decrement the top.

## How to implement a stack

1. Declare a global or local variable that defines the stack and it's size, it's usually a structure with two members: array and integer.

2. Implement `push` and `pop` functions as the main fucntions of the stack.

3. Implement `isEmpty`, `isFull`, `printStack`, and `getStackTop` functions as a helper and utility functions.

4. Stacks can be also implemented using `Linked Lists`.

