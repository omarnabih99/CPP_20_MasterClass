# Linked List

## Void Pointers

- They are pointer which has no associated data type with it.

- It can point to any data of any type and can be typecasted to any type.

- Example:

    ```C
    int main()
    {
        int number = 10;
        void* ptr = &n;

        // The void pointer is typecasted to pointer to int in order to be used in printing int type data
        // output will be -> 10
        printf("%d", *(int*)ptr);
    }
    ```
- We cannot dereference a void pointer directly. We must typecast it firstly.

- Use of void pointers:
    
    - malloc() and calloc() functions return a void pointer. Due to this reason they can allocate memory for any type of data.

## Null Pointers

- A `NULL` pointer is a pointer that doesn't point to any memory location.

- It represents an invalid memory location.

- When a `NULL` value is assigned to a pointer, then the pointer is considered as `NULL` pointer.
    ```C
    int* ptr = NULL;
    ```

### Uses of NULL pointers:

1. To initialize a pointer when that pointer isn't assigned any valid memory address yet.

2. Useful for handling errors when using malloc() function as it returns NULL when memory couldn't be allocated.

```C
int* ptr;
ptr = (int*)malloc(2 * sizeof(int));
if(ptr == NULL)
{
    printf("%s", "Memory couldn't be allocated");
}
else
{
    printf("%s", "Memory is allocated");
}
```

### Facts about NULL pointer

1. The value of `NULL` is `0`. We can either use `NULL` or `0` but this `0` will be written in context of pointers and is not equivalent to the integer `0`. It is not good practice to initialize a pointer with `0`, instead initialize it with `NULL`.

```C
int* ptr = NULL;
// output will be -> 0
printf("%d", ptr);
```

2. Size of NULL pointer depends upon the platform and similar to the size of normal pointers.

```C
int* ptr;
// output will be -> 8 4 8
printf("%ld \n%ld \n%ld", sizeof(NULL), sizeof(int), sizeof(ptr));
```

### Best practices

1. It is a good practice to initialize a pointer as `NULL`.

2. It is a good practice to perform `NULL` check before dereferencing any pointer to avoid any surprises.

## Dangling Pointers

- A dangling pointer is a pointer which points to some `non-existing` memory locations,

```C
int* ptr = (int*)malloc(sizeof(int));

/*
some code
*/

// free() is used to deallocate the already allocated memory.
// but the pointer ptr is still pointing to the deallocated memory becoming dangling pointer.
free(ptr);

// The solution is to assign NULL to ptr after freeing the memory.
ptr = NULL;
```

-  Example:

```C
int* fun()
{
    int number = 10;
    return &number;
}

int main()
{
    int* ptr = NULL;

    ptr = fun();

    printf("%d", *ptr);
}
```

- The function fun() returns address to it's local variable `number`. This will give a warning: `retunrning address of a local variable` during compilation time.

- During runtime, `Segemntaion fault` will happen as the main function tries to dereference ptr while ptr is considered a `Dangling pointer`.

## Wild Pointers

- They are pointers that are not initialized.

- These pointers usually point to some arbiteray memory location and may cause a program to crash or misbehave.

```C
// unintialized pointer point to a random location in the memory (wild pointer)
int* ptr;

// dereferencing a wild pointer may result in a misbehave nut it doesn't produce neither compilation error nor warnings
*ptr = 10;
```

- How to avoid Wild Pointers:

    1. Initialize them with the address of a known variable.

    ```C
    int number = 10;
    
    // nomore a wild pointer
    int* ptr = &number;
    ```

    2. Explicitly allocate the memory and put the values in the allocated memory.

    ```C
    int* p = (int*)malloc(sizeof(int));
    *p = 10;
    free(p);
    p = NULL;
    ```

## Memory Allocation

### Static Memory allocation

- Memory allocated during compile time is called static memory.

- This allocated memory is fixed and cannot be increased or decreased during runtime.

- Global and Static variables are examples of static allocation

- The statically allocated memory remains permanently allocated and freed automatically upon end of the program.

- If you are defining an array:

    - A fixed memory size will be allocated for it during `compile time`.

    - This memory size is fixed and user cannot change it during `runtime`.

    - The values stored by the user in this array maybe less than the size allocated for the array resulting in `memory waste`.

    - The values can be also larger than the size allocated for the array then the program may crash or misbehave.

### Dynamic Memory Allocation

- It is the process of allocating memory at the time of execution `runtime`.

- The dynamic memory requested by a program is allocated by the system in `heap` section of the memory.

- Dynamic memory allocation is done using the standard C library functions
    
    1. `malloc()`.

    2. `calloc()`.

    3. `realloc()`.

    4. `free()`.

#### malloc() 

- It is a built-in function declared in <stdlib.h>.

- malloc is short for `memory allocation` and is used to dynamically allocate a single large block of contigous memory according to the size specified.

- Syntax:
 ```C
(void*) malloc(size_t size);
```

- On success, it return a void pointer pointing to the first byte of the allocated memory. Else, it returns NULL.

- `malloc` doesn't have an idea of what it is pointing to.

- It just allocates memory requested by the user without knowing the type of data to be stored inside the memory. So, it returns a void pointer which then can be typecasted to an appropriate type.

- Example: 
```C
int* ptr = (int*) malloc(4);
```
malloc allocates 4 bytes of memory in the heap and the address of the first byte is stored in the pointer `ptr`.

- The allocated memory locations initial values are `garbage`.

#### calloc()

- It is used to dynamically allocate multiple blocks of memory.

- It stands for contguous allocation.

- Syntax:
```C
void* calloc(size_t n, size_t size);
```

- Example:
```C
int* ptr = (int*) calloc(4, sizeof(int));
```

##### calloc() vs malloc()

- calloc() needs to arguments not just one.

- It allocates multiple blocks of memory each of the same size and sets all bytes to `zero` instead of `garbage` values.

#### realloc()

- It is used to change the size of a previously allocated memory block without losing the old data.

- Syntax:
```C
void* realloc(void* ptr, size_t newSize);
```

- Example:
```C
int* ptr = (int*) malloc(sizeof(int));
ptr = (int*) realloc(ptr, 2 * sizeof(int));
```

- This function moves the contents of the old block to a new block and the data of the old block is not lost.

- We may lose data when the new size is smaller than the old size.

- Newely allocated bytes using realloc() are not initialized.

#### free()

- It is used to release the dynamically allocated memory in heap.

- The memory allocated in heap will not be released automatically after using the memory.

- It is the programmer's responsibility to release the memory after use.

- It is best practice to assign NULL to the pointer after releasing the allocated memory to avoid dangling pointer.

- Syntax: 
```C
void free(ptr);
```

## Self-Referential Structures

- Self referential structures are those structures in which one or more pointers points to another structure of the same type.

```C
struct self
{
    int p;
    struct self *ptr;
};
```

- Example:

    ```C
    struct code
    {
        int i;
        char c;
        struct code *ptr;
    };

    int main()
    {
        // 1- take an instance of the struct code
        struct code var1;
        var1.i = 65;
        var1.c = 'A';
        // initialize the pointer to NULL till another instance is created
        var1.ptr = NULL;

        // 2- take another instance of 
        struct code var2;
        var2.i = 66;
        var2.c = 'B';
        var2.ptr = NULL;

        // set the address of the second struct in the ptr of first struct
        var1.ptr = &var2;

        // now we can access var2 members through var1
        // output will be -> 66 B
        printf("%d %c", var1.ptr->i, var1.ptr->c);
    }
    ```

## Linked Lists

- Linked-List is a linear data structure that connect data nodes together without need of `contigous` storing into memory.

- A real life example of linked-list is `Alt+Tab` in windows.

- Any linked-list is characterized by it's head and tail.

- Any linked-list is a group of nodes, each node contains data in addition to a pointer to the same type of the list.

### Types of Linked-List

- Types of Linked-lists are classified according to the pointer variable in the node

1. Singly Linked-List: The last node points to null to terminate the list.

    - Head -> Node1(data)(pointer) -> Node2(data)(pointer) -> NULL.

    - Navigation is forward only

2. Circular Linked-List: The last node points to the first node.

    - Head -> Node1(data)(pointer) -> Node2(data)(pointer) -> Node1.

    - Last element is linked to the first element

3. Doubly Linked-List: in doubly linked-lists, the construction of the node is different, where each node contains data in addition to two pointers, one pointer points to the next node and the other pointer points to the previous node. 

    - Head -> Node1 (pointer -> NULL)(data)(pointer) -> Node2 (pointer -> Node1)(data)(pointer) -> Node3 (pointer -> Node2)(data)(pointer) -> NULL.

    - Forward and backward navigation is available

4. Circular Doubly Linked-List: Same as Doubly linked-list but a pointer in the first node points to the last node and a pointer in the last node points to the first node.

    - Head -> Node1 (pointer -> Node 3)(data)(pointer) -> Node2 (pointer -> Node1)(data)(pointer) -> Node3 (pointer -> Node2)(data)(pointer) -> Node 3.

### Linked Lists Applications

- It is used to implement stacks and queues.

- It is used in notepad to perform undo or redo or deleting functions.

- We can think of it's use in a photo viewer for having a look at photos continously in a slide show.

- Used in switching between applications and programs (Alt+Tab) in the operating system.