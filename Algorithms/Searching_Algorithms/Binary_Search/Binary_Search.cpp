#include "Binary_Search.h"

int Binary_Search(int* arr, int arrSize, int desiredElement)
{
    int start {0};
    int end {arrSize - 1};

    while(start <= end)
    {
        int mid {(start + end) / 2};

        if (arr[mid] == desiredElement)
        {
            return mid;
        }
        else if (arr[mid] > desiredElement)
        {
            end = mid - 1;
        }
        else if(arr[mid] < desiredElement)
        {
            start = mid + 1;
        }
    }

    return -1;
}