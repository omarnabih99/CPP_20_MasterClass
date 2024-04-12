#include <iostream>



using namespace std; // not recommended in large scale projects

void CreateWindow (string tittle = "Omar Nabih", int x = 25, int y = 175, int color = 255)
{
    cout << "title is: " << tittle << endl;
    cout << "X is: " << x << endl;
    cout << "Y is: " << y << endl;
    cout << "Colour is: " << color << endl;
}

int main()
{
    CreateWindow(); // this function has default arguments
}