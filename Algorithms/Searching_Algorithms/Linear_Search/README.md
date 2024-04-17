# Linear Search Algorithm

## Steps to make Linear Search into an array

1. Check if array element is matched with the value you search for.

2. If **not matched**, move to the next element.

3. Repeat the previous steps until you reach the **last element**, or find a **matching element**.

4. If **not matched** and the program reached to the **last element**, return `error not found`.

5. If **matched**, return `the index of that element`.

## Worst Case

- The worst case is that the element is not found.

- If we have an array of 100 elements that doesn't contain the element we are searching for, we will iterate 100 times till reaching the **last element**.

- Worst case time of linear search depends linearly with the data.

## Worst case time complexity

- O(n).