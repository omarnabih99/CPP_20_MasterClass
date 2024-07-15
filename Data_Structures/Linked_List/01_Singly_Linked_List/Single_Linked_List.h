#include <stdio.h>
#include <stdlib.h>

#define EMPTY_LIST (0)

#define INSERT_TO_HEAD (1)
#define INSERT_TO_TAIL ((list->listSize) + 1)

#define DELETE_FROM_HEAD (1)
#define DELETE_FROM_TAIL ((list->listSize))




/********************************************************************************************
*   1- Struct to represent the single linked list node
*
*   It conists of data part which stores the actual data.
*
*   And it contains the link part which links this node with the next nodes.
*   
*   Multiple data is allowed but it can only have one link
*
*   It is a self referential structure.
*********************************************************************************************/
typedef struct node
{
    int data;           // data part
    struct node* link;    // link part
}ST_listNode_t;


/********************************************************************************************
*   2- Struct to represent the single linked list 
*********************************************************************************************/
typedef struct list
{
    ST_listNode_t* head;
    ST_listNode_t* tail;
    int listSize;
}ST_list_t;


/********************************************************************************************
  Return types
*********************************************************************************************/
typedef enum EN_insertToListHead_t
{
    insertToListHead_ALLOCATION_FAILED,
    insertToListHead_OK
}EN_insertToListHead_t;

typedef enum EN_insertToListTail_t
{
    insertToListTail_ALLOCATION_FAILED,
    insertToListTail_EMPTY_LIST,
    insertToListTail_OK
}EN_insertToListTail_t;

typedef enum EN_optimalInsertToListTail_t
{
    optimalInsertToListTail_ALLOCATION_FAILED,
    optimalInsertToListTail_EMPTY_LIST,
    optimalInsertToListTail_OK
}EN_optimalInsertToListTail_t;

typedef enum EN_insertToList_t
{
    insertToList_ALLOCATION_FAILED,
    insertToList_WRONG_POSITION,
    insertToList_OK
}EN_insertToList_t;

typedef enum EN_deleteFromListHead_t
{
    deleteFromListHead_LIST_IS_EMPTY,
    deleteFromListHead_OK
}EN_deleteFromListHead_t;

typedef enum EN_deleteFromListTail_t
{
    deleteFromListTail_LIST_IS_EMPTY,
    deleteFromListTail_OK
}EN_deleteFromListTail_t;

typedef enum EN_deleteFromList_t
{
    deleteFromList_LIST_IS_EMPTY,
    deleteFromList_WRONGPOSITION,
    deleteFromList_OK
}EN_deleteFromList_t;

typedef enum EN_reverseList
{
    reverseList_EMPTY_LIST,
    reverseList_OK
}EN_reverseList;

typedef enum EN_printList_t
{
    printList_LIST_IS_EMPTY,
    printList_OK
}EN_printList_t;

typedef enum EN_getNodeData_t
{
    getNodeData_NODE_NOT_AVAILABLE,
    getNodeData_LIST_IS_EMPTY,
    getNodeData_OK
}EN_getNodeData_t;

typedef enum EN_isTail_t
{
    isTail_NOT_TAIL,
    isTail_TAIL
}EN_isTail_t;

typedef enum EN_isEmpty_t
{
    isEmpty_NOT_EMPTY,
    isEmpty_EMPTY
}EN_isEmpty_t;

typedef enum EN_deleteList_t
{
    deleteList_EMPTY_LIST,
    deleteList_OK
}EN_deleteList_t;


/********************************************************************************************
*   1- This function initialize the list parameters
*   Time Complexity is O(1)
*   Head, Tail, and List Size are initialized as follows
*********************************************************************************************/
void createEmptyList(ST_list_t* list);


/********************************************************************************************
*   2- This function inserts a new node to the head of the list.
*   Time complexity is O(1) as it doesn't contain any looping.
*   So, number of operations doesn't depend on the data size.
*********************************************************************************************/
EN_insertToListHead_t insertToListHead(ST_list_t* list, int data);


/********************************************************************************************
*   3- This function inserts a new node to the tail of the list.
*   This function has a time complexity of O(n) due to the while loop used to traverse the whole list till reaching the tail using head pointer.
*   This function can not be used with empty list. There must be head node initially.
*********************************************************************************************/
EN_insertToListTail_t insertToListTail(ST_list_t* list, int data);


/********************************************************************************************
*   4- This is the optimal version of insertToListTail function.
*   This function has a time complexity of O(1) as it doesn't traverse the list.
*   It uses the tail pointer directly.
*   This function can not be used with empty list. There must be head node initially.
*********************************************************************************************/
EN_optimalInsertToListTail_t optimalInsertToTail(ST_list_t* list, int data);


/********************************************************************************************
*   5- This function inserts a new node at any position of the list.
*   The list is indexed starting from 1.
*   This function is generic, it can insert at head, at tail, or any position between them.
*   Time Complexity is O(n) as it loops till reaching to the node whose link is the address of the position where we want to insert into
*********************************************************************************************/
EN_insertToList_t insertToList(ST_list_t* list, int position, int data);


/********************************************************************************************
*   6- This functions deletes a node from head and assign the just before node to be the new head
*   This functions returns list is empty error if we attempted to delete node from empty list
*   Time complexity is O(1)
*********************************************************************************************/
EN_deleteFromListHead_t deleteFromListHead(ST_list_t* list);


/********************************************************************************************
*   7- This function deletes the tail node and assign the just before node to be the new tail.
*   This function loops till finding the node just before the tail node to be the new tail. So, Time complexity will be O(n).
*********************************************************************************************/
EN_deleteFromListTail_t deleteFromListTail(ST_list_t* list);


/********************************************************************************************
*   8- This function deletes a node from any position
*   This function loops till finding the desired node. So, Time Complexity is O(n)
*********************************************************************************************/
EN_deleteFromList_t deleteFromList(ST_list_t* list, int position);


/********************************************************************************************
*   9- This function deletes the whole list.
*   We can loop on the list and use any implemented delete function.
*   But we will implement this function from scratch.
*   Time Complexity is O(n) as it loops the whole list to delete the all nodes.
*********************************************************************************************/
EN_deleteList_t deleteList(ST_list_t* list);


/********************************************************************************************
*   10- This function reverses the whole list.
*   The idea is to change the link parts of each node to point to the previous node not the next node.
*   Also, change the head pointer to point to the last node instead of the first node.
*   This is done using 2 temp pointers and the head pointer.
*   We will update the link part of each node at a time which is pointed by the head pointer.
*********************************************************************************************/
EN_reverseList reverseList(ST_list_t* list);


/********************************************************************************************
*   11- This function prints the whole list starting from the head node till the tail node
*   This function loops on all the nodes in the list. So, Time complexity is O(n)
*********************************************************************************************/
EN_printList_t printList(ST_list_t* list);


/********************************************************************************************
*   12- This function get the data part of the desired node
*   This function loops till reaching the desired node. So, Time complexity is O(n)
*********************************************************************************************/
EN_getNodeData_t getNodeData(ST_list_t* list, int nodeNumber, int* nodeData);


/********************************************************************************************
*   13- This function checks wether the node is tail or not
*   This function just checks the passed node. So, Time complexity is O(1)
*********************************************************************************************/
EN_isTail_t isTail(ST_listNode_t* node);


/********************************************************************************************
*   14- This function checks wether the list is empty
*   This function just checks on the head pointer of the list. So, Time complexity is O(1)
*********************************************************************************************/
EN_isEmpty_t isEmpty(ST_list_t* list);