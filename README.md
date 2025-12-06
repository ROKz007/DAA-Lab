# Design and Analysis of Algorithms [LAB] - CS39001

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
├── Day9/
│   └── Lab9-1.c
├── Day10/
│   ├── Lab10-1.c
│   └── Lab10-2.c
├── Day11/
│   └── Lab11-1.c
├── Day12/
│   ├── Lab12-1.c
│   └── Lab12-2.c
├── Day13/
│   └── Lab13-1.c
└── sample.c
```


---

## Implemented Programs

### Day 1: Revision of Data Structures
### Day 2: Algorithmic Problem Solving & Additional Programs
### Day 3: Recursion & Basic Algorithms
### Day 4: Recursion & Time Measurement
### Day 5: Sorting & Searching Algorithms
### Day 6: Divide and Conquer
####    > Quick Sort
####    > Max and Min Elements
### Day 7: Heap Data Structure
### Day 8: Fractional Knapsack (Greedy Technique)
### Day 9: Huffman Coding (Greedy Technique)
### Day 10: Minimum Spanning Tree (Greedy Technique)
####    > Prim's Algorithm
####    > Kruskal's Algorithm
### Day 11: Single-Source Shortest Path
####    > Dijkstra's Algorithm
### Day 12: Dynamic Programming
####    > Matrix Chain Multiplication
####    > Longest Common Subsequence
### Day 13: Dynamic Programming
####    > All-Pairs Shortest Path (Floyd-Warshall)
---

## Utility Programs

**`sample.c`**: This program is a utility to generate and optionally sort an array of integers, which can be useful for testing the other lab programs.

## My Progress

I have successfully completed all assignments up to Day 13, which marks the conclusion of the Algorithms Laboratory (CS39001) course for the Autumn 2025 semester. This repository now contains the complete collection of programs implemented during the lab sessions, spanning from fundamental data structures to advanced dynamic programming algorithms. 🚀

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