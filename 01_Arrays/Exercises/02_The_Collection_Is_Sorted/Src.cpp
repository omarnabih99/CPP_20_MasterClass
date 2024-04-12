#include "The_Collection_Is_Sorted.h"

int main()
{
    std::array testArr {1, 2, 3, 4};

    bool sorted = is_collection_sorted(testArr.data(), testArr.size());
    if(sorted)
    {
        std::cout << "The array is sorted" << "\n";
    }
    else
    {
        std::cout << "The array is not sorted" << "\n";
    }
}
