#include <iostream>

using namespace std;

int main()
{
    int arr [] = {1,2,3,4,5,6};
    for (int i =0; i < 6; i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<< "***********"<<endl;
        for(int x : arr)
    {
        cout<<x<<endl;
    }
    cout<< "***********"<<endl;
    for(int x : arr)
    {
        cout<<x+1<<endl;
    }

}