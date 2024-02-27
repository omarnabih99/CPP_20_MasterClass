#include <iostream>
using namespace std;


class ExampleClass 
{
    public:
    int x, y, z;
    ExampleClass()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    ExampleClass(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }

    ~ExampleClass()
    {
        cout<<"Destructed"<<endl;
    }

};

int main()
{
    ExampleClass A;
    cout<<A.x<<endl;
    {
    ExampleClass B(1, 2, 3);
    cout<<B.x<<endl;
    }   

   cout<<A.y<<endl;
   //cout<<B.y<<endl; B is no longer existed

}