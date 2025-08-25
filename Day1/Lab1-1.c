#include <stdio.h>
/*
1.1 Aim of the program: Write a program to find out the second smallest and second largest
element stored in an array of n integers.
Input: Size of the array is ‘n’ and read ‘n’ number of elements from a disc file.
Output: Second smallest, Second largest
*/
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array must have at least 2 elements.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int smallest, second_smallest;
    int largest, second_largest;

    // Initialize smallest and largest
    if (arr[0] < arr[1]) {
        smallest = arr[0];
        second_smallest = arr[1];
        largest = arr[1];
        second_largest = arr[0];
    } else {
        smallest = arr[1];
        second_smallest = arr[0];
        largest = arr[0];
        second_largest = arr[1];
    }

    for (int i = 2; i < n; i++) {
        // For smallest and second smallest
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }

        // For largest and second largest
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }

    if (smallest == second_smallest)
        printf("No second smallest element.\n");
    else
        printf("Second smallest element: %d\n", second_smallest);

    if (largest == second_largest)
        printf("No second largest element.\n");
    else
        printf("Second largest element: %d\n", second_largest);

    return 0;
}