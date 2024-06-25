# Exercise 3: Decimal to binary using stacks

## Steps to convert a decimal number to a binary number

1. Divide the number by `2`.

2. Store the remainder somewhere.

3. Repeat step 1 and 2 untill the `quotient` becomes 0.

4. print all the remainders in reverse order.

- Example: number = 77

    77 / 2 = 38 `(1)`

    38 / 2 = 19 `(0)`

    19 / 2 = 9 `(1)`

    9 / 2 = 4 `(1)`

    4 / 2 = 2 `(0)`

    2 / 2 = 1 `(0)`

    1 / 2 = 0 `(1)`

- So, the binary representaion will be the remainders from downside :

    (1 0 0 1 1 0 1)