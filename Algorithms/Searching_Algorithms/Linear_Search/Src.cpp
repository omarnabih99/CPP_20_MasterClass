#include "Linear_Search.h"

int main()
{
    std::array <int,10> linearSearchArr {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    int searchResult {};
    int desiredElementValue {15};
    searchResult = Linear_Search(linearSearchArr.data(), linearSearchArr.size(), desiredElementValue);
    if (-1 == searchResult)
    {
        std::cout << "Element is not found" << "\n";
    }
    else 
    {
        std::cout << "Element is found at index: " << searchResult << "\n";
    }
}