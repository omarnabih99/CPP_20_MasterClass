# Data Structures

- It is data oragnization, management, and storage format that enables efficient access and modifications of data.

- It allows the processing of a large amount of data in a relatively short time.

- The main purpose of using data structures is to reduce time and space complexities.

- An efficient data structure makes use of minimum memory space and takes minimal possible time to modify data.

## Why data structures are important ?

- It is the building block of more complex problems.

- It enhances software design and algorithms' implementation.

- Choosing an inappropriate data structure may result in slow runtimes or inefficient code.

- Data Structures are used in:

    1. Storing and sorting data.

    2. Managing resources and services.

    3. Data exchange.

## Types of data structures

### Linear Data Structures

- A data structure is linear when all elements are arranged in a linear (sequential) order.

- Example: Arrays, Linked Lists, Stacks, and Queues.

### Non Linear Data Structures

- A data structure is non linear when all elements are not arranged in a linear (sequential) order. There is no linear arrangment of elements.

- Example: Trees, and Graphs.

### Static Data Strucures

- In these type of data structures, the memory is allocated at compile time. Therefore, the maximum size is constant.

- Advantage: Fast access.

- Disadvantage: Slower insertion and deletion.

- Example: Arrays.

### Dynamic Data Structures

- In these type of data structures, the memory is allocated at run time. Therefore, the maximum size is flexible.

- Advantage: Faster Insertion and deletion.

- Disadvantage: Slower access.

- Example: Linked Lists.

1. Arrays -> Stores data of the same type, and can be multidimensional.

2. Stack -> Last In First Out (LIFO).

3. Heap.

4. Queue -> First In First Out (FIFO).

5. Tree.

6. Table -> most used in encryption.

7. Graph.

8. Linked Lists -> can be used to create stacks, queues, ..., etc.

## Static and Dynamic data structures

1. Static data structures:

    - Have fixed size in memory.

    - Data can be modified but the allocated memory can not be changed during run-time.

    - Arrays are static data structures and any data structure is implemented using arrays is static too.

2. Dynamic data structures:

    - Have dynamic size in memory.

    - Both data and allocated memory can be modified during run-time.

    - Linked lists are dynamic data structures and any data structure is implemented using linked lists is dynamic too.

## Space and time complexities

1. Space Complexity:

    - It means how much space of memory is consumed during the run-time.

    - Space complexity is increased as long as you define more variables that allocate more memory.

2. Time complexity

    - It means how much time does it take to finish the needed operation.

    - Time complexity is increased as long as you make more iterations/steps to reach your goal.

## Space and time complexities for some data structures

![Complexities](https://github.com/omarnabih99/CPP_20_MasterClass/blob/main/Data_Structures/Screenshot%20from%202024-06-23%2021-24-08.png)


## Some data structures applications

1. Arrays:

    - 2D arrays commonly known as, matrices, are used in image processing.

    - It is also used in speech processing, in which each speech signal is an arrya.

    - Any viewing screen is also a multidimensional array of pixels.

2. Linked Lists:

    - Used for symbol table management in designing a compiler.

    - Used in switching between applications (Alt + Tab) in the operating system. (implemented using Circular Linked List)

    - It can be used to implement Stacks, Queues, Graphs, and Trees.

3. Stacks:

    - Undo/Redo button/operation in word processors.

    - Syntaxes in languages are parsed using stacks.

    - Message logs and all messages you get are arranged in a stack.

4. Queues:

    - Operating System uses queues for job scheduling.

    - To handle congestion in the networking, queue can be used.

    - Sending an email, it will be queued.