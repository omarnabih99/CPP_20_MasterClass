#include "Linear_Search.h"

int Linear_Search(int* arr, int arrSize, int desiredElement)
{
    for(int i {}; i < arrSize; ++i)
    {
        if (desiredElement == arr[i])
        {
            return i;
        }
    }

    return -1;
}
