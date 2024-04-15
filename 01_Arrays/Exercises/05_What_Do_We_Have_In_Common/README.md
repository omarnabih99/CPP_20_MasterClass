# What do we have in common?

Given two input arrays of int with a `size of 10` (each element shows up only once in the array), for example :

```cpp
int data1[] {1,2,4,5,9,3,6,7,44,55}; 
int data2[] {11,2,44,45,49,43,46,47,55,88};
```

Your job is to write code that identifies **common elements** in these two collections and prints a message like:

```sql
There are 3 common elements they are : 2 44 55
```

with a single space after the last common element. 

If there are **no common** elements between the arrays, for example our input arrays contain the data below:

```cpp
int data1[] {1,2000,4,5,9,3,6,7,4400,5500}; 
int data2[] {11,2,44,45,49,43,46,47,55,88};
```

your code will then print a message : 

```sql
There are 0 common elements
```

This time there's no space after elements in the message. 

**!!! Again, please remember that the input arrays will have a fixed size of 10 !!!**