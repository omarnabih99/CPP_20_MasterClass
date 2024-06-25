#include "PrimeFactors.h"

int main()
{
    printf("%s", "Enter the desired number to find it's prime factors or enter the sentinel value to exit: ");
    int inputNumber;
    scanf("%d", &inputNumber);

    while (inputNumber != SENTINEL_VALUE)
    {
        primeFactor(inputNumber);

        printf("%s", "Enter the desired number to find it's prime factors or enter the sentinel value to exit: ");
        scanf("%d", &inputNumber);
    }

    printf("%s", "Goodbye! \n");
}