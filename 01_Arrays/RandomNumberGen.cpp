#include <iostream>
#include <ctime>

/*
*   Random Number Generation
*/

int main()
{
/*
*   1- Using std::rand()
*/
    // generates a number between 0 and RAND_MAX
    // RAND_MAX is determined by the compiler
    int randomNumber = std::rand();

    // print out the generated random number
    std::cout << "The random number is: " << randomNumber << "\n";

    // print out the RAND_MAX variable -> 2147483647
    std::cout << "RAND_MAX is: " << RAND_MAX << "\n";

/*
*   2- Limiting the generated random number
*/
    // we use % operator to limit the random number
    // the number after the % operator represents the upper limit of possible numbers minus 1
    // that means the possible range 0~10
    int limitedRandomNumber = std::rand() % 11;
    std::cout << "The limited random number is: " << limitedRandomNumber << "\n";

    for(int i {}; i < 30; i++)
    {
        limitedRandomNumber = std::rand() % 11;
        std::cout << "The limited random number (0~10) is: " << limitedRandomNumber << "\n";
    }

    // we can modify the range to be 1~11 by adding 1
    int limitRandomNumber2 = (std::rand() % 11) + 1;

    for(int i{}; i < 30; i++)
    {
        limitRandomNumber2 = (std::rand() % 11) + 1;
        std::cout << "The limited random number (1~11) is: " << limitRandomNumber2 << "\n";
    }

/*
*   Note: std::rand has a disadvantage that you will get the same sequence each time the
*   program runs even if you re-compiled your program.
*/

/*
*   3- Using seed to avoid the previous disadvantage.
*   -> Seed is a hint to the compiler to give a different numbers every time the program runs.
*/
    // we will use std::time(0) as a seed
    // this function calculates the time since jan. 1st, 1970 at 00:00:00 AM.
    // this means that the seed will change every second.
    // ctime header file is required to use std::time()
    std::srand(std::time(0));

    // random number is limited to 1~11
    int limitedRandomNumber3 = (std::rand() % 11) + 1;
    for(int i{}; i < 30; i++)
    {
        limitedRandomNumber3 = (std::rand() % 11) + 1;
        std::cout << "The limited random number (1~11) with seed is: " << limitedRandomNumber3 << "\n";
    }

}
