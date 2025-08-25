#include <stdio.h>
/*
Write a program to find the maximum and minimum element in an array using the Divide and Conquer approach.

Your program should:
a) Take an array of integers as input.
b) Use (not simple linear search) to find both the maximum and minimum elements.
c) Count and display the number of comparison made during execution.
d) Measure and display the execution time of your algorithm.
*/
#include <stdlib.h>
#include <time.h>

long long comparisons = 0;

typedef struct MaxMinResult {
    int max;
    int min;
} MaxMinResult;

MaxMinResult findMaxMin(int arr[], int low, int high) {
    MaxMinResult result, left_result, right_result;
    int mid;

    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }

    if (high == low + 1) {
        comparisons++;
        if (arr[low] > arr[high]) {
            result.max = arr[low];
            result.min = arr[high];
        } else {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }

    mid = (low + high) / 2;

    left_result = findMaxMin(arr, low, mid);
    right_result = findMaxMin(arr, mid + 1, high);

    comparisons++;
    if (left_result.max > right_result.max) {
        result.max = left_result.max;
    } else {
        result.max = right_result.max;
    }

    comparisons++;
    if (left_result.min < right_result.min) {
        result.min = left_result.min;
    } else {
        result.min = right_result.min;
    }

    return result;
}

int main() {
    int n;
    int *arr = NULL;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of elements must be positive.\n");
        return 1;
    }

    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    comparisons = 0;

    clock_t start_time = clock();

    MaxMinResult final_result = findMaxMin(arr, 0, n - 1);

    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n--- Results ---\n");
    printf("Maximum element: %d\n", final_result.max);
    printf("Minimum element: %d\n", final_result.min);
    printf("Total number of comparisons: %lld\n", comparisons);
    printf("Execution time: %.6f seconds\n", execution_time);

    free(arr);

    return 0;
}
/*
input/output
Enter the number of elements in the array: 10
Enter 10 integers:
528 330 19 806 87 527 580 713 672 818

--- Results ---
Maximum element: 818
Minimum element: 19
Total number of comparisons: 14
Execution time: 0.000000 seconds
*/