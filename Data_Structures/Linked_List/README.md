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



