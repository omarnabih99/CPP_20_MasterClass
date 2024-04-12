#include <iostream>

//#define PI 3.1415  #defines are not recommended

using namespace std;

int main()
{
    const float PI = 3.1415;
    //use ref to constant data
    float radius;
    cin>>radius;
    float area = PI * radius * radius;
    float circum = 2 * PI * radius;

    cout<<area<<endl<<circum<<endl;
}