#include "Inverted_Stack.h"

ST_stack_t myStack;
ST_stack_t* myStackPtr = &myStack;

int main()
{
    createEmptyStack(myStackPtr);

    printf("%s", "Enter your choice: \n");
    printf("%s", "1 to push a value to the stack \n");
    printf("%s", "2 to pop a value to the stack \n");
    printf("%s", "3 to exit the program \n");
    printf("%s", "?");
    int inputDecision;
    scanf("%d", &inputDecision);

    int value = 0;
    while(inputDecision != EXIT)
    {
        int stackState = PUSH_STACK_IS_AVAILABLE;

        switch (inputDecision)
        {
            case PUSH:
                if(isFull(myStackPtr))
                {
                   printf("%s", "The stack is full \n");
                   break; 
                }

                printf("%s", "Enter the value to be pushed: ");
                scanf("%d", &value);

                stackState = push(myStackPtr, value);

                if(stackState == PUSH_STACK_OVERFLOW)
                {
                    printf("%s", "The stack is full \n");
                    printStack(myStackPtr);
                    break;
                }
                else if(stackState == PUSH_STACK_IS_AVAILABLE)
                {
                    printf("%s", "Push is done \n");
                    printStack(myStackPtr);
                }
                break;
            

            case POP:
                if(isEmpty(myStackPtr))
                {
                    printf("%s", "The stack is empty \n");
                    break;
                }

                stackState = pop(myStackPtr, &value);
                if(stackState == POP_STACK_EMPTY)
                {
                    printf("%s", "The stack is empty \n");
                    break;
                }
                else if(stackState == POP_STACK_IS_AVAILABLE)
                {
                    printf("The popped value is: %d \n", value);
                    printStack(myStackPtr);
                }
                break;


            default:
                printf("%s", "Invalid choice \n");
                printf("%s", "Enter your choice: \n");
                printf("%s", "1 to push a value to the stack \n");
                printf("%s", "2 to pop a value to the stack \n");
                printf("%s", "3 to exit the program \n");
                break;
        }

        printf("%s", "?");
        scanf("%d", &inputDecision);
    }

    printf("%s", "End of program \n");
}