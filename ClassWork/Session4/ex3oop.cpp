#include <iostream>

using namespace std; // not recommended in large scale projects

class Car 
{
    private:
    float fuelLevel{};
    int speed{};
    int passenger{};

    public:
    Car(); // default constructor
    Car(float amount); // parameterized constructor
   // ~Car();

    void fillFuel(float amount);
    void Accelerate();
    void brake();
    void addPassenger(int newPassenger);
    void dashboard();
};

Car:: Car()
{
    cout << "I'm the default constructor" << endl;
}

Car:: Car (float amount)
{
    fuelLevel = amount;
    cout << "I'm the parameterized constructor" << endl;
}



void Car:: fillFuel(float fuelLevel)
{
    this -> fuelLevel = fuelLevel; // first use case of this pointer
                                  // used to determine which variable is the class member
}

void Car:: Accelerate()
{
    speed++;
    fuelLevel -= 0.5;
}

void Car:: brake()
{
    speed = 0;
}

void Car:: addPassenger(int newPassenger)
{ 
    passenger = newPassenger;
}

void Car:: dashboard()
{
    cout << "Fuel Level is: " << fuelLevel << endl;
    cout << "Speed is: " << speed << endl;
    cout << "Passengers are: " << passenger << endl;

}



int main()
{
    Car myCar(60);
    Car hisCar;
    Car herCar;
    Car car4;

    myCar.fillFuel(50);
    myCar.Accelerate();
    myCar.addPassenger(2);
    myCar.dashboard();

}