#include <iostream>

int main()
{
/***************************************************************************************************************************************************
*   1- Pointer declaration
***************************************************************************************************************************************************/
    //  Will be initialized to nullptr implicitly
    int* p_number {}; // can only store an address of a variable of type int

    //  Will be initialized to nullptr implicitly
    double* p_fractional_number {}; // can only store an address of a variable of type double

    std::cout << "non initialize int pointer value: " << p_number << "\n";
    std::cout << "non initialize double pointer value: " << p_fractional_number << "\n";


/***************************************************************************************************************************************************
*   2- Pointer definition
*   we can initialize the pointers with any address.
*   Here, we initialized it by (nullptr).
*   In C++, nullptr is a keyword introduced in the C++11 standard to represent a null pointer.
*   It's used to indicate that a pointer doesn't point to any memory location.
*   Prior to C++11, programmers typically used the integer constant NULL to represent a null pointer.
*   nullptr offers several adv. over NULL: 
    1-  Type Safety: Unlike NULL, which is usually defined as 0 or ((void*)0),
        nullptr is of type nullptr_t, which is implicitly convertible to any pointer type.
        This makes nullptr type-safe and prevents certain types of bugs.
    2-  Clarity: nullptr clearly indicates that you're dealing with a null pointer,
        enhancing code readability and reducing ambiguity compared to integer constants like 0.
    3-  Avoids Ambiguity: Using nullptr avoids potential ambiguities that might arise from overloading functions
        or operators that take integer types, where 0 might be interpreted as an integer value
        rather than a null pointer.
    4-  Implicit Conversion: When nullptr is assigned to a pointer of any type, it's implicitly converted to that pointer type.
***************************************************************************************************************************************************/
    int* p_number_initialized {nullptr};

    double* p_fractional_number_initialized {nullptr};

    std::cout << "nullptr initialized int pointer value: " << p_number_initialized << "\n";
    std::cout << "nullptr initialize double pointer value: " << p_fractional_number_initialized << "\n";


/***************************************************************************************************************************************************
*   3- Pointer Size
*   Since pointers store memory addresses, their size depends on the machine archeticture for which the source code is compiled.
*   This means that the pointer's size doesn't depend on it's data type.
*   Also, all the pointer will have the same size regardless their data type.
***************************************************************************************************************************************************/
    int* p_number_size {nullptr};
    char* p_character_size {nullptr};
    double* p_fractional_number_size {nullptr};

    std::cout << "Size of int pointer: " << sizeof(p_number_size) << "bytes"<< "\n";
    std::cout << "Size of char pointer: " << sizeof(p_character_size) << "bytes"<< "\n";
    std::cout << "Size of double pointer: " << sizeof(p_fractional_number_size) << "bytes" << "\n";


/***************************************************************************************************************************************************
*   4- Initializing pointers with data
*   We use the address operator (&) to assign the pointer an adress of a variable
***************************************************************************************************************************************************/
    int int_var{43};
    int* p_int {&int_var};

    std::cout << "The int variable: "
              << int_var
              << " is stored at: "
              << p_int
              << "\n";


/***************************************************************************************************************************************************
*   5- Modifying the value of a pointer
***************************************************************************************************************************************************/
    int int_var1 {65};
    p_int = &int_var1;
    std::cout << "The int variable: "
              << int_var1
              << " is stored at: "
              << p_int
              << "\n";


/***************************************************************************************************************************************************
*   6- Trying to assign an adress of variable to a different type pointer
***************************************************************************************************************************************************/
    int* pointerToInteger {nullptr};
    double doubleVariable {33};

    // Compiler error -> cannot convert ‘double*’ to ‘int*’
    //pointerToInteger = &doubleVariable;


/***************************************************************************************************************************************************
*   7-  Dereferencing a pointer
***************************************************************************************************************************************************/
    int int_var2 {2709};
    pointerToInteger = &int_var2;

    std::cout << "Value at address: " << pointerToInteger << " is: " << *pointerToInteger << "\n"; 


/***************************************************************************************************************************************************
*   8- Exercises
***************************************************************************************************************************************************/
//  ex1) Guess the output before running the code
    unsigned long int a {5};
    unsigned long int *b {&a};
    unsigned long int c {*b};

    a = 7;

    //this will print (7 5)
    // *b will be updated to 7 as it has direct access on a
    // c will preserve it's assigned value which is 5
    std::cout << *b << " " << c << "\n";


/***************************************************************************************************************************************************
*   9- Pointer to Char
***************************************************************************************************************************************************/
    char* p_char_var {nullptr};
    char char_var {'A'};

    p_char_var = &char_var;

    std::cout << "The character stored in: " << static_cast <const void*> (p_char_var) << " is: " << *p_char_var << "\n";


/***************************************************************************************************************************************************
*   10- Initialize Pointer to Char with string literal
*   Another way of accessing a contigous chunk of memory, instead of with an array, is with a pointer.
*   Since we are talking about strings, which are made up of characters, we will be using a pointer to character.
*   When we do something like that, the string here will be expanded to a character array.
*   The first character in this string will be pointed to by the pointer itself.
*   This string literal will be stored in a shared Read Only section in the memory. So, you can not modify it.
*   Unlike the array name, the pointer variable itself is a non constant pointer. So, we are able to change it.
*   we can deduce that a pointer to char is a normal pointer to constant data.
***************************************************************************************************************************************************/
    char *str {"c++ programming"};
    std::cout << "Base address is: " << (const void*)(str)
              << " String is: " << str << "\n";

    // change the char pointer itself to point to another string
    str = "Omar Nabih";
    std::cout << "Base address is: " << (const void*)(str)
              << " String is: " << str << "\n";


    // change the first character in the string using the char pointer
    // the program will be compiled but will crash during run time
    //*str = 'K';
    //std::cout << "Base address is: " << (const void*)(str)
    //          << " String is: " << str << "\n";


    // since the literal string is constant data. So, the best practice is to define the pointer to point to const char
    const char* str1 {"Pointer to constant literal string"};
        std::cout << "Base address is: " << (const void*)(str1)
                  << " String is: " << str1 << "\n";


    // defining the char pointer to point to const char helps us to detect the error of modifying constant literal string early
    // without const, the program will be compiled but crashes in runtime
    // with const, there will be a compiler error -> assignment of read-only location ‘* str1’
    // *str1 = 'K';

    // This will print the first character of the literal string
    std::cout << "The first character in the string is: " << *str1 << "\n";

    // This will print the string characters
    std::cout << "print the base address of the string: " << str1 << "\n";

    // This will print the address where the pointer itself is stored
    std::cout << "print the base address of the string: " << &str1 << "\n";

    // This will print the base address of the literal string
    std::cout << "print the base address of the string: " << (const void*)str1 << "\n";
    



    





}


