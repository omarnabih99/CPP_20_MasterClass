#include "Converter.h"

int main()
{
    printf("%s", "Enter the decimal value to be converted to binary or -1 to exit: ");
    int inputValue;
    scanf("%d", &inputValue);

    while (inputValue != SENTINEL_VALUE)
    {
        decimalToBinary(inputValue);

        printf("%s", "Enter the decimal value to be converted to binary or -1 to exit: ");
        scanf("%d", &inputValue);
    }

    printf("%s", "Goodbye \n");
}