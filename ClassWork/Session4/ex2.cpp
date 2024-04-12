#include <iostream>

using namespace std; // not recommended in large scale projects

namespace calculator
{
    int sum (int x, int y)
    {
        return x + y;
    }
}

namespace calc
{
    int sum (int x, int y)
    {
        return (x + y) / 2;
    }
}

int main()
{
    int x, y;
    x = calculator:: sum(10, 20);
    y = calc:: sum(20, 30);
    cout << "x is " << x << endl;
    cout << "y is " << y << endl;
}