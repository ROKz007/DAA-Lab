#include <stdio.h>
#include <stdlib.h>
/*
Aim of the program: Write a program to find the maximum profit nearest to but not
exceeding the given knapsack capacity using the Fractional Knapsack algorithm.
Notes# Declare a structure ITEM having data members item_id, item_profit, item_weight and
profit_weight_ratio. Apply heap sort technique to sort the items in non-increasing order,
according to their profit /weight.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
} ITEM;

float calculate_profit_weight_ratio(float profit, float weight) {
    return profit / weight;
}

void heapify(ITEM arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;

    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i) {
        ITEM temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(ITEM arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        ITEM temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    int num_items;
    float knapsack_capacity;

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    ITEM items[num_items];

    for (int i = 0; i < num_items; i++) {
        items[i].item_id = i + 1;
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
        items[i].profit_weight_ratio = calculate_profit_weight_ratio(items[i].item_profit, items[i].item_weight);
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &knapsack_capacity);

    heapSort(items, num_items);

    float total_profit = 0.0;
    float current_weight = 0.0;

    printf("Item No profit Weight Amount to be taken\n");

    for (int i = 0; i < num_items; i++) {
        if (current_weight + items[i].item_weight <= knapsack_capacity) {
            total_profit += items[i].item_profit;
            current_weight += items[i].item_weight;
            printf("%d %f %f %f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, 1.0);
        } else {
            float remaining_capacity = knapsack_capacity - current_weight;
            if (remaining_capacity > 0) {
                float fraction = remaining_capacity / items[i].item_weight;
                total_profit += items[i].item_profit * fraction;
                current_weight += items[i].item_weight * fraction;
                printf("%d %f %f %f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, fraction);
            } else {
                printf("%d %f %f %f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, 0.0);
            }
        }
    }

    printf("Maximum profit: %f\n", total_profit);

    return 0;
}

/*
Sample Input:
Enter the number of items: 3
Enter the profit and weight of item no 1: 27 16
Enter the profit and weight of item no 2: 14 12
Enter the profit and weight of item no 3: 26 13
Enter the capacity of knapsack: 18

Sample Output:
Item No profit Weight Amount to be taken
3 26.000000 13.000000 1.000000
1 27.000000 16.000000 0.312500
2 14.000000 12.000000 0.000000
Maximum profit: 34.437500
*/
