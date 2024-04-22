# Fortune Teller V3

This is the enhanced version of [01_Arrays/Exercise/04_Fortune_Teller_V1](https://github.com/omarnabih99/NTI-CPP/tree/main/01_Arrays/Exercises/04_Fortune_Teller_V1).

- In this version, we used array of pointers to character.

- A disadvantage of creating strings using the character array syntax is that you must say most of time how many character the array may hold especially when using array of strings. 

- The specified string size will be allocated during compile time. So, if we didn't use all the specified size, there will be unused allocated memory.

- To avoid this headache of memory loss and limiting the number of characters, we will use array of pointer to character.

- We can store any number of characters and the compiler will deduce them automatically.