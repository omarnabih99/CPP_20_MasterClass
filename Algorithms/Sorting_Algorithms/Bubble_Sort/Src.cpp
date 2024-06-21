#include "Bubble_Sort.h"

int main()
{
    std::array <int,10> bubbleSortArr {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (size_t index = 0; index != bubbleSortArr.size(); index++)
    {
        std::cout << "Array before sorting: " << bubbleSortArr[index] << "\n";
    }

    Bubble_Sort(bubbleSortArr.data(), bubbleSortArr.size());
    for (size_t index = 0; index != bubbleSortArr.size(); index++)
    {
        std::cout << "Array after sorting: " << bubbleSortArr[index] << "\n";
    }
}