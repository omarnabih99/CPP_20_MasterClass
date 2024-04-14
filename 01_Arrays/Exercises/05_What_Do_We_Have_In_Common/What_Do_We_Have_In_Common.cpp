#include "What_Do_We_Have_In_Common.h"

void common_elements(int* array_1, int* array_2)
{
    // 1- define the given array size
    const int arrSize {10};

    // 2- define a flag which determines that a common element is found
    bool commonIsFound {false};

    // 3- define a counter to count the common elements and will also be used as an index to the common elements array
    unsigned int commonCounter {};

    // 4- define the common elements array with max size of 10 elements
    int commonArr[arrSize] {0};

    // 5- loop on both arrays comparing each element in array_1 with all elements in arr_2
    for (int i {}; i < arrSize; i++)
    {
        commonIsFound = false;

        for (int j {}; j < arrSize; j++)
        {
            if (array_1[i] == array_2[j])
            {
                commonIsFound = true;
                break;
            }
        }

        if (commonIsFound)
        {
            commonArr[commonCounter] = array_1[i];
            commonCounter++;
        }
    }

    if(commonCounter == 0)
    {
        std::cout << "There are " << commonCounter << " common elements";
    }
    else
    {
        std::cout << "There are " << commonCounter << " common elements they are : ";
        for (int i {}; i < commonCounter; i++)
        {
            std::cout << commonArr[i] << " ";
        }
    }

}