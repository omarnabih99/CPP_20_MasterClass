#include "The_Collection_Is_Sorted.h"

bool is_collection_sorted(int* numbers, unsigned int collection_size)
{
    int sortedFlag {1};

    for (int i {}; i < collection_size; i++)
    {
        if (i == 0)
        {
            continue;
        }

        if (numbers[i] < numbers[i-1])
        {
            sortedFlag = 0;
            break;
        }
    }

    return sortedFlag;
}