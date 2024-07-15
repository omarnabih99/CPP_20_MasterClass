# Single Linked List

- It is a list that made up of nodes that consists of two parts:

    1. Data -> Contains the actual data

    2. Link -> Contains the address of the next node in the list.

## Arrays Vs. Single Linked List (in terms of representation)

- Example: We want to store a list of numbers 23, 54,  78, 90.

    1. Using arrays: assume that base address of array is 1000 and the size of int is 4 bytes.

        1000 -> 23

        1004 -> 54

        1008 -> 78

        1012 -> 90

        In an array, elements are stored in consecutive memory locations. So, we can say that the `array` is the `sequential` representation of a list.

    2. Using Single Linked List: Forward navigation only

        Head -> Node1(23)(5000) -> Node2(54)(4750) -> Node3(78)(3978) -> Node4(90)(NULL).

        `Head` 1000 -> Node 1

        5000 -> Node 2

        4750 -> Node 3

        3978 -> Node 4

        These nodes are not stored in consecutive memory locations. These nodes are stored in random memory locations but linked together by the Link part in each node. So, we can say that the `Linked-List` is the `linked` representation of a list.

        Nodes are scattered in different memory locations but still linked by the link part of each node.

        `Head` pointer is important as it points to the first node in the list.

## Operations on Linked-List

1. Inserting may be into head, tail, or any position.

2. Deleting may be from head, tail, or any position.

3. A linear linked-list node is represented by a structure with at least two memebers: data, and a pointer to the next node.

4. A linked-list is represented by a structure with two members: head, pointer and size. It is empty when it's head points to NULL.

5. Linked-Lists take place into `heap`.

### Insert to Head Operation

1. Allocate list node into heap.

2. Store data into node.

3. Make the node pointer points to what the head is pointing to.

4. Make the head pointer points to the created node.

### Delete form Head Operation

1. Check if the list is empty.

2. If empty, print the list is empty.

3. If not empty, store the address of the head node to a temp pointer.

4. Make the head pointer points to what the head node next pointer points to.

5. Free the allocated memory pointed by the temp pointer.

### Print List Operation

1. Check if the list is empty.

2. If empty, print the list is empty.

3. If not empty, create a temp pointer that points at the head node.

4. print the node data.

5. change the temp pointer to point at the next node.

6. If it is the last node, print node and stop.




