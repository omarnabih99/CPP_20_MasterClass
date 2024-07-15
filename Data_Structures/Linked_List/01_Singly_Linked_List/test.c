#include "Single_Linked_List.h"

ST_list_t myList;
ST_list_t* myListPtr = &myList;

int main()
{

    //  1- test the insert functions
    createEmptyList(myListPtr);

    insertToListHead(myListPtr, 1);
    printList(myListPtr);
    printf("list size: %d\n", myListPtr->listSize);
    puts("###########");

    optimalInsertToTail(myListPtr, 2);
    printList(myListPtr);
    printf("list size: %d\n", myListPtr->listSize);
    puts("###########");

    insertToList(myListPtr, 3, 3);
    printList(myListPtr);
    printf("list size: %d\n", myListPtr->listSize);
    puts("###########");

    insertToListHead(myListPtr, 0);
    printList(myListPtr);
    printf("list size: %d\n", myListPtr->listSize);
    puts("###########");

    optimalInsertToTail(myListPtr, 4);
    printList(myListPtr);
    printf("list size: %d\n", myListPtr->listSize);
    puts("###########");  

    insertToList(myListPtr, 6, 5);
    printList(myListPtr);
    printf("list size: %d\n", myListPtr->listSize);
    puts("###########");

    int linkState = insertToList(myListPtr, 8, 6);
    if (linkState == insertToList_WRONG_POSITION)
    {
        puts("Wrong Position");
    }
    printList(myListPtr);
    printf("list size: %d\n", myListPtr->listSize);
    puts("###########");


    //  2- test the delete function
    deleteFromList(myListPtr, 1);
    printList(myListPtr);
    printf("list size: %d\n", myListPtr->listSize);
    puts("###########");
    
    deleteFromList(myListPtr, 3);
    printList(myListPtr);
    printf("list size: %d\n", myListPtr->listSize);
    puts("###########");

    deleteFromList(myListPtr, 4);
    printList(myListPtr);
    printf("list size: %d\n", myListPtr->listSize);
    puts("###########");

    for (int index = 1; index <= 4; index++)
    {
        linkState = deleteFromList(myListPtr, 1);
        if(linkState == deleteFromList_LIST_IS_EMPTY)
        {
            puts("Cannot delete from empty list");
        }

        linkState = printList(myListPtr);
        if (linkState == printList_LIST_IS_EMPTY)
        {
            puts("Cannot print empty list");
        }
        printf("list size: %d\n", myListPtr->listSize);
        puts("###########");        
    }

    insertToList(myListPtr, 1, 1);
    printList(myListPtr);
    printf("list size: %d\n", myListPtr->listSize);
    puts("###########");

    deleteFromList(myListPtr, 1);
    linkState = printList(myListPtr);
    if (linkState == printList_LIST_IS_EMPTY)
    {
        puts("Cannot print empty list");
    }
    printf("list size: %d\n", myListPtr->listSize);
    puts("###########");

    for (int index = 1; index <=5; index++)
    {
        insertToList(myListPtr, index, index);
    }
    linkState = printList(myListPtr);
    if (linkState == printList_LIST_IS_EMPTY)
    {
        puts("Cannot print empty list");
    }
    printf("list size: %d\n", myListPtr->listSize);
    puts("###########");

    //  3- test the reverse function
    reverseList(myListPtr);
    linkState = printList(myListPtr);
    if (linkState == printList_LIST_IS_EMPTY)
    {
        puts("Cannot print empty list");
    }
    printf("list size: %d\n", myListPtr->listSize);
    puts("###########");

    reverseList(myListPtr);
    linkState = printList(myListPtr);
    if (linkState == printList_LIST_IS_EMPTY)
    {
        puts("Cannot print empty list");
    }
    printf("list size: %d\n", myListPtr->listSize);
    puts("###########");         

}