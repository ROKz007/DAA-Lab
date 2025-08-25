#include <stdio.h>
/*
Given an array arr[] of size N, shift all zeroes to the end while maintaining the relative order
of non-zero elements.
Sample output:
Enter the number of elements: 8
Enter 8 elements (include some zeroes):
1 0 2 0 3 4 0 5
Original array:
1 0 2 0 3 4 0 5
Array after shifting zeroes to the end:
1 2 3 4 5 0 0 0
*/
int main() {
    int N, i, j = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N], result[N];

    printf("Enter %d elements (include some zeroes):\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Move non-zero elements to result array
    for (i = 0; i < N; i++) {
        if (arr[i] != 0) {
            result[j++] = arr[i];
        }
    }
    // Fill the rest with zeroes
    while (j < N) {
        result[j++] = 0;
    }

    printf("Array after shifting zeroes to the end:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}