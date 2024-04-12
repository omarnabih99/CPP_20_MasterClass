#include "Eliminating_Duplicates.h"


void unique_numbers(int* numbers, unsigned int collection_size)
{
    // declare an array to store the unique numbers with size of 20 elements as stated in the problem description
    std::array <int,uniqueSize> uniqueArray {0};

    // define a counter to count the unique array elements
    int uniqueCounter {};

    // define a flag to determine whether the element exists in the unique array
    bool duplicateFlag {false};

    for (int i {}; i < collection_size; i++)
    {
        // we must reset the duplicate flag each iteration to reset the condition
        duplicateFlag = false;

        for (int j {}; j < uniqueSize; j++)
        {
            if (numbers[i] == uniqueArray[j])
            {
                duplicateFlag = true;
                break;
            }
        }

        if (false == duplicateFlag)
        {
            uniqueArray[uniqueCounter] = numbers[i];
            uniqueCounter++;
        }
    }
    

    std::cout << "The collection contains " << uniqueCounter << " unique numbers, they are : ";
    for(int i {}; i < uniqueCounter; i++)
    {
        std::cout << uniqueArray[i] << " ";
    }

}


