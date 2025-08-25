#include <stdio.h>
/*
Aim of the program: Write a function to ROTATE_RIGHT (p1, p2) right an array for first p2
elements by 1 position using EXCHANGE (p, q) function that swaps/exchanges the numbers p
& q. Parameter p1 be the starting address of the array and p2 be the number of elements to be
rotated.
Input:
Enter an array A of size N (9): 11 22 33 44 55 66 77 88 99
Call the function ROTATE_RIGHT (A, 5)
Output:
Before ROTATE: 11 22 33 44 55 66 77 88 99
After ROTATE: 55 11 22 33 44 66 77 88 99 
*/
// Function to exchange/swap two integers
void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

// Function to rotate right the first p2 elements of array by 1 position
void ROTATE_RIGHT(int *p1, int p2) {
    if (p2 <= 1) return; // No rotation needed for 0 or 1 elements

    // Move the last of first p2 elements to the front
    for (int i = p2 - 1; i > 0; i--) {
        EXCHANGE(&p1[i], &p1[i-1]);
    }
}

int main() {
    int N;
    printf("Enter size of array N: ");
    scanf("%d", &N);

    int A[N];
    printf("Enter array A of size %d: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    printf("Before ROTATE: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    int p2;
    printf("Enter number of elements to rotate (p2): ");
    scanf("%d", &p2);

    ROTATE_RIGHT(A, p2);

    printf("After ROTATE: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}