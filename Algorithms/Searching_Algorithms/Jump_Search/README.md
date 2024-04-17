# Jump Search Algorithm

## Steps to make jump search into an array

1. Sort the array.

2. Calculate the jump: jump = min( sqrt(array_size) ) - 1.

3. Check if the first element -index 0- is matched with the value you search for. If matched return `the index`

4. If not matched and **smaller**, add one jump to the index.

5. If not matched and **larger**, return `error not found`. This happens as the array is already sorted and the first element in the array is larger than the value you search for. So, the rest of array will also be larger than the value then the element is not found.

6. Check if the current element -index i- is matched with the value you search for. If matched return `the index`.

7. If not matched and **smaller**, add one jump to the index.

8. If not matched and **larger**, make linear search backwards till the previous jump position.

9. Repeat the previous steps until you reach the last element or find a matching element.

10. If not matched and the program reached the last element, return `error not found`.

11. If matched, return `the index`.

## Worst time complexity

- O(sqrt(n)).

-Better than `Linear Search` but worst than `Binary Search`.