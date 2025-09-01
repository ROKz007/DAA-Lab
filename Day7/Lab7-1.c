#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
/*
Define a struct person as follows:
struct person
{
int id;
char *name;
int age;
int height;
int weight;
};
Write a menu driven program to read the data of ‘n’ students and store them in a dynamically allocated array of struct person.
Implement the min-heap or max-heap and its operations based on the menu options.
*/
struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

struct person *g_persons_array = NULL;
int g_num_persons = 0;
static int current_heap_type = 0;

void freePersonData(struct person *p) {
    if (p && p->name) {
        free(p->name);
        p->name = NULL;
    }
}

void swapPersons(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapifyAge(struct person arr[], int n, int i) {
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left].age < arr[smallest].age) smallest = left;
    if (right < n && arr[right].age < arr[smallest].age) smallest = right;
    if (smallest != i) {
        swapPersons(&arr[i], &arr[smallest]);
        minHeapifyAge(arr, n, smallest);
    }
}

void buildMinHeapAge(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) minHeapifyAge(arr, n, i);
    printf("Min-heap based on age created.\n");
    current_heap_type = 1;
}

void insertMinHeapAge(struct person arr[], int *n_ptr, struct person new_person) {
    *n_ptr += 1;
    g_persons_array = realloc(g_persons_array, (*n_ptr) * sizeof(struct person));
    if (g_persons_array == NULL) {
        printf("Memory reallocation failed!\n");
        freePersonData(&new_person);
        exit(1);
    }
    int i = *n_ptr - 1;
    g_persons_array[i] = new_person;
    while (i > 0 && g_persons_array[(i - 1) / 2].age > g_persons_array[i].age) {
        swapPersons(&g_persons_array[i], &g_persons_array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    printf("Person with ID %d inserted into the age-based min-heap.\n", new_person.id);
}

void maxHeapifyWeight(struct person arr[], int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left].weight > arr[largest].weight) largest = left;
    if (right < n && arr[right].weight > arr[largest].weight) largest = right;
    if (largest != i) {
        swapPersons(&arr[i], &arr[largest]);
        maxHeapifyWeight(arr, n, largest);
    }
}

void buildMaxHeapWeight(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) maxHeapifyWeight(arr, n, i);
    printf("Max-heap based on weight created.\n");
    current_heap_type = 2;
}

void maxHeapifyAge(struct person arr[], int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left].age > arr[largest].age) largest = left;
    if (right < n && arr[right].age > arr[largest].age) largest = right;
    if (largest != i) {
        swapPersons(&arr[i], &arr[largest]);
        maxHeapifyAge(arr, n, largest);
    }
}

void buildMaxHeapAge(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) maxHeapifyAge(arr, n, i);
}

void readData() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Number of students must be positive.\n");
        return;
    }
    if (g_persons_array != NULL) {
        for (int i = 0; i < g_num_persons; i++) freePersonData(&g_persons_array[i]);
        free(g_persons_array);
        g_persons_array = NULL;
    }
    g_persons_array = malloc(n * sizeof(struct person));
    if (g_persons_array == NULL) {
        printf("Memory allocation failed!\n");
        g_num_persons = 0;
        current_heap_type = 0;
        return;
    }
    g_num_persons = n;
    current_heap_type = 0;
    printf("Enter details for %d students:\n", n);
    printf("Id Name Age Height Weight(pound)\n");
    for (int i = 0; i < n; i++) {
        g_persons_array[i].id = i;
        char temp_name[100];
        printf("%d ", i);
        scanf("%s %d %d %d", temp_name, &g_persons_array[i].age, &g_persons_array[i].height, &g_persons_array[i].weight);
        g_persons_array[i].name = strdup(temp_name);
        if (g_persons_array[i].name == NULL) {
            printf("Memory allocation for name failed!\n");
            for (int j = 0; j <= i; j++) freePersonData(&g_persons_array[j]);
            free(g_persons_array);
            g_persons_array = NULL;
            g_num_persons = 0;
            exit(1);
        }
    }
    printf("Data read successfully.\n");
}

void displayWeightOfYoungestPerson() {
    if (g_num_persons == 0) {
        printf("No student data available.\n");
        return;
    }
    if (current_heap_type != 1) {
        printf("Min-heap based on age not active. Building now...\n");
        buildMinHeapAge(g_persons_array, g_num_persons);
    }
    double weight_kg = g_persons_array[0].weight * 0.453592;
    printf("Weight of youngest student (ID: %d, Name: %s, Age: %d): %.2f kg\n", g_persons_array[0].id, g_persons_array[0].name, g_persons_array[0].age, weight_kg);
}

void insertNewPersonIntoMinHeap() {
    if (g_num_persons == 0 || current_heap_type != 1) {
        printf("Please read data and create a Min-heap based on age first.\n");
        return;
    }
    struct person new_p;
    char temp_name[100];
    printf("Enter details for the new person:\n");
    printf("Name Age Height Weight(pound)\n");
    scanf("%s %d %d %d", temp_name, &new_p.age, &new_p.height, &new_p.weight);
    new_p.id = g_num_persons;
    new_p.name = strdup(temp_name);
    if (new_p.name == NULL) {
        printf("Memory allocation for name failed!\n");
        return;
    }
    insertMinHeapAge(g_persons_array, &g_num_persons, new_p);
    printf("New person inserted. Total persons: %d\n", g_num_persons);
}

void deleteOldestPerson() {
    if (g_num_persons == 0) {
        printf("No student data available to delete.\n");
        return;
    }
    printf("Building Max-heap on age to find and delete the oldest person...\n");
    buildMaxHeapAge(g_persons_array, g_num_persons);
    struct person oldest_person = g_persons_array[0];
    printf("Deleting oldest person found: ID %d, Name %s, Age %d\n", oldest_person.id, oldest_person.name, oldest_person.age);
    freePersonData(&oldest_person);
    g_persons_array[0] = g_persons_array[g_num_persons - 1];
    g_num_persons--;
    if (g_num_persons > 0) {
        g_persons_array = realloc(g_persons_array, g_num_persons * sizeof(struct person));
        if (g_persons_array == NULL) {
            printf("Memory reallocation failed after deletion! Program might be unstable.\n");
            exit(1);
        }
        maxHeapifyAge(g_persons_array, g_num_persons, 0);
        printf("Max-heap rebuilt. Total persons: %d\n", g_num_persons);
    } else {
        free(g_persons_array);
        g_persons_array = NULL;
        printf("Last person deleted. Array is now empty.\n");
        current_heap_type = 0;
    }
}

int main() {
    int choice;
    do {
        printf("\n--- MAIN MENU (HEAP) ---\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: readData(); break;
            case 2:
                if (g_num_persons == 0) printf("No data to create heap.\n");
                else buildMinHeapAge(g_persons_array, g_num_persons);
                break;
            case 3:
                if (g_num_persons == 0) printf("No data to create heap.\n");
                else buildMaxHeapWeight(g_persons_array, g_num_persons);
                break;
            case 4: displayWeightOfYoungestPerson(); break;
            case 5: insertNewPersonIntoMinHeap(); break;
            case 6: deleteOldestPerson(); break;
            case 7:
                printf("Exiting program. Freeing memory.\n");
                if (g_persons_array != NULL) {
                    for (int i = 0; i < g_num_persons; i++) freePersonData(&g_persons_array[i]);
                    free(g_persons_array);
                    g_persons_array = NULL;
                }
                break;
            default: printf("Invalid option. Try again.\n");
        }
    } while (choice != 7);
    return 0;
}
/*
Sample Input/Output:
MAIN MENU (HEAP)
1. Read Data
2. Create a Min-heap based on the age
3. Create a Max-heap based on the weight
4. Display weight of the youngest person
5. Insert a new person into the Min-heap
6. Delete the oldest person
7. Exit
Enter option: 1
Id Name Age Height Weight(pound)
0 Adarsh Hota 39 77 231
1 Levi Maier 56 77 129
2 Priya Kumari 63 78 240
3 Dorothy Helton 47 72 229
4 Florence Smith 24 75 171
5 Erica Anyan 38 73 102
6 Norma Webster 23 75 145
Enter option: 4
Weight of youngest student: 65.77 kg
*/
