#include "Insertion_Sort.h"

int main()
{
    std::array <int,7> insertionSortArr{12, 30, 1, 7, 16, 20, 15};
    std::cout << "Array before sorting: ";
    for(size_t index {0}; index != insertionSortArr.size(); index++)
    {
        std::cout << insertionSortArr[index] << " ";
    }
    std::cout << "\n";

    Insertion_Sort(insertionSortArr.data(), insertionSortArr.size());
}