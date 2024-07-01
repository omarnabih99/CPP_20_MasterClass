#include <stdio.h>
#include <stdlib.h>


#define STACK_SIZE    (20)
#define EMPTY_STACK   (-1)
#define FULL_STACK    (STACK_SIZE - 1)
#define RESET         (0)
#define BOTTOM        (0)

#define FIRST_PRIME_NUMBER (2)
#define PRIME_STOP_VALUE         (1)

#define SENTINEL_VALUE (-1)

typedef struct ST_stack_t
{
    int stack_arr    [STACK_SIZE];  // stack like array
    int top;                        // a variable to keep track of the topmost element in the array
}ST_stack_t;

typedef enum EN_pushError_t
{
    PUSH_STACK_OVERFLOW,
    PUSH_STACK_IS_AVAILABLE
}EN_pushError_t;

typedef enum EN_popError_t
{
    POP_STACK_EMPTY,
    POP_STACK_IS_AVAILABLE
}EN_popError_t;


/*
*   Prime factors function
*/
void primeFactor(int number);