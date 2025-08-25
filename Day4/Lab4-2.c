#include <stdio.h>
/*
Q. WAP to print the Fibonacci series using recursion. Also measure the execution time of the program.
Input:
Enter the number of terms: 20
Output:
Fibonacci series for 20 terms:
0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181
Execution time: 0.001000 seconds
*/
#include <time.h>

void printFibonacci(unsigned long a, unsigned long b, unsigned long count) {
    if (count == 0)
        return;
    unsigned long next = a + b;
    printf("%lu ", next);
    printFibonacci(b, next, count - 1);
}

int main() {
    unsigned long n;
    clock_t start, end;
    printf("Enter the number of terms: ");
    scanf("%lu", &n);

    printf("Fibonacci series for %lu terms:\n", n);

    if (n >= 1) printf("%lu ", 0UL);
    if (n >= 2) printf("%lu ", 1UL);

    start = clock();
    printFibonacci(0UL, 1UL, n - 2);
    end = clock();

    double exe_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nExecution time: %f seconds\n", exe_time);
    return 0;
}
