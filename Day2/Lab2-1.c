#include <stdio.h>

/*Aim of the program: Write a program to read ‘n’ integers from a disc file that must contain
some duplicate values and store them into an array. Perform the following operations on the
array.

a) Find out the total number of duplicate elements.
b) Find out the most repeating element in the array.

Input:
Enter how many numbers you want to read from file: 15
Output:
The content of the array: 10 40 35 47 68 22 40 10 98 10 50 35 68 40 10
Total number of duplicate values = 4
The most repeating element in the array = 10*/

int main() {
    int n, i, j;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The content of the array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Count duplicates
    int duplicate_count = 0;
    int counted[n]; // To mark already counted duplicates
    for (i = 0; i < n; i++) {
        counted[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (counted[i])
            continue;
        int count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                counted[j] = 1;
            }
        }
        if (count > 1) {
            duplicate_count++;
        }
    }

    // Find most repeating element
    int max_count = 0, most_repeating = arr[0];
    for (i = 0; i < n; i++) {
        int count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            most_repeating = arr[i];
        }
    }

    printf("Total number of duplicate values = %d\n", duplicate_count);
    printf("The most repeating element in the array = %d\n", most_repeating);

    return 0;
}