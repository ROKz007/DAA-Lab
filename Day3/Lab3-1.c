#include <stdio.h>
/*
Aim of the program: Write a program in C to convert ‘n’ decimal numbers to binary using recursion.
input:
Enter Decimal number-
2564
output:
The binary equivalent of 2564 is 0000101000000100
*/
// Function to recursively convert decimal to binary and store in array
void decimalToBinary(int n, int binary[], int *index) {
    if (n > 0) {
        decimalToBinary(n / 2, binary, index);
        binary[(*index)++] = n % 2;
    }
}

int main() {
    int n;
    printf("Enter Decimal number-\n");
    scanf("%d", &n);

    int binary[16] = {0}; // For 16 bits
    int index = 0;

    decimalToBinary(n, binary, &index);

    // Pad with leading zeros if necessary
    for (int i = 0; i < 16 - index; i++) {
        printf("0");
    }
    for (int i = 0; i < index; i++) {
        printf("%d", binary[i]);
    }
    printf("\nThe binary equivalent of %d is ", n);
    for (int i = 0; i < 16 - index; i++) {
        printf("0");
    }
    for (int i = 0; i < index; i++) {
        printf("%d", binary[i]);
    }
    printf("\n");

    return 0;
}