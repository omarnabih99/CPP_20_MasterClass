/*****************
* A file to explaing delete and default keywords in constructors
****************/

#include <iostream>

class Integer
{
private:
    int *m_pInt; // pointer to int

public:

    Integer();
    Integer(int amount);
    Integer(double) = delete; // this will prevent passing float arguments
    Integer(const Integer &obj);
    int setValue(int value);
    int setValue(float) = delete; // this will prevent passing float arguments
    ~Integer();
};

                                    /*Methods*/
//No parameters constructor
Integer::Integer()
{
    m_pInt = new int{}; // dynamically allocated int without initialization using new operator
}

//single parameter constrcutor
Integer::Integer(int amount)
{
    m_pInt = new int{amount}; // dynamically allocated int with initialiation
}

// Copy constructor
// Solves the shallow copy problem by the default constructor
// This method recieves a const reference to the target object
Integer::Integer(const Integer &obj)
{
    std::cout << "Copy Constructor: Integer(const Integer&)\n";
    m_pInt = new int{*obj.m_pInt}; // deep copy -> dynamically allocate int with initialization value equals to that of the passed object
                                  // object is passed here by reference                                
}

//Operator overloading
Integer& Integer::operator=(const Integer &obj)
{
    m_pInt = new int{*obj.m_pInt};
    return *this;
}

//destrctor here uses delete operator as constructors use new operator
//we here deal with dynamically allocated data
Integer::~Integer()
{
    delete m_pInt;
}

int main()
{
    Integer obj1(3);
    Integer obj2(obj1);
    Integer obj3(5);
    Integer obj4;
    obj4 = obj3; //-> this is shallow copying by default -> we will do operator overloading to make it deep copying

    //Integer floatObj(3.5); -> this will generate an error as we trying to pass a float value


    return 0;
}