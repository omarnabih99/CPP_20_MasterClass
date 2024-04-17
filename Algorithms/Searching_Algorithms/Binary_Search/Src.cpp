#include "Binary_Search.h"

int main()
{   
    // the array is hard coded to be sorted
    std::array <int,10> binarySearchArr {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int searchResult{};
    int desiredElementValue {5};
    searchResult = Binary_Search(binarySearchArr.data(), binarySearchArr.size(), desiredElementValue);
    if (-1 == searchResult)
    {
        std::cout << "Element is not found" << "\n";
    }
    else
    {
        std::cout << "Element is found at index: " << searchResult << "\n";
    }

}