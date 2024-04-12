#include <iostream>
using namespace std;


class Calculator 
{
    private:
    int a, b;
    static int count;

    public:
    
    Calculator()
    {
        count++;
    }
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

    static int get_count()
    {
        return count;
    }

};

int Calculator::count = 0;

int main()
{
   
   int x;
    cout<<"Enter the first number:";
    cin>>x;

    int y;
    cout<<"Enter the second number:";
    cin>>y;

    Calculator res1(x, y);
    res1.add();
   


    Calculator first;
    cout<<first.get_count()<<endl;

    Calculator second;
    cout<<second.get_count()<<endl;

    Calculator third;
    cout<<third.get_count()<<endl;

}