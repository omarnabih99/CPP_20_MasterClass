/*****************
* A file to explaing copy constructor, shallow copy, deep copy, operator overloading
****************/

#include <iostream>

class Integer
{
private:
    int *m_pInt; // pointer to int

public:
    Integer();
    Integer(int amount);
    Integer(const Integer &obj);
    void SetValue(int value);
    int GetValue();
    Integer& operator=(const Integer &obj);
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

//modify the value of a current object
void Integer::SetValue(int value)
{
    *m_pInt = value;
}

//return the value of a current object
int Integer::GetValue()
{
    return *m_pInt;
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
    std::cout << "obj1 = " << obj1.GetValue() << "\n";

    Integer obj2(obj1);
    std::cout << "obj2 = " << obj2.GetValue() << "\n";

    Integer obj3(5);
    Integer obj4;

   obj4 = obj3; //-> this is shallow copying by default -> we will do operator overloading to make it deep copying

    return 0;
}