#include <iostream>
#include <ctime>

int main()
{
    // 1- Seed the std::srand()
    std::srand(std::time(0));

    // 2- define the predictions using multi dimensional array
    char prediction[][100]
    {
        { "a lot of kinds running in the backyard!" },
        { "a lot of empty beer bootles on your work table." },
        { "you Partying too much with kids wearing weird clothes." },
        { "you running away from something really scary" },
        { "clouds gathering in the sky and an army standing ready for war" },
        { "dogs running around in a deserted empty city" },
        { "a lot of cars stuck in a terrible traffic jam" },
        { "you sitting in the dark typing lots of lines of code on your dirty computer" },
        { "you yelling at your boss. And oh no! You get fired!" },
        { "you laughing your lungs out. I've never seen this before." },
        { ", huum, I don't see anything" }
    };
   

    // 3-define the sentinel value for the loop
    bool end {false};

    // 4- define the name array max size -> must be const
    const int maxSize {15};

    // 5- declare the char array which stores the user name
    char userName[maxSize] {};

    // 6- prompt the user to enter their name
    std::cout << "What is your name, dear ?" << "\n";

    // 7- take the user name as a setence
    std::cin.getline(userName, maxSize);

    // 8- while loop using sentinel value
    while (end == false)
    {
        std::cout << "Oh dear, " << userName << ". I see ";

        // we will make the range 0~10 while we have predicitions 0~9 to make room for the default case which will be satisfied when the std::rand generates 10
        int predictionIndex = std::rand() % 11;

        //print the prediction based on the random generated index
        std::cout << prediction[predictionIndex] << "\n";

        // prompt the user if he wants to try again
        std::cout << "Do you want me to try again ? (Y | N) : ";
        char goOn {};
        std::cin >> goOn;

        if ( (goOn == 'Y') || (goOn == 'y') )
        {
            end = false;
        }
        else if ( (goOn == 'N') || (goOn == 'n') )
        {
            end = true;
            std::cout << "That's all I have for you today dear. Best wishes" << "\n";
        }

    }

}