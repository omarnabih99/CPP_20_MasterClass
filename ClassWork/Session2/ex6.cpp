#include <iostream>
using namespace std;


class DeepCopy
{
    public:
    int* data;
    DeepCopy()
    {
        data = new int[100];
        for(int i =0; i < 100; i++)
        {
            data[i] = i;
        }
    }

    ~DeepCopy()
    {
        delete[] data;
    }

    DeepCopy(const DeepCopy &oldObj)
    {
        data = new int[100];
        for (int i = 0; i < 100; i++)
        {
            data[i] = oldObj.data[i];
        }
    }

};



int main()
{
   DeepCopy A;
   DeepCopy C(A);
   cout<<"A"<<"   "<<"C"<<endl;
   for(int i = 0; i < 100; i++)
   {
    cout<<A.data[i]<<"   "<<C.data[i]<<endl;
   }
}