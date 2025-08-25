#include <stdio.h>
/*
Write a menu driven program in C to sort a list of elements in ascending order using Quick Sort technique.
After sorting display the content of the output along with number of comparisons.
Based on the partitioning position for each recursive call,
conclude the input scenario is either best-case partitioning or worst-case partitioning. 
*/
#include <stdlib.h>
#include <string.h>

long long comparisons = 0;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        int left_subarray_size = pi - low;
        int right_subarray_size = high - pi;
        int total_size = high - low + 1;

        printf("  Partition: Current range [%d, %d], Pivot index: %d\n", low, high, pi);
        printf("    Left sub-array size: %d, Right sub-array size: %d\n", left_subarray_size, right_subarray_size);

        if (left_subarray_size == 0 || right_subarray_size == 0) {
            printf("    Conclusion: Worst-case partitioning (pivot is an extreme element).\n");
        } else if (abs(left_subarray_size - right_subarray_size) <= 1 || (double)left_subarray_size / total_size >= 0.4 && (double)left_subarray_size / total_size <= 0.6) {
            printf("    Conclusion: Best-case partitioning (pivot is near the median).\n");
        } else {
            printf("    Conclusion: Average-case partitioning.\n");
        }

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr = NULL;
    int n = 0;
    int choice;

    do {
        printf("\n--- Quick Sort Menu ---\n");
        printf("1. Enter elements\n");
        printf("2. Sort and Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (arr != NULL) {
                    free(arr);
                }
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                arr = (int*)malloc(n * sizeof(int));
                if (arr == NULL) {
                    printf("Memory allocation failed!\n");
                    return 1;
                }
                printf("Enter %d integers:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("Elements entered successfully.\n");
                break;

            case 2:
                if (arr == NULL || n == 0) {
                    printf("Please enter elements first (Option 1).\n");
                } else {
                    int *temp_arr = (int*)malloc(n * sizeof(int));
                    if (temp_arr == NULL) {
                        printf("Memory allocation failed!\n");
                        break;
                    }
                    memcpy(temp_arr, arr, n * sizeof(int));

                    comparisons = 0;
                    printf("\nOriginal array: ");
                    printArray(temp_arr, n);

                    printf("\n--- Partitioning Analysis ---\n");
                    quickSort(temp_arr, 0, n - 1);
                    printf("\n-----------------------------\n");

                    printf("Sorted array: ");
                    printArray(temp_arr, n);
                    printf("Total number of comparisons: %lld\n", comparisons);
                    free(temp_arr);
                }
                break;

            case 3:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    if (arr != NULL) {
        free(arr);
    }

    return 0;
}
/*
input/output
--- Quick Sort Menu ---
1. Enter elements
2. Sort and Display
3. Exit
Enter your choice: 1
Enter the number of elements: 10
Enter 10 integers:
528 330 19 806 87 527 580 713 672 818 
Elements entered successfully.

--- Quick Sort Menu ---
1. Enter elements
2. Sort and Display
3. Exit
Enter your choice: 2

Original array: 528 330 19 806 87 527 580 713 672 818

--- Partitioning Analysis ---
  Partition: Current range [0, 9], Pivot index: 9
    Left sub-array size: 9, Right sub-array size: 0
    Conclusion: Worst-case partitioning (pivot is an extreme element).
  Partition: Current range [0, 8], Pivot index: 6
    Left sub-array size: 6, Right sub-array size: 2
    Conclusion: Average-case partitioning.
  Partition: Current range [0, 5], Pivot index: 5
    Left sub-array size: 5, Right sub-array size: 0
    Conclusion: Worst-case partitioning (pivot is an extreme element).
  Partition: Current range [0, 4], Pivot index: 3
    Left sub-array size: 3, Right sub-array size: 1
    Conclusion: Average-case partitioning.
  Partition: Current range [0, 2], Pivot index: 1
    Left sub-array size: 1, Right sub-array size: 1
    Conclusion: Best-case partitioning (pivot is near the median).
  Partition: Current range [7, 8], Pivot index: 8
    Left sub-array size: 1, Right sub-array size: 0
    Conclusion: Worst-case partitioning (pivot is an extreme element).

-----------------------------
Sorted array: 19 87 330 527 528 580 672 713 806 818
Total number of comparisons: 29

--- Quick Sort Menu ---
1. Enter elements
2. Sort and Display
3. Exit
Enter your choice: 3
Exiting program. Goodbye!
*/