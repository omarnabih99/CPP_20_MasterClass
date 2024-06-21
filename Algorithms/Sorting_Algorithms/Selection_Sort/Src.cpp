#include "Selection_Sort.h"

int main()
{
    std::array <int,10> selectionSortArr {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::cout << "Array before sorting: ";
    for (size_t index {0}; index != selectionSortArr.size(); index++)
    {
        std::cout << selectionSortArr[index] << " ";
    }
    std::cout << "\n";

    Selection_Sort(selectionSortArr.data(), selectionSortArr.size());
}