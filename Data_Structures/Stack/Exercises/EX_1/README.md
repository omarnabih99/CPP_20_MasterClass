# Exercise 1

- Write a program to implement a stack in an array `stack_arr[]` using `stack_arr[0]` as the top element.

- Example: if we want to push 1, 2, 3 in this sequence, the stack wil be (stack starts from left):   1   2   3

- But we want to make the first place in the array to be the topmost,

- instead, the stack will be (stack starts from left):  3   2   1

- It is a good idea to keep track of the `first inserted element` and it is so clear that there is no need to keep track of the last inserted element. The position of the last inserted element is fixed.

- Unlike the regular stack, when we push data in this stack, this data will be shifted upwards as long we push new data to keep the last inserted data at the bottom.

- We have two things to consider:

    1. keep track of the first inserted element.

    2. Shift all elements on step upwards and push the new element at index `0`.

