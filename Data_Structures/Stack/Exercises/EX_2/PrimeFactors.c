#include "PrimeFactors.h"


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


/*
*   Prime factors function
*/
void primeFactor(int inputNumber)
{
    ST_stack_t primeFactorsStack;
    ST_stack_t* primeFactorsStackPtr = &primeFactorsStack;

    createEmptyStack(primeFactorsStackPtr);

    int divisor = FIRST_PRIME_NUMBER;
    while (inputNumber != PRIME_STOP_VALUE)
    {
        while ( (inputNumber % divisor) == 0)
        {
            push (primeFactorsStackPtr, divisor);
            inputNumber = inputNumber / divisor;
        }

        divisor++;
    }

    printf("%s", "Prime factors in descending order: \n");
    while (primeFactorsStackPtr->top != EMPTY_STACK)
    {
        int value;
        pop (primeFactorsStackPtr, &value);
        printf("%d \n", value);
    }

}