# Algorithms

- Algorithms are a finite series of well-defined instructions to solve a problem or to make computations.

- In order for some instructions to be an algorithm, it must be: 
1. Clear.
2. Have well-defined inputs and outputs.
3. Finite.
4. Feasible.
5. Language independent.

- Searching and Sorting Algorithms are most widely used in many applications.

## Advantages and Disadvantages

### Advantages

1. Easy to understand.
2. Algorithm is a step-wise representation of a solution to a given problem.
3. In an algorithm, the problem is broken down into smaller pieces or steps. So, it is easier for the programmer to convert it into an actual program

### Disadvantages

1. Writing an algorithm takes a long time. So, it is time consuming.
2. Uderstanding complex logic through algorithms can be very difficult.
3. Branching and looping statements are difficult to show in algorithms.

## Space and Time complexity

### Space Complexity

1. It indicates how much of memory is consumed during the run-time.
2. Space Complexity is increased as long as you define more variables that allocates more memory.

### Time Complexity

1. It indicates how much time does it take to finish the needed operation.
2. The complexity is increased as long as you make more iterations/steps to reach your goal.

## Space and Time Complexities

- Complexity is measured in Big-O notation.

1. `O(1)` means there is no dependency on the input  data size. ***(The best)***
2. `O(logn)` means logarithmic increase in operations.
3. `O(n)` means linear relation: number of operations is same as data size.
4. `O(nlogn)` means more increase in operations.
5. `O(n²)` number of operations increases rapidly with any small changes in the input data size. ***(The worst)***

![Graph](<Screenshot from 2024-04-14 03-21-34.png>)

## Measurements for some Algorithms

|   Algorithm     | Time Complexity (worst) | Space Complexity (worst)      |
|-----------------|-------------------------|-------------------------------|
| Linear Search   | O(n)                    | O(1)                          |
| Binary Search   | O(logn)                 | O(1) in case of iteration.    |
|                 |                         | O(logn) in case of recurssion.|
| Jump Search     | O(sqrt(n))              | O(1)                          |
| Bubble Sort     | O(n²)                   | O(1)                          |
| Insertion Sort  | O(n²)                   | O(1)                          |

## Some Algorithms Applications

1. The internet

2. In a transportation firm, such as trucking or railroad company, may have financial interest in finding the shortest path through a road or rail network.

3. A routing node on the internet may need to find the shortest path through the network in order to route a message quickly.

4. Searching and Sorting products in e-commerce applications.

5. Banking systems and payment gateways.

## Algorithm Life Cycle

- **Preparing the prerequisities**
1. The problem that is to be solved by the algorithm i.e. `clear problem definition`.
2. The constraints of the problem that must be considered while solving the problem.
3. The input to be taken to solve the problem.
4. The output to be expected when the problem is solved.
5. The solution to this problem within the given constraints.

- **Implementation**
1. Develop the algorithm using any programming language.

- **Testing**
1. Test your algorithm using different test cases.
