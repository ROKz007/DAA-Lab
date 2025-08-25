# Algorithms Laboratory - CS39001

This repository contains C programs for the **Algorithms Laboratory (CS39001)** course at KIIT University for the Autumn 2025 semester. The labs cover fundamental data structures and algorithmic techniques as outlined in the course manual.

---

## Repository Structure

The programs are organized by "Day" folders, corresponding to the lab sessions.

```
.
├── .gitignore
├── Day1/
│   ├── Lab1-1.c
│   └── Lab1-2.c
├── Day2/
│   ├── AP2-3.c
│   ├── AP2-4.c
│   ├── AP2-5.c
│   ├── Lab2-1.c
│   └── Lab2-2.c
├── Day3/
│   ├── Lab3-1.c
│   └── Lab3-2.c
├── Day4/
│   ├── Lab4-1.c
│   └── Lab4-2.c
├── Day5/
│   ├── Lab5-1.c
│   └── Lab5-2.c
├── Day6/
│   ├── Lab6-1.c
│   └── Lab6-2.c
├── Day7/
│   └── Lab7-1.c
└── sample.c
```


---

## Implemented Programs

Here's a breakdown of the C programs implemented so far:

### Day 1: Revision of Data Structures

* **`Lab1-1.c`**: Finds the **second smallest and second largest** elements in an array of `n` integers.

* **`Lab1-2.c`**: Computes the **prefix sum** of an array.

### Day 2: Fundamentals of Algorithmic Problem Solving & Additional Programs

* **`Lab2-1.c`**: Identifies the **total number of duplicate elements** and the **most repeating element** in an array.

* **`Lab2-2.c`**: Implements a `ROTATE_RIGHT` function to right-rotate the first `p2` elements of an array by 1 position using an `EXCHANGE` (swap) function.

* **`AP2-3.c`**: Reverses an array **in-place** (without using an additional array).

* **`AP2-4.c`**: Finds the **frequency of each element** in an array.

* **`AP2-5.c`**: Shifts all **zeroes to the end** of an array while maintaining the relative order of non-zero elements.

### Day 3: Recursion & Basic Algorithms

* **`Lab3-1.c`**: Converts a decimal number to its **binary equivalent** using recursion.

* **`Lab3-2.c`**: Finds the **GCD (Greatest Common Divisor)** of pairs of numbers using recursion.

### Day 4: Recursion & Time Measurement

* **`Lab4-1.c`**: Calculates the **factorial of a number** using recursion.

* **`Lab4-2.c`**: Prints the **Fibonacci series** using recursion and measures its execution time.

### Day 5: Sorting Algorithms & Search

* **`Lab5-1.c`**: Implements **Merge Sort** to sort array elements and measures execution time and number of comparisons.

* **`Lab5-2.c`**: Implements **Binary Search** to find an element, measuring execution time and comparisons for best, worst, and average cases.

### Day 6: Divide and Conquer

* **`Lab6-1.c`**: Implements **Quick Sort** with an analysis of partitioning (best, worst, average case) and counts comparisons.

* **`Lab6-2.c`**: Finds the **maximum and minimum elements** in an array using the Divide and Conquer approach, counting comparisons and measuring execution time.

### Day 7: Heap Data Structure

* **`Lab7-1.c`**: Defines a `struct person` and implements a **menu-driven program for heap operations**. This program reads student data (ID, name, age, height, weight) into a dynamically allocated array. It supports:
    * Creating a **Min-heap based on age** to quickly find the youngest person.
    * Creating a **Max-heap based on weight** for other potential operations.
    * Displaying the **weight of the youngest person**.
    * **Inserting** a new person into the age-based min-heap.
    * **Deleting** the oldest person from the data.

---

## My Progress

I've successfully completed all assignments up to **Day 7**, including several additional programs from the lab manual. I'll be updating this repository regularly as I attend more lab classes and complete further assignments. Stay tuned for more algorithms! 🚀

---

## How to Compile and Run

To compile and run any of the C programs:

1.  Navigate to the directory containing the `.c` file in your terminal.

2.  Compile the program using a C compiler (like GCC):

    ```bash
    gcc <program_name>.c -o <output_executable_name>
    ```

    For example: `gcc Day1/Lab1-1.c -o Lab1-1`

3.  Run the executable:

    ```bash
    ./<output_executable_name>
    ```

    For example: `./Lab1-1`

Some programs might require specific input files or command-line arguments as described in their respective comments or the lab manual.

---

## .gitignore

The `.gitignore` file is configured to ignore compiled executables (`*.exe`) to keep the repository clean.
