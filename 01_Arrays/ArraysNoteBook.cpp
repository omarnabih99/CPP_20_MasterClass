/*
* A file to explain Arrays in C++
*/

/*
* 1- Dependency
*/
#include <iostream>
#include <array>

int main()
{
/*
*   1- Declare an Array
*   -> <array members data type, number of members> array name;
*   -> due to c++ core guidelines, we use STL declaration instead of normal C declaration.
*   -> Once an array is declared, it will store garbage data till assigning values to it.
*   -> Be aware of the array boundaries.
*   -> Arrays store data of the same type, if any member has a different type of that declared to the compiler,
*      it will get a compiler error.
*/
    std::array <int, 5> arr1;

/*
*   2- Initialize an array with int literals
*   -> std::array <array members data type, number of members> array name {v1, v2, v3, ..., vn};
*   -> std::array array_name {v1, v2, v3, ..., vn}; -> here, the compiler will determine the size and type automatically
*   -> In case we initialized number of elements less than the number of array members, the rest members
*      will be initialized by zeroes automatically
*   -> We cannot modify a member of a const array
*/
    std::array <int, 5> arr2 {1, 2, 3, 4, 5};

    // Here, the compiler will determine the array size automatically
    const int cArray[] {2, 4, 6, 7, 8, 10};
    /* Because we used C array definition, we can't use the STL functions
     * Example:
     * std::cout << "Size of int array is: " << cArray.size() << "\n"; */

    // Using for range based loop as we avoid the headache of counting the array members
    for (auto value : cArray)
    {
        std::cout << "C Array: " << value << "\n";
    }

    // std::array <const int, 5> constArray {1, 2, 3, 4, 5};
    std::array const constArray {1, 2, 3, 4, 5};
    /*
     * Try to modify a constant array member
     * constArray[0] = 10;
     * cArray[0] = 10;
     * !!!Error!!!
    */
    

/*
*   3- assign an array to another array
*/
    arr1 = arr2;

/*
*   4- printing a specific element of the array
*/
    std::cout << "arr1[0]: " << arr1[0] << "\n";
    std::cout << "arr2[0]: " << arr2[0] << "\n";
/*
*   5- front and back functions
*/
    std::cout << "arr1 front: " << arr1.front() << "\n";
    std::cout << "arr2 front:" << arr2.front() << "\n";

    std::cout << "arr1 back: " << arr1.back() << "\n";
    std::cout << "arr1 back: " << arr2.back() << "\n";

/*
*   6- Capacity functions
*/

/*
*   a- empty function
*   -> this function returns true if the array is empty and false if the array is not empty
*/
    std::array <int, 0> emptyArr; // decaring an empty array
    std::array <int, 5> notEmptyArr {0}; // defining non empty array with zero as initial value for it's 5 members
    std::array <int, 5> notEmptyArr1; // declaring a non empty array without initialization
    if(emptyArr.empty() == true)
    {
        std::cout << "The array is empty" << "\n";
    }

    if(notEmptyArr.empty() == false)
    {
        std::cout << "The array is not empty" << "\n";
    }

    if(notEmptyArr1.empty() == false)
    {
        std::cout << "The array is not empty" << "\n";
    }
 
/*
*   b- size function 
*   -> this function return the number of elements in the array
*/
    std::array <int, 5> sizeArr {0};
    std::array <double, 5> sizeArr1 {1, 2, 3, 4, 5};
    std::cout << "Size of int array is: " << sizeArr.size() << "\n";
    std::cout << "Size of double array is: " << sizeArr1.size() << "\n";
    // std::size() can also be used with std::array thanks to function overloading
    std::cout << "Size of double array using std::size() is: " << std::size(sizeArr1) << "\n";

    // Using std::size() with C arrays not std::arrays (introduced in C++17). We can use it as an upper limit in looping on an array
    int cSizeArr[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "The C Array Size is: " << std::size(cSizeArr) << "\n";
    /*
     * This cannot be done as cSizeArr is not std::array 
     * std::cout << "The C Array Size is: " << cSizeArr.size() << "\n";
    */

/*
*   c- maxsize function
*   -> in case of arrays, each array has a fixed size container. So, this function will also return the number of array elements
*/
    std::array <int, 5> MaxSizeArr {0};
    std::array <double, 5> MaxSizeArr1 {1, 2, 3, 4, 5};
    std::cout << "Max Size of int array is: " << MaxSizeArr.size() << "\n";
    std::cout << "Max Size of double array is: " << MaxSizeArr1.size() << "\n"; 

/*
*   7- Operations
*/

/*
*   a- fill operation
*   -> this operation takes a value to be filled in the array as an argument
*/
    std::array <int,5> fillArray{1, 2, 3, 4, 5};
    std::cout << "Array before filling: " << fillArray.front() << fillArray.back() << "\n";
    fillArray.fill(5);
    std::cout << "Array after filling: " << fillArray.front() << fillArray.back() << "\n";

/*
*   b- swap operation
*   -> this operation exchanges the contents of the container with those of the other container
*/
    std::array <int, 5> swapArr1 {1 ,1, 1, 1, 1};
    std::cout << "Array1 is:" << swapArr1.front() << swapArr1.back() << "\n";

    std::array <int, 5> swapArr2 {2, 2, 2, 2, 2};
    std::cout << "Array2 is:" << swapArr2.front() << swapArr2.back() << "\n";

    swapArr1.swap(swapArr2);
    std::cout << "Array1 after swapping is:" << swapArr1.front() << swapArr1.back() << "\n";
    std::cout << "Array2 after swapping is:" << swapArr2.front() << swapArr2.back() << "\n";

/*
*   8- printing the whole array using begin and end
*   -> begin returns iterator to the first element
*   -> end returns iterator to the element following the last element
*/
    std::array <int, 5> beginEndArr{1, 2, 3, 4, 5};
    std::cout << "print the array using begin and end: \n";
    for(auto iterator = beginEndArr.begin(); iterator != beginEndArr.end(); iterator++)
    {
        std::cout << *iterator << "\n";
    }

/*
*   9- printing the whole array using the array index
*/
    std::array indexArr1{6.2, 7.5, -8.1, 9.3, 10.4, 11.6}; // compiler knows automatically the number and type of element through the initialization list
    std::cout << "print the array using index: \n";
    for (int i = 0; i < indexArr1.size(); i++) // this is equivalent to using begin and end
    {
        std::cout << "indexArr1[" << i <<"]: " << indexArr1[i] << "\n";
    }
    std::cout << "Size is: " << indexArr1.size() << "\n"; // size = 6 elements

/*
*   10- printing the whole array using range-based for loop
*/
    std::array <int, 5> rangeBasedArr {1, 2, 3, 4, 5};
    std::cout << "print the array using range based for loop \n";
    for(auto& element : rangeBasedArr)
    {
        std::cout << element << "\n";
    }

/*
*   Note: we can't directly print an array of integers without looping
*/
    int directArr[5] {1, 2, 3, 4, 5};
    std::array <int,5> directArr2 {1, 2, 3, 4, 5};
    // Printing c-arrays directly will not prompt an error. This will print the address of the first element in the array in hexa format as the name of an c-array is an address of it's first element
    std::cout << "Printing c-array of integers directly: " << directArr << "\n";
    // Printing std::array arrays will prompt an error (uncomment tbe following line to see) as the name of std::array is not an address of it's first element
    // std::cout << "Printing array of integers directly: " << directArr2 << "\n";
    // but we can make an equivalent expression to this in c-arrays to print the address of the first element
    std::cout << "Printing std::array array of integers directly: " << directArr2.data() << "\n";


/*
*   11- initializing array elements with user input
*/
    std::array <int,5> inputArr {0};
    std::cout << "please input the array: \n";
    for(auto& element : inputArr)
    {
        std::cin >> element;
    }

    std::cout << "the input array is: \n";
    for(auto& element : inputArr)
    {
        std::cout << element << "\n";
    }   

/*
*   12- Exercises
*/

    // Exercise (1): Assign values to an array which equals to 10 * the member index
    std::array <int, 10> ex1Arr;
    ex1Arr.fill(0);
    for (size_t index = 0; index < 10; ++index)
    {
        std::cout << "before multiplying->ex1Arr["<< index <<"]: " << ex1Arr[index] << "\n";
    } 

    for (size_t index = 0; index < 10; ++index)
    {
        ex1Arr[index] = index * 10;
    }

    for (size_t index = 0; index < 10; ++index)
    {
        std::cout << "after multiplying->ex1Arr["<< index <<"]: " << ex1Arr[index] << "\n";
    }

    // Exercise (2): Sum the array elements which are entered by the user
    std::array <int,5> sumArray;
    int sum {0};

    std::cout << "Please input the array to be summed: " << "\n";
    for(size_t index = 0; index < 5; ++index)
    {
        std::cin >> sumArray[index];
    }

    for(auto element : sumArray)
    {
        sum += element;
    }

    std::cout << "Sum is: " << sum << "\n";

/*
*   13- Character Arrays
*/
    // 1- define a Character Array
    char message [5] {'H', 'e', 'l', 'l', 'o'};

    // 2- Print the Character Array
    // a- using for ranged loop
    std::cout << "Print the message using for range: ";
    for(auto c : message)
    {
        std::cout << c;
    }
    std::cout << "\n";

    // b- using for index loop
    std::cout << "Print the message using for index: ";
    for (int i {}; i < 5; i++)
    {
        std::cout << message[i];
    }
    std::cout << "\n";

    // c- Direct print out
    // we can print the message directly without looping if it is a proper C string -> terminated by a null character
    char message1 [] {'O', 'm', 'a', 'r', '\0'};
    std::cout << "Print the message directly using null character: " ;
    std::cout << message1 << "\n";
    // Trying to print the character array without terminating it will print garbage data
    char message2 [5] {'N', 'a', 'b', 'i', 'h'};
    std::cout << "Print the message directly without using null character: " ;
    std::cout << message2 << "\n";
    // This also will print garbage data
    char message3 [] {'N', 'a', 'b', 'i', 'h'};
    std::cout << "Print the message directly without using null character and without sepicyfing a size: " ;
    std::cout << message3 << "\n";   
    // we can specify a size greater than the number of the desired characters by 1 character to make a room for the null character which will be appended automatically by the compiler
    char message4 [6] {'H', 'e', 'l', 'l', 'o'};
    std::cout << "Print the message directly using automatically appended null character: " ;
    std::cout << message4 << "\n";

    // 3- Modify an array element
    std::cout << "Modify an Array Element..." << "\n";
    message [1] = 'a';
    std::cout << "The new message is: ";
    for(auto c : message)
    {
        std::cout << c;
    }
    std::cout << "\n";

/*
*   14- Literal C-strings
*/
    // 1- define a literal C-string
    char cString [] {"Hello"};
    char cString2 [] {"Hello, it is Omar Nabih"};

    // 2- Print a c-string
    // a- we can print a c-string directly as a null character is appended to it automatically by the compiler
    std::cout << "Printing c-string directly: " << cString << "\n";
    std::cout << "Printing c-string directly: " << cString2 << "\n";

    // b- we can print the c-string using for range loop
    // This loop will print the string till it meets a null character -> Hello
    std::cout << "Printing the c-string using for range loop: ";
    for (auto c : cString)
    {
        std::cout << c;
    }
    std::cout << "\n";
    // This loop will print the string till it meets a null character -> Hello, it is Omar Nabih
    std::cout << "Printing the c-string using for range loop: ";
    for (auto c : cString2)
    {
        std::cout << c;
    }
    std::cout << "\n";

    // 3- determine the size of a c-string
    // we will notice that the size will be greater than the string characters by one
    // this additional character is the automatically appended null character
    std::cout << "The size of (Hello) is: " << std::size(cString) << "\n";
    std::cout << "The size of (Hello, it is Omar Nabih) is: " << std::size(cString2) << "\n";
}