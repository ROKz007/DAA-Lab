#include <stdio.h>
#include <stdlib.h>
/*
Aim of the program: Huffman coding assigns variable length code words to fixed length
input characters based on their frequencies or probabilities of occurrence. Given a set of
characters along with their frequency of occurrences, write a c program to construct a Huffman
tree.
Note#
● Declare a structure SYMBOL having members alphabet and frequency. Create a MinPriority Queue, keyed on frequency attributes.
● Create an array of structures where size=number of alphabets.
*/
typedef struct {
    char alphabet;
    int frequency;
} SYMBOL;

typedef struct MinHeapNode {
    char alphabet;
    int frequency;
    struct MinHeapNode *left, *right;
} MinHeapNode;

typedef struct {
    int size;
    int capacity;
    MinHeapNode** array;
} MinPriorityQueue;

MinHeapNode* newMinHeapNode(char alphabet, int frequency) {
    MinHeapNode* temp = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    if (temp == NULL) {
        perror("Memory allocation failed for MinHeapNode");
        exit(1);
    }
    temp->alphabet = alphabet;
    temp->frequency = frequency;
    temp->left = temp->right = NULL;
    return temp;
}

MinPriorityQueue* createMinPriorityQueue(int capacity) {
    MinPriorityQueue* minPQ = (MinPriorityQueue*)malloc(sizeof(MinPriorityQueue));
    if (minPQ == NULL) {
        perror("Memory allocation failed for MinPriorityQueue");
        exit(1);
    }
    minPQ->size = 0;
    minPQ->capacity = capacity;
    minPQ->array = (MinHeapNode**)malloc(minPQ->capacity * sizeof(MinHeapNode*));
    if (minPQ->array == NULL) {
        perror("Memory allocation failed for minPQ array");
        exit(1);
    }
    return minPQ;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinPriorityQueue* minPQ, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minPQ->size && minPQ->array[left]->frequency < minPQ->array[smallest]->frequency) {
        smallest = left;
    }

    if (right < minPQ->size && minPQ->array[right]->frequency < minPQ->array[smallest]->frequency) {
        smallest = right;
    }

    if (smallest != idx) {
        swapMinHeapNode(&minPQ->array[smallest], &minPQ->array[idx]);
        minHeapify(minPQ, smallest);
    }
}

int isSizeOne(MinPriorityQueue* minPQ) {
    return (minPQ->size == 1);
}

MinHeapNode* extractMin(MinPriorityQueue* minPQ) {
    MinHeapNode* temp = minPQ->array[0];
    minPQ->array[0] = minPQ->array[minPQ->size - 1];
    --minPQ->size;
    minHeapify(minPQ, 0);
    return temp;
}

void insertMinHeap(MinPriorityQueue* minPQ, MinHeapNode* minHeapNode) {
    ++minPQ->size;
    int i = minPQ->size - 1;
    while (i > 0 && minHeapNode->frequency < minPQ->array[(i - 1) / 2]->frequency) {
        minPQ->array[i] = minPQ->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minPQ->array[i] = minHeapNode;
}

void buildMinHeap(MinPriorityQueue* minPQ) {
    int n = minPQ->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minPQ, i);
    }
}

MinHeapNode* buildHuffmanTree(SYMBOL symbols[], int n) {
    MinHeapNode *left, *right, *top;

    MinPriorityQueue* minPQ = createMinPriorityQueue(n);
    for (int i = 0; i < n; ++i) {
        insertMinHeap(minPQ, newMinHeapNode(symbols[i].alphabet, symbols[i].frequency));
    }

    buildMinHeap(minPQ);

    while (!isSizeOne(minPQ)) {
        left = extractMin(minPQ);
        right = extractMin(minPQ);

        top = newMinHeapNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minPQ, top);
    }

    return extractMin(minPQ);
}

void inorderTraversal(MinHeapNode* root) {
    if (root) {
        inorderTraversal(root->left);
        if (root->alphabet != '$') {
            printf("%c ", root->alphabet);
        }
        inorderTraversal(root->right);
    }
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);
    getchar();

    SYMBOL* symbols = (SYMBOL*)malloc(n * sizeof(SYMBOL));
    if (symbols == NULL) {
        perror("Memory allocation failed for symbols array");
        return 1;
    }

    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &symbols[i].alphabet);
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &symbols[i].frequency);
    }

    MinHeapNode* root = buildHuffmanTree(symbols, n);

    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);
    printf("\n");

    free(symbols);

    return 0;
}
/*
Input:
Enter the number of distinct alphabets: 6
Enter the alphabets: a b c d e f
Enter its frequencies: 45 13 12 16 9 5
Output:
In-order traversal of the tree (Huffman): a c b f e d
*/