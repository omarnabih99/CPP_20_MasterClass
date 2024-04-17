# Binary Search Algorithm

## Steps to make binary search into an array

1. Sort the array.

2. Calculate the array mid: **mid = (start + end) / 2**.

3. Check if the mid element is matched with the value you search for.

4. if **not matched**, check if this element is larger than what you search for.

5. if **larger**, change the end to be (mid - 1) then calculate new mid.

6. if **not larger**, change the start to be (mid + 1) then calculate a new mid.

7. Repeat the previous steps until you reach the **last element**, or find a **matching element**.

8. if there is no match and program reached the last element (start = end = mid), return error not found.

9. if matched, return the index of the element.

10. **Note:** To apply `binary search` on an array, the array must be `sorted` firstly.

## Worst time complexity

- O(log n)