#include <stdio.h>
/*
Given an array arr[] of size N, find the frequency of each element in the array. Display each
unique element along with its count.
Sample output:
Enter the number of elements: 7
Enter 7 elements:
1 2 2 3 4 1 2
Frequency of each element:
1 occurs 2 time(s)
2 occurs 3 time(s)
3 occurs 1 time(s)
4 occurs 1 time(s)
*/
int main() {
    int n, i, j, count;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n], freq[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1; // Initialize frequency array
    }

    for(i = 0; i < n; i++) {
        if(freq[i] == -1) {
            count = 1;
            for(j = i + 1; j < n; j++) {
                if(arr[i] == arr[j]) {
                    count++;
                    freq[j] = 0; // Mark as counted
                }
            }
            freq[i] = count;
        }
    }

    printf("Frequency of each element:\n");
    for(i = 0; i < n; i++) {
        if(freq[i] != 0) {
            printf("%d occurs %d time(s)\n", arr[i], freq[i]);
        }
    }

    return 0;
}