#include <iostream>
using namespace std;


class Calculator 
{
    private:
    int a, b;

    public:
    Calculator (int x, int y)
    {
        a = x;
        b = y;
    }

    void add (void)
    {
        cout<<"Result is: "<<a+b<<endl;
    }
        void sub (void)
    {
        cout<<"Result is: "<<a-b<<endl;
    }
        void product (void)
    {
        cout<<"Result is: "<<a*b<<endl;
    }
        void divide (void)
    {
        cout<<"Result is: "<<a/b<<endl;
    }


};

int main()
{
    int x;
    cout<<"Enter the first number:";
    cin>>x;

    int y;
    cout<<"Enter the second number:";
    cin>>y;

    Calculator res(x, y);
    res.add();
}