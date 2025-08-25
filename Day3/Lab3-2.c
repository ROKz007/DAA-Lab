#include <stdio.h>
/*
Aim of the program: Write a program in C to find GCD of two numbers using recursion.
Read all pair of numbers from input.
input:
8 12 20 45 30 80
output:
The GCD of 8 and 12 is 4
The GCD of 20 and 45 is 5
The GCD of 30 and 80 is 10
*/
// Recursive function to find GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int nums[100], count = 0, i, pairs;
    printf("Enter number of pairs: ");
    scanf("%d", &pairs);
    if (pairs <= 0 || pairs * 2 > 100) {
        printf("Invalid number of pairs.\n");
        return 0;
    }
    printf("Enter %d pairs of numbers:\n", pairs);
    for (i = 0; i < pairs * 2; i++) {
        scanf("%d", &nums[i]);
    }
    for (i = 0; i < pairs * 2; i += 2) {
        printf("The GCD of %d and %d is %d\n", nums[i], nums[i+1], gcd(nums[i], nums[i+1]));
    }
    return 0;
}