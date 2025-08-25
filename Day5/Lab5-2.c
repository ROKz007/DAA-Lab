#include <stdio.h>

/*
Write a C program to search for an element in a list of integers using the Binary Search technique and calculate:

1. Execution time (for the search operation only).
2. Number of comparisons made during the search.

Consider the following input types:

a) Best Case: The element is exactly in the middle of the sorted list.
b) Worst Case: The element is not in the list (or at one extreme).
C) Average Case: The element is somewhere in between, requiring a moderate number of comparisons.

Compare the execution time and number of comparisons for all three cases.
*/
#include <stdlib.h>
#include <time.h>
#include <string.h>

int compareIntegers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int binarySearch(int array[], int size, int key, long long *comparisons) {
    int low = 0;
    int high = size - 1;
    *comparisons = 0;

    while (low <= high) {
        (*comparisons)++;
        int mid = low + (high - low) / 2;

        if (array[mid] == key) {
            return mid;
        } else if (array[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;

    printf("Enter the number of elements in the list: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of elements. Please enter a positive integer.\n");
        return 1;
    }

    int *list = (int *)malloc(n * sizeof(int));
    
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &list[i]) != 1) {
            fprintf(stderr, "Invalid input. Please enter an integer.\n");
            free(list);
            return 1;
        }
    }
    
    qsort(list, n, sizeof(int), compareIntegers);
    printf("\nSorted List : \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    int key;
    printf("\nEnter the element to search: ");
    if (scanf("%d", &key) != 1) {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        free(list);
        return 1;
    }

    long long comparisons = 0;

    clock_t start_time = clock();

    int result_index = binarySearch(list, n, key, &comparisons);

    clock_t end_time = clock();

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    if (result_index != -1) {
        printf("\nElement %d found at index %d (0-indexed).\n", key, result_index);
    } else {
        printf("\nElement %d not found in the list.\n", key);
    }

    printf("Execution Time for search: %f seconds\n", execution_time);
    printf("Number of Comparisons: %lld\n", comparisons);

    free(list);
    return 0;
}
/*
Input:
Enter the number of elements in the list: 10
Enter 10 integers:
22 44 66 88 77 99 11 80 55 32

Output:
Sorted List :
11 22 32 44 55 66 77 80 88 99
Enter the element to search: 88
Element 88 found at index 8 (0-indexed).
Execution Time for search: 0.000000 seconds
Number of Comparisons: 3
*/
