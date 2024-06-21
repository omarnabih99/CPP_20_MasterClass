#include "Selection_Sort.h"

void swap (int* arr, size_t first, size_t second)
{
    int tmp = arr[first];
    arr[first] = arr[second];
    arr[second] = tmp;
}

void Selection_Sort(int* arr, int size)
{   
    // loop on (size - 1) elements
    for (size_t i {0}; i != (size - 1); i++)
    {
        size_t min = i; //first index of the remaining array

        // loop to find the smallest element
        for (size_t j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        swap(arr, i, min);

        std::cout << "After Pass ("<< i + 1 <<"): "; 
        for(size_t i {0}; i != size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
}
