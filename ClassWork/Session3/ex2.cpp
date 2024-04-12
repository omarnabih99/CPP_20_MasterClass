#include <iostream>

using namespace std;

int main()
{
    int var = 5;
    int var1 = 10;

/*reference to lval*/
    int & refa = var; // references must be initialized
    refa = var1; // this is equivalent to var = var1


    refa++; // incrementing the var not var1 

    int x = sizeof(refa); // this will return the size of the variable
                         // not the reference itself due to auto dereferencing

    cout<<var<<endl;
    cout<<x<<endl;


/*reference to rval*/

int && refb = 5; // reference to right value
                // search about it

}