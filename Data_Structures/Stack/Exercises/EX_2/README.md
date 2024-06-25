# Exercise 2: Prime factors in descending order

- Write a program to print all the prime factors of a number in descending order using a stack.

## How to find prime factors of a number

- If the number is divisible by a prime number. So, this prime number is a prime factor of this number.

- Keep dividing the number by a prime number till the result of the division is a prime number too.

- Example: given number is 12

    12 / `2` = 6 -> 6 is a composite number

    6 / `2` = `3` -> 3 is a prime number

    `3` / `3` = 1 -> stop division

    So, the prime factors of 12 are `3`, `2`, and `2`.