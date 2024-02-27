#include <iostream>
using namespace std;


class tmp 
{
    public:
    int x; // variable is called attribute here
    void printHello() // function is called method here
    {
        cout<<"Hello World!"<<endl;
    }
};

int main()
{
    tmp A;
    A.x = 10;
    A.printHello();
    cout<<A.x<<endl;
}