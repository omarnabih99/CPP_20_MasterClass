#include "Converter.h"

ST_stack_t BinaryRepresentationStack;
ST_stack_t* BinaryRepresentationStackPtr = &BinaryRepresentationStack;


/*
*   Stack functions declarations
*/
static void createEmptyStack (ST_stack_t* stack);
static EN_pushError_t push (ST_stack_t* stack, int data);
static EN_popError_t pop (ST_stack_t* stack, int* data);
static EN_printError_t printStack (ST_stack_t* stack);


/*
*   Decimal to binary coversion function
*/
void decimalToBinary(int number)
{
    createEmptyStack(BinaryRepresentationStackPtr);

    EN_pushError_t pushState;
    EN_printError_t printState;

    int remainder = 0;
    while (number != 0)
    {
        remainder = number % 2;

        pushState = push(BinaryRepresentationStackPtr, remainder);
        if (pushState == PUSH_STACK_OVERFLOW)
        {
            printf("%s", "Stackoverflow \n");
            break;
        }

        number = number / 2;
    }

    printState = printStack(BinaryRepresentationStackPtr);
    if (printState == PRINT_STACK_EMPTY)
    {
        printf("%s", "Stack is empty");
    }
    printf("%s", "\n");
}


/*
*   Stack functions
*/
static void createEmptyStack (ST_stack_t* stack)
{
    stack->top = EMPTY_STACK;
}

static EN_pushError_t push (ST_stack_t* stack, int data)
{
    if (stack->top == FULL_STACK)
    {
        return PUSH_STACK_OVERFLOW;
    }

    stack->top++;
    stack->stack_arr[stack->top] = data;

    return PUSH_STACK_IS_AVAILABLE;
}

static EN_popError_t pop (ST_stack_t* stack, int* data)
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

static EN_printError_t printStack (ST_stack_t* stack)
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


