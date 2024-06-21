#include "Bubble_Sort.h"

void Bubble_Sort (int* arr, int size)
{
    // loop to control number of passes
    // ex) 10 members array
    // for first pass, the largest value is guranteed to be in arr[9]
    // for the 9th pass, the least largest value is guranteed to be in arr[1]
    // this leaves the smalles value at arr[0]
    // So, only 9 passes are required
    for (size_t pass = 1; pass != size; pass++)
    {
        // loop to control number of comparisons per pass
        // ex) 10 memebrs array
        // although we have 10 memebrs, we need only 9 comparisons
        // as we don't need to compare the last elements with any another element 
        for (size_t arrIndex = 0; arrIndex != (size - 1); arrIndex++)
        {
            if ( arr[arrIndex] > arr[arrIndex + 1] )
            {
                int temp = arr[arrIndex];
                arr[arrIndex] = arr[arrIndex + 1];
                arr[arrIndex + 1] = temp;
            }
        }
    }
}