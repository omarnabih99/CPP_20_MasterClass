#include "Insertion_Sort.h"

void Insertion_Sort(int* arr, int size)
{
    for (size_t index {1}; index != size; index++)
    {
        int insert = arr[index];
        size_t moveItem = index;

        while ( (moveItem > 0) && (arr[moveItem - 1] > insert) )
        {
            arr[moveItem] = arr[moveItem - 1];
            --moveItem;
        }
        arr[moveItem] = insert;

        std::cout << "After pass ("<< index <<"): ";
        for (size_t i {0}; i != size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
}