#include <stdio.h>
/*
Generate sample array of integers of user specified size.
Also get it sorted in ascending or descending order based on user preference.
*/
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSortAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void bubbleSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void displayArray(int arr[], int size) {
    if (arr == NULL || size <= 0) {
        printf("Array is empty or not initialized.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *sampleArray = NULL;
    int arraySize = 0;
    char wantsSorted;
    char sortOrder;

    srand(time(NULL));

    printf("Enter the desired size of the array: ");
    if (scanf("%d", &arraySize) != 1 || arraySize <= 0) {
        printf("Invalid input. Please enter a positive integer for the array size.\n");
        return 1;
    }

    sampleArray = (int *)malloc(arraySize * sizeof(int));

    if (sampleArray == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Generating a sample array of %d elements...\n", arraySize);
    for (int i = 0; i < arraySize; i++) {
        sampleArray[i] = rand() % 1000 + 1;
    }

    printf("\nGenerated Array: ");
    displayArray(sampleArray, arraySize);

    while (getchar() != '\n');

    printf("\nDo you want to sort the array? (y/n): ");
    if (scanf(" %c", &wantsSorted) != 1) {
        printf("Invalid input. Please enter 'y' or 'n'.\n");
        free(sampleArray);
        return 1;
    }
    wantsSorted = tolower(wantsSorted);

    if (wantsSorted == 'y') {
        while (getchar() != '\n');

        printf("Sort in ascending (a) or descending (d) order?: ");
        if (scanf(" %c", &sortOrder) != 1) {
            printf("Invalid input. Please enter 'a' or 'd'.\n");
            free(sampleArray);
            return 1;
        }
        sortOrder = tolower(sortOrder);

        if (sortOrder == 'a') {
            printf("\nSorting array in ascending order...\n");
            bubbleSortAscending(sampleArray, arraySize);
        } else if (sortOrder == 'd') {
            printf("\nSorting array in descending order...\n");
            bubbleSortDescending(sampleArray, arraySize);
        } else {
            printf("Invalid sort order choice. Array will not be sorted.\n");
        }

        printf("\nResulting Array: ");
        displayArray(sampleArray, arraySize);
    } else if (wantsSorted == 'n') {
        printf("Array will not be sorted.\n");
        printf("\nFinal Array: ");
        displayArray(sampleArray, arraySize);
    } else {
        printf("Invalid choice. Array will not be sorted.\n");
        printf("\nFinal Array: ");
        displayArray(sampleArray, arraySize);
    }

    free(sampleArray);
    sampleArray = NULL;

    return 0;
}
