#include "Jump_Search.h"

int Jump_Search(int* arr, int arrSize, int desiredElement)
{
    int jump {(int)(sqrt(arrSize)) - 1};
    int index {};

    if (arr[0] > desiredElement)
    {
        return -1;
    }

    while (index < arrSize)
    {
        if(arr[index] == desiredElement)
        {
            return index;
        }
        else if(arr[index] < desiredElement)
        {
            index += jump;
        }
        else if (arr [index] > desiredElement)
        {
            for(int i {index}; i > (index - jump); --i)
            {
                if (arr[i] == desiredElement)
                {
                    return i;
                }
            }
        }
    }

    return -1;

}