#include "Jump_Search.h" 

int main()
{
    std::array <int,11> jumpSearchArr {1, 2, 7, 8, 10, 12, 15, 16, 19, 20, 30};
    int searchResult {};
    
    searchResult = Jump_Search(jumpSearchArr.data(), jumpSearchArr.size(), 19);
    if (-1 == searchResult)
    {
        std::cout << "Element not found" << "\n";
    }
    else
    {
        std::cout << "Element is found at index: " << searchResult << "\n";
    }

    searchResult = Jump_Search(jumpSearchArr.data(), jumpSearchArr.size(), 30);
    if (-1 == searchResult)
    {
        std::cout << "Element not found" << "\n";
    }
    else
    {
        std::cout << "Element is found at index: " << searchResult << "\n";
    }

    searchResult = Jump_Search(jumpSearchArr.data(), jumpSearchArr.size(), 20);
    if (-1 == searchResult)
    {
        std::cout << "Element not found" << "\n";
    }
    else
    {
        std::cout << "Element is found at index: " << searchResult << "\n";
    }

    searchResult = Jump_Search(jumpSearchArr.data(), jumpSearchArr.size(), 1);
    if (-1 == searchResult)
    {
        std::cout << "Element not found" << "\n";
    }
    else
    {
        std::cout << "Element is found at index: " << searchResult << "\n";
    }

    searchResult = Jump_Search(jumpSearchArr.data(), jumpSearchArr.size(), -2);
    if (-1 == searchResult)
    {
        std::cout << "Element not found" << "\n";
    }
    else
    {
        std::cout << "Element is found at index: " << searchResult << "\n";
    }
}