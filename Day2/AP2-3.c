#include <stdio.h>
/*
Given an array arr[] of size N, reverse the array in-place (without using any additional array
or library reverse functions). Display the array before and after the reversal.
Sample output:
Enter the number of elements: 5
Enter 5 elements:
1 2 3 4 5
Original array:
1 2 3 4 5
Reversed array:
5 4 3 2 1
*/
int main() {
    int N, i, temp;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter %d elements:\n", N);
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    for(i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reverse the array in-place
    for(i = 0; i < N / 2; i++) {
        temp = arr[i];
        arr[i] = arr[N - 1 - i];
        arr[N - 1 - i] = temp;
    }

    printf("Reversed array:\n");
    for(i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}