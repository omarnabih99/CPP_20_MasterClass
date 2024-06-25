#include <stdio.h>
#include <stdlib.h>


#define STACK_SIZE    (5)
#define EMPTY_STACK   (-1)
#define FULL_STACK    (STACK_SIZE - 1)
#define RESET         (0)
#define BOTTOM        (0)

/*Application control defs*/
#define PUSH 1
#define POP  2
#define EXIT 3


/*
*   1- Struct to define the stack and stack size
*
*   - We know that stack_arr[] is an array, where insertion and deletion operations
*   can be performed at any place.
*
*   - But we want the stack_arr[] to behave like a stack where insertions and deletions
*   must be performed at the top of stack only.
*/
typedef struct stack
{
    int stack_arr    [STACK_SIZE];  // stack like array
    int first;                      // a variable to keep track of the first inserted element
}ST_stack_t;


/*
*   2- Function to create an empty stack and set it's first to -1
*/
void createEmptyStack (ST_stack_t* stack);


/*
*   3- Function to push
*/
int push (ST_stack_t* stack, int data);


/*
*   4- Function to pop
*/
int pop (ST_stack_t* stack, int* data);


/*
*   5- Function to print stack
*/
int printStack (ST_stack_t* stack);


/*
*   6- Function to get the current stack first
*/
int getStackFirst(ST_stack_t* stack);


/*
*   7- Function to test stack whether it is full or not
*/
int isFull (ST_stack_t* stack);


/*
*   8- Function to test stack whether it is empty or not
*/
int isEmpty (ST_stack_t* stack);



/*
*   9- push error type
*/
typedef enum EN_pushError_t
{
    PUSH_STACK_OVERFLOW,
    PUSH_STACK_IS_AVAILABLE
}EN_pushError_t;


/*
*   10- pop error type
*/
typedef enum EN_popError_t
{
    POP_STACK_EMPTY,
    POP_STACK_IS_AVAILABLE
}EN_popError_t;


/*
*   11- print error type
*/
typedef enum EN_printError_t
{
    PRINT_STACK_EMPTY,
    PRINT_STACK_IS_AVAILABLE
}EN_printError_t;


/*
*   12- isFull return type
*/
typedef enum EN_isFull_t
{
    ISFULL_STACK_IS_NOT_FULL,
    ISFULL_STACK_IS_FULL
}EN_isFull_t;


/*
*   13- isEmpty return type
*/
typedef enum EN_isEmpty_t
{
    ISEMPTY_STACK_IS_NOT_EMPTY,
    ISEMPTY_STACK_EMPTY
}EN_isEmpty_t;