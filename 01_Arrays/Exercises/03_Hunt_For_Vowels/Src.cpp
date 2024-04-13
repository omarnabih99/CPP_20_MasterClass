#include "Hunt_For_Vowels.h"

int main()
{
    char inputMessage[] {"The Sky Is Blue"};

    hunt_for_vowels(inputMessage, std::size(inputMessage));
}