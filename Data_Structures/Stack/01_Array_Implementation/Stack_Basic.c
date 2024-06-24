#include "Stack_Basic.h"


/*
*   1- Function to create an empty stack and set it's top to -1
*/
void createEmptyStack (ST_stack_t* stack)
{
    stack->top = EMPTY_STACK;
}


/*
*   2- Function to push
*/
int push (ST_stack_t* stack, int data)
{
    if (stack->top == FULL_STACK)
    {
        return PUSH_STACK_OVERFLOW;
    }

    stack->top++;
    stack->stack_arr[stack->top] = data;

    return PUSH_STACK_IS_AVAILABLE;
}


/*
*   3- Function to pop
*/
int pop (ST_stack_t* stack, int* data)
{
    if (stack->top == EMPTY_STACK)
    {
        return POP_STACK_EMPTY;
    }

    *data = stack->stack_arr[stack->top];
    stack->stack_arr[stack->top] = RESET;
    stack->top--;
    return POP_STACK_IS_AVAILABLE;
}


/*
*   4- Function to print stack
*/
int printStack (ST_stack_t* stack)
{
    if (stack->top == EMPTY_STACK)
    {
        return PRINT_STACK_EMPTY;
    }

    printf("%s", "The stack is: \n");
    for(int currentIndex = stack->top; currentIndex >= BOTTOM; currentIndex--)
    {
        printf("%d \n", stack->stack_arr[currentIndex]);
    }
    return PRINT_STACK_IS_AVAILABLE;
}


/*
*   5- Function to get the current stack top
*/
int getStackTop(ST_stack_t* stack)
{
    if (stack->top == EMPTY_STACK)
    {
        return POP_STACK_EMPTY;
    }
    
    return stack->top; 
}


/*
*   6- Function to test stack whether it is full or not
*/
int isFull (ST_stack_t* stack)
{
    if (stack->top == FULL_STACK)
    {
        return ISFULL_STACK_IS_FULL;
    }
    
    return ISFULL_STACK_IS_NOT_FULL;

}


/*
*   7- Function to test stack whether it is empty or not
*/
int isEmpty (ST_stack_t* stack)
{
    if (stack->top == EMPTY_STACK)
    {
        return ISEMPTY_STACK_EMPTY;
    }

    return ISEMPTY_STACK_IS_NOT_EMPTY;
}


