#include "Converter.h"

ST_stack_t BinaryRepresentationStack;
ST_stack_t* BinaryRepresentationStackPtr = &BinaryRepresentationStack;


/*
*   Stack functions
*/
static void createEmptyStack (ST_stack_t* stack)
{
    stack->top = EMPTY_STACK;
}

static int push (ST_stack_t* stack, int data)
{
    if (stack->top == FULL_STACK)
    {
        return PUSH_STACK_OVERFLOW;
    }

    stack->top++;
    stack->stack_arr[stack->top] = data;

    return PUSH_STACK_IS_AVAILABLE;
}

static int pop (ST_stack_t* stack, int* data)
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

static int printStack (ST_stack_t* stack)
{
    if (stack->top == EMPTY_STACK)
    {
        return PRINT_STACK_EMPTY;
    }

    printf("%s", "The stack is: \n");
    for(int currentIndex = stack->top; currentIndex >= BOTTOM; currentIndex--)
    {
        printf("%d\t", stack->stack_arr[currentIndex]);
    }
    return PRINT_STACK_IS_AVAILABLE;
}


/*
*   Decimal to binary coversion function
*/
void decimalToBinary(int number)
{
    createEmptyStack(BinaryRepresentationStackPtr);

    int remainder = 0;
    while (number != 0)
    {
        remainder = number % 2;
        push(BinaryRepresentationStackPtr, remainder);

        number = number / 2;
    }

    printStack(BinaryRepresentationStackPtr);
    puts("\n");

}
