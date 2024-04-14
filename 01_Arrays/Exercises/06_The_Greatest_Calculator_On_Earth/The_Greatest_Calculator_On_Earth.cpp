#include <iostream>
#include <ctime>

int main()
{
    std::srand(std::time(0));

    bool end {false};
    int result {};

    std::cout << "Welcome to the greatest calculator on Earth!" << "\n";
    while (end == false)
    {
        int operand1 = std::rand() % 200;
        int operand2 = std::rand() % 200;
        int operation = std::rand() % 3;


        switch (operation)
        {
            case 0 : 
                    std::cout << "what's the result of : " << operand1 << "-" << operand2 << " : ";
                    std::cin >> result;
                    if (result == (operand1 - operand2))
                    {
                        std::cout << "Congratulations! You got the result " << result << " right!" << "\n";
                    }
                    else 
                    {
                        std::cout << "the correct result is : " << operand1 - operand2 << "\n";
                    }
                    break;

           case 1 : 
                    std::cout << "what's the result of : " << operand1 << "+" << operand2 << " : ";
                    std::cin >> result;
                    if (result == (operand1 + operand2))
                    {
                        std::cout << "Congratulations! You got the result " << result << " right!" << "\n";
                    }
                    else 
                    {
                        std::cout << "the correct result is : " << operand1 + operand2 << "\n";
                    }
                    break;

           case 2 : 
                    std::cout << "what's the result of : " << operand1 << "*" << operand2 << " : ";
                    std::cin >> result;
                    if (result == (operand1 * operand2))
                    {
                        std::cout << "Congratulations! You got the result " << result << " right!" << "\n";
                    }
                    else 
                    {
                        std::cout << "the correct result is : " << operand1 * operand2 << "\n";
                    }
                    break;

        }
        std::cout << "\n";

        std::cout << "Do you want me to try again? (Y | N) : ";
        char goOn {};
        std::cin >> goOn;
        if ( (goOn == 'y') || (goOn == 'Y') )
        {
            end = false;
        }
        else
        {
            end = true;
            std::cout << "See you later!" << "\n";
        }
    }
}