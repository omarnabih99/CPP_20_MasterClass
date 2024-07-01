#include "Inverted_Stack.h"

void createEmptyStack (ST_stack_t* stack)
{
    stack->first = EMPTY_STACK;
}

EN_pushError_t push (ST_stack_t* stack, int data)
{
    if (stack->first == FULL_STACK)
    {
        return PUSH_STACK_OVERFLOW;
    }

    stack->first++;
    
    // shift the stack elements to right in order to insert the new data at the start
    for(int moveItem = stack->first; moveItem > 0; moveItem--)
    {
        stack->stack_arr[moveItem] = stack->stack_arr[moveItem - 1];
    }

    stack->stack_arr[BOTTOM] = data;

    return PUSH_STACK_IS_AVAILABLE;
}

EN_popError_t pop (ST_stack_t* stack, int* data)
{
    if(stack->first == EMPTY_STACK)
    {
        return POP_STACK_EMPTY;
    }

    *data = stack->stack_arr[0];
    stack->stack_arr[0] = RESET;

    for (int moveItem = 0; moveItem < stack->first; moveItem++)
    {
        stack->stack_arr[moveItem] = stack->stack_arr[moveItem + 1];
    }

    stack->first--;

    return POP_STACK_IS_AVAILABLE;
}

EN_printError_t printStack (ST_stack_t* stack)
{
    if (stack->first == EMPTY_STACK)
    {
        return PRINT_STACK_EMPTY;
    }

    printf("%s", "The stack is: \n");
    for(int index = 0; index <= stack->first; index++)
    {
        printf("%d \n", stack->stack_arr[index]);
    }

    return PRINT_STACK_IS_AVAILABLE;
}

int getStackFirst(ST_stack_t* stack)
{
    if (stack->first == EMPTY_STACK)
    {
        return POP_STACK_EMPTY;
    }
    
    return stack->first; 
}

EN_isFull_t isFull (ST_stack_t* stack)
{
    if (stack->first == FULL_STACK)
    {
        return ISFULL_STACK_IS_FULL;
    }
    
    return ISFULL_STACK_IS_NOT_FULL;

}

EN_isEmpty_t isEmpty (ST_stack_t* stack)
{
    if (stack->first == EMPTY_STACK)
    {
        return ISEMPTY_STACK_EMPTY;
    }

    return ISEMPTY_STACK_IS_NOT_EMPTY;
}

