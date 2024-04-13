#include <iostream>
#include "Hunt_For_Vowels.h"

void hunt_for_vowels(char* message, unsigned int size)
{
    unsigned int vowel_count{};//Initialized to zero

    for (int index {}; index < size; index++)
    {
        if (
                message[index] == 'a' || 
                message[index] == 'A' || 
                message[index] == 'e' || 
                message[index] == 'E' || 
                message[index] == 'o' || 
                message[index] == 'O' || 
                message[index] == 'u' ||
                message[index] == 'U' || 
                message[index] == 'i' || 
                message[index] == 'I'
            )
            {
                vowel_count ++;
            }
    }
  
    std::cout << "The string : " << message << " has " << vowel_count << " vowels" << "\n";
}