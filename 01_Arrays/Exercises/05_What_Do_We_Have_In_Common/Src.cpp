#include "What_Do_We_Have_In_Common.h"

int main()
{
    int data1[] {1,2,4,5,9,3,6,7,44,55};
    int data2[] {11,2,44,45,49,43,46,47,55,88};
    common_elements(data1, data2);

    int data3[] {1,2000,4,5,9,3,6,7,4400,5500}; 
    int data4[] {11,2,44,45,49,43,46,47,55,88};
    common_elements(data3, data4);

}