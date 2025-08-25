#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Aim of the program: Write a menu driven program to sort list of array elements using Merge
Sort technique and calculate the execution time only to sort the elements. Count the number of
comparisons.
Sample Input from file:
MAIN MENU (MERGE SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. ERROR (EXIT)
Output:
Enter option: 1
Before Sorting: Content of the input file
After Sorting: Content of the output file
Number of Comparisons: Actual
Execution Time: lapse time in nanosecond
*/
#define MAX_SIZE 500

int comparisons = 0;

// Merge function for merge sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
    free(L);
    free(R);
}

// Merge sort function
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Function to display array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to input array
void inputArray(int arr[], int *n) {
    printf("Enter number of elements (300-500): ");
    scanf("%d", n);
    if (*n < 300 || *n > 500) {
        printf("Invalid size. Please enter between 300 and 500.\n");
        *n = 0;
        return;
    }
    printf("Enter %d elements:\n", *n);
    for (int i = 0; i < *n; i++)
        scanf("%d", &arr[i]);
}

int main() {
    int arr[MAX_SIZE], n = 0, choice;
    clock_t start, end;
    double cpu_time_used;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Input array manually\n");
        printf("2. Display array\n");
        printf("3. Sort array using Merge Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &n);
                break;
            case 2:
                if (n == 0)
                    printf("Array is empty.\n");
                else
                    display(arr, n);
                break;
            case 3:
                if (n == 0) {
                    printf("Array is empty. Please input array first.\n");
                    break;
                }
                comparisons = 0;
                start = clock();
                mergeSort(arr, 0, n - 1);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Sorted array:\n");
                display(arr, n);
                printf("Number of comparisons: %d\n", comparisons);
                printf("Execution time to sort: %f seconds\n", cpu_time_used);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
