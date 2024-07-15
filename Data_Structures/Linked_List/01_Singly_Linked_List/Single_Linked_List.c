#include "Single_Linked_List.h"


/********************************************************************************************
*   1- This function initialize the list parameters
*   Time Complexity is O(1)
*   Head, Tail, and List Size are initialized as follows
*********************************************************************************************/
void createEmptyList(ST_list_t* list)
{
    list->head = NULL;
    list->tail = NULL;
    list->listSize = EMPTY_LIST;
}



/********************************************************************************************
*   2- This function inserts a new node to the head of the list.
*   Time complexity is O(1) as it doesn't contain any looping. So, number of operations doesn't depend on the data size.
*********************************************************************************************/
EN_insertToListHead_t insertToListHead(ST_list_t* list, int data)
{
    ST_listNode_t* allocatedNodePtr = NULL;

    // 1- allocate node in the heap
    allocatedNodePtr = (ST_listNode_t*) malloc(sizeof(ST_listNode_t));
    if(allocatedNodePtr == NULL)
    {
        return insertToListHead_ALLOCATION_FAILED;
    }

    // 2- store the data into node
    allocatedNodePtr->data = data;

    // 3- make the node link points to what the head points to
    allocatedNodePtr->link = list->head;

    // 4- make the head pointer points to the created node
    list->head = allocatedNodePtr;


    // 5- increment the size of the list
    list->listSize++;

    // 6- keep track of the tail of the list. while inserting to head, the tail will be the address of the first inserted node
    if(list->listSize == 1)
    {
        list->tail = allocatedNodePtr;
    }

    return insertToListHead_OK;
}
                                                              


/********************************************************************************************
*   3- This function inserts a new node to the tail of the list.
*   This function has a time complexity of O(n) due to the while loop used to traverse the whole list till reaching the tail using head pointer.
*   This function can not be used with empty list. There must be head node initially.
*********************************************************************************************/
EN_insertToListTail_t insertToListTail(ST_list_t* list, int data)
{
    if(list ->head == NULL)
    {
        return insertToListTail_EMPTY_LIST;
    }

    // 1- create a pointer to hold the address of the memory allocated for the node
    ST_listNode_t* allocatedNodePtr = NULL;

    // 2- allocate a memory for the node
    allocatedNodePtr = (ST_listNode_t*)malloc(sizeof(ST_listNode_t));

    // 3- check if the allocation is successful
    if (allocatedNodePtr == NULL)
    {
        return insertToListTail_ALLOCATION_FAILED;
    }

    // 4- store the data
    allocatedNodePtr->data = data;

    // 5- make the link pointer in the newely allocated node to point to NULL to be the tail node
    allocatedNodePtr->link = NULL;

    // 6- traverse through the list to find the current tail node
    ST_listNode_t* tempPtr = list->head;
    while(tempPtr->link != NULL)
    {
        tempPtr = tempPtr->link;
    }

    // 7- make the link pointer in the current tail node to point to the newely allocated node instead of pointing to NULL
    tempPtr->link = allocatedNodePtr;

    // 8- increment the list size
    list->listSize++;

    // 9- keep track of the tail of the list. while inserting to tail, the tail will be the address of the last inserted node
    list->tail = allocatedNodePtr;

    // 10- return OK
    return insertToListTail_OK;
}   



/********************************************************************************************
*   4- This is the optimal version of insertToListTail function.
*   This function has a time complexity of O(1) as it doesn't traverse the list.
*   It uses the tail pointer directly.
*   This function can not be used with empty list. There must be head node initially.
*********************************************************************************************/
EN_optimalInsertToListTail_t optimalInsertToTail(ST_list_t* list, int data)
{
    if(list ->head == NULL)
    {
        return optimalInsertToListTail_EMPTY_LIST;
    }

    // 1- create a pointer to hold the address of the memory allocated for the node
    ST_listNode_t* allocatedNodePtr = NULL;

    // 2- allocate a memory for the node
    allocatedNodePtr = (ST_listNode_t*)malloc(sizeof(ST_listNode_t));

    // 3- check if the allocation is successful
    if (allocatedNodePtr == NULL)
    {
        return optimalInsertToListTail_ALLOCATION_FAILED;
    }

    // 4- store the data
    allocatedNodePtr->data = data;

    // 5- make the link pointer in the newely allocated node to point to NULL to be the tail node
    allocatedNodePtr->link = NULL;

    // 6- make the link pointer in the current tail node to point to the newely allocated node instead of pointing to NULL
    list->tail->link = allocatedNodePtr;

    // 7-keep track of the tail of the list. while inserting to tail, the tail will be the address of the last inserted node
    list->tail = allocatedNodePtr;

    // 8- increment list size
    list->listSize++;

    // 9- return OK
    return optimalInsertToListTail_OK;
}



/********************************************************************************************
*   5- This function inserts a new node at any position of the list.
*   The list is indexed starting from 1.
*   This function is generic, it can insert at head, at tail, or any position between them.
*   Time Complexity is O(n) as it loops till reaching to the node whose link is the address of the position where we want to insert into
*********************************************************************************************/
EN_insertToList_t insertToList(ST_list_t* list, int position, int data)
{
    // 1- allocate memory for the node
    ST_listNode_t* allocatedNodePtr = NULL;
    allocatedNodePtr = (ST_listNode_t*)malloc(sizeof(ST_listNode_t));
    if (allocatedNodePtr == NULL)
    {
        return insertToList_ALLOCATION_FAILED;
    }

    // 2- initialize the node
    allocatedNodePtr->data = data;
    allocatedNodePtr->link = NULL;

    // 3- Update the links
    // a- If I want to insert to first position -> I will use insert to head logic.
    if (position == INSERT_TO_HEAD)
    {
        // a- update the link part of the new allocated node to point at which head points to
        allocatedNodePtr->link = list->head;
        // b- update the head
        list->head = allocatedNodePtr;
        // c- increment the list size
        list->listSize++;
        // d- keep track of the tail
        if(list->listSize == 1)
        {
            list->tail = allocatedNodePtr;
        }
        // e- return OK
        return insertToList_OK;            
    }

    // b- If I want to insert to the last position -> I will use optimal insert to tail logic
    else if(position == INSERT_TO_TAIL)
    {
        // a- update the link part of the current tail node to point to the newely created node
        list->tail->link = allocatedNodePtr;
        // b- update the tail pointer to point to the newely created node
        list->tail = allocatedNodePtr;
        // c- increment the list size
        list->listSize++;
        // d- return ok
        return insertToList_OK;
    }

    // c- If I want to insert between the head and tail
    else if ((position > INSERT_TO_HEAD) && (position < INSERT_TO_TAIL))
    {
        ST_listNode_t* previousNode = list->head;
        for(int index = 1; index < (position - 1); index++)
        {
            previousNode = previousNode->link;
        }
        // a- update the link part of the new allocated node to point at the node which the previous node points to
        allocatedNodePtr->link = previousNode->link;
        // b- update the link part of the previous node 
        previousNode->link = allocatedNodePtr;
        // c- increment list size
        list->listSize++;
        // d- return ok
        return insertToList_OK;
    }

    // d- if I want to insert before head and after tail -> wrong position error
    else
    {
        return insertToList_WRONG_POSITION;
    }
}



/********************************************************************************************
*   6- This functions deletes a node from head and assign the just before node to be the new head
*   This functions returns list is empty error if we attempted to delete node from empty list
*   Time complexity is O(1)
*********************************************************************************************/
EN_deleteFromListHead_t deleteFromListHead(ST_list_t* list)
{
    // 1- check if the list is empty
    if(list->head == NULL)
    {
        return deleteFromListHead_LIST_IS_EMPTY;
    }

    // 2- store the address of the head node in a temp pointer
    ST_listNode_t* tempPtr = list->head;

    // 3- make the head pointer points to what the head node link pointer points to
    list->head = list->head->link;

    // 4- free the allocated memory pointed by the temp pointer;
    free(tempPtr);
    tempPtr = NULL;

    // 5- decrement the size of the list
    list->listSize--;

    // 6- after deleting the last head, the tail and the head become null again
    if(list->listSize == EMPTY_LIST)
    {
        list->tail = list->head;
    }

    return deleteFromListHead_OK;
}



/********************************************************************************************
*   7- This function deletes the tail node and assign the just before node to be the new tail.
*   This function loops till finding the node just before the tail node to be the new tail. So, Time complexity will be O(n).
*********************************************************************************************/
EN_deleteFromListTail_t deleteFromListTail(ST_list_t* list)
{
    // 1- check if the list is empty
    if(list->head == NULL)
    {
        return deleteFromListTail_LIST_IS_EMPTY;
    }
    // 2- check if the list has only one node
    else if(list->head->link == NULL)
    {
        free(list->head);
        list->head = NULL;
        list->tail = list->head;
        list->listSize--;
        return deleteFromListTail_OK;
    }
    // 3- check if the list has more than one node
    else
    {
        // a- define the temp pointer
        ST_listNode_t* tempPtr = list->head;

        // b- search for the node just before the current tail node
        while(tempPtr->link->link != NULL)
        {
            tempPtr = tempPtr->link;
        }

        // c- delete the current tail node
        free(tempPtr->link);

        // d- assign NULL to the new tail node link part
        tempPtr->link = NULL;

        // e- update the list tail
        list->tail = tempPtr;

        // f- decrement the list size
        list->listSize--;

        // g- return ok
        return deleteFromListTail_OK;
    }
}


/********************************************************************************************
*   8- This function deletes a node from any position
*   This function loops till finding the desired node. So, Time Complexity is O(n)
*********************************************************************************************/
EN_deleteFromList_t deleteFromList(ST_list_t* list, int position)
{
    // 1- check if the list is empty.
    if(list->head == NULL)
    {
        return deleteFromList_LIST_IS_EMPTY;
    }
    // 2- check if the list has only one node.
    else if(list->head->link == NULL)
    {
        free(list->head);
        list->head = NULL;
        list->tail = list->head;
        list->listSize--;
        return deleteFromList_OK;
    }
    // 3- check if the list has more than one node.
    else
    {
        // a- check if delete first position -> use delete from head logic.
        if(position == DELETE_FROM_HEAD)
        {
            deleteFromListHead(list);              
            return deleteFromList_OK;
        }
        // b- check if delete last position which equals to the list size -> use delete from tail logic.
        else if(position == DELETE_FROM_TAIL)
        {
            deleteFromListTail(list);
            return deleteFromList_OK;
        }
        // c- check if the position between head and tail.
        else if(  (position > DELETE_FROM_HEAD) && (position < DELETE_FROM_TAIL) )
        {
            // 1- define current pointer to point to the desired node (n) to be deleted.
            ST_listNode_t* current = list->head;

            // 2- define the previous pointer to point to the node just before the node to be deleted (n-1) in order to update it's link part.
            ST_listNode_t* previous = list->head;

            // 3- search for the desired node and it's previous node.
            // to reach node (n) we must fetch the link part of node (n-1). So, we need to loop (n-1) times.
            for(int index = 1; index < position; index++)
            {
                previous = current;
                current = current->link;
            }

            // 4- update the link part of the previous node (n-1) to point to the node which the to be deleted node points to (n+1).
            // Now, node (n-1) and node (n+1) are linked.
            previous->link = current->link;

            // 5- delete the current node (n)
            free(current);
            current = NULL;

            // 6- decrement the list size
            list->listSize--;

            // 7- return OK
            return deleteFromList_OK;
        }
        // d- check if the position is out of range
        else
        { 
            return deleteFromList_WRONGPOSITION;
        }
    }        
}



/********************************************************************************************
*   9- This function deletes the whole list.
*   We can loop on the list and use any implemented delete function.
*   But we will implement this function from scratch.
*   Time Complexity is O(n) as it loops the whole list to delete the all nodes.
*********************************************************************************************/
EN_deleteList_t deleteList(ST_list_t* list)
{
    // 1- check if the list is empty
    if (list->head == NULL)
    {
        return deleteList_EMPTY_LIST;
    }

    // 2- reset the tail pointer to null as the whole list will be deleted
    list->tail = NULL;

    // 3- define a temp pointer to store the address of the next node while the first one is being deleted
    ST_listNode_t* tempPtr = list->head;

    // 4- traverse on the list till reaching to the NULL
    // for (n) nodes list, we will loop n times.
    // decrement the list size to reset it to zero
    while (tempPtr != NULL)
    {
        tempPtr = tempPtr->link;
        free(list->head);
        list->head = tempPtr;
        list->listSize--;
    }

    // 5- return OK
    return deleteList_OK;
}



/********************************************************************************************
*   10- This function reverses the whole list.
*   The idea is to change the link parts of each node to point to the previous node not the next node.
*   Also, change the head pointer to point to the last node instead of the first node.
*   This is done using 2 temp pointers and the head pointer.
*   One pointer to preserve the reference to the previous node.
*   One pointer to preserve the reference to the next node.
*   Head pointer to update the link part of the node itself.
*   We will update the link part of each node at a time which is pointed by the head pointer.
*********************************************************************************************/
EN_reverseList reverseList(ST_list_t* list)
{
    //  1- check if the list is empty
    if(list->head == NULL)
    {
        return reverseList_EMPTY_LIST;
    }

    //  2- before reversing, update the tail node to point to the node which will be the last node after reversing
    //  The last node after reversing is the head node before reversing
    list->tail = list->head;

    //  2- define the next and previous pointers
    ST_listNode_t* previous = NULL;
    ST_listNode_t* next = NULL;

    //  3- repeat the steps till head reaches to null
    while(list->head != NULL)
    {
        //  a- assign the address of the next node to the (next) pointer
        next = list->head->link;
        // b- update the link part of the node by the (previous) pointer
        list->head->link = previous;
        // c- update the previous to point to what head points to
        previous = list->head;
        // d- move head pointer to the next node
        list->head = next;
    }

    //  4- after finishing looping, head will be NULL and (previous) points to the last node
    //  So, you have to make the last node to be the head node to complete the reversing  
    list->head = previous;

    return reverseList_OK;
}


/********************************************************************************************
*   11- This function prints the whole list starting from the head node till the tail node
*   This function loops on all the nodes in the list. So, Time complexity is O(n)
*********************************************************************************************/
EN_printList_t printList(ST_list_t* list)
{
    // 1- check if the list is empty
    if(list->head == NULL)
    {   
        // 2- return that the list is empty
        return printList_LIST_IS_EMPTY;
    }

    // 3- create a temp pointer to point to the head node
    ST_listNode_t* tempPtr = list->head;

    // 6- check if the temp pointer reaches to the end of the list (NULL)
    while(tempPtr != NULL)
    {
        // 4- print the node data
        printf("%d\n", tempPtr->data);

        // 5- change the temp pointer to point at the next node
        tempPtr = tempPtr->link;
    }

    return printList_OK;
}



/********************************************************************************************
*   12- This function get the data part of the desired node
*   This function loops till reaching the desired node. So, Time complexity is O(n)
*********************************************************************************************/
EN_getNodeData_t getNodeData(ST_list_t* list, int nodeNumber, int* nodeData)
{

    if(nodeNumber > (list->listSize))
    {
        return getNodeData_NODE_NOT_AVAILABLE;
    }

    if((list->head) == NULL)
    {
        return getNodeData_LIST_IS_EMPTY;
    }

    ST_listNode_t* tempPtr = list->head;

    for(int index = 1; index < nodeNumber; index++)
    {
        tempPtr = tempPtr ->link;
    }

    *nodeData = tempPtr->data;

    return getNodeData_OK;
}



/********************************************************************************************
*   13- This function checks wether the node is tail or not
*   This function just checks the passed node. So, Time complexity is O(1)
*********************************************************************************************/
EN_isTail_t isTail(ST_listNode_t* node)
{
    if (node ->link == NULL)
    {
        return isTail_TAIL;
    }
    else
    {
        return isTail_NOT_TAIL;
    }
}



/********************************************************************************************
*   14- This function checks wether the list is empty
*   This function just checks on the head pointer of the list. So, Time complexity is O(1)
*********************************************************************************************/
EN_isEmpty_t isEmpty(ST_list_t* list)
{
    if(list->head == NULL)
    {
        return isEmpty_EMPTY;
    }
    else
    {
        return isEmpty_NOT_EMPTY;
    }
}