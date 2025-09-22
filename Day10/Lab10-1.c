#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100 // Max number of vertices.
/*
Aim of the program: Given an undirected weighted connected graph G(V, E) and starring vertex
 ‘s’. Maintain a Min-Priority Queue ‘Q’ from the vertex set V and apply Prim’s algorithm to
    ● Find the minimum spanning tree T(V, E’). Display the cost adjacency matrix of ‘T’.
    ● Display total cost of the minimum spanning tree T.
Note# Nodes will be numbered consecutively from 1 to n (user input), and edges will have
varying weight. The graph G can be read from an input that contains cost adjacency matrix. 
The expected output could be displayed as the cost adjacency matrix of the minimum spanning tree 
and total cost of the tree.
*/
// Find vertex with minimum key value.
int minKey(int n, int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Print the constructed MST and total cost.
void printMST(int n, int parent[], int graph[][MAX_VERTICES]) {
    printf("\nCost Adjacency Matrix of the Minimum Spanning Tree:\n");
    int mst_matrix[MAX_VERTICES][MAX_VERTICES] = {0};
    int total_cost = 0;

    for (int i = 1; i < n; i++) {
        int u = parent[i];
        int v = i;
        int weight = graph[u][v];
        
        mst_matrix[u][v] = weight; // Add edge to MST matrix.
        mst_matrix[v][u] = weight;
        
        total_cost += weight;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mst_matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nTotal Weight of the Spanning Tree: %d\n", total_cost);
}

// Implement Prim's algorithm.
void primMST(int n, int graph[][MAX_VERTICES], int start_vertex) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    int start_node_index = start_vertex - 1;
    key[start_node_index] = 0;
    parent[start_node_index] = -1;

    for (int count = 0; count < n; count++) {
        int u = minKey(n, key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(n, parent, graph);
}

// Main function.
int main() {
    int n, start_vertex;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_VERTICES) {
        printf("Invalid number of vertices. Please enter a value between 1 and %d.\n", MAX_VERTICES);
        return 1;
    }

    printf("Enter the Starting Vertex: ");
    scanf("%d", &start_vertex);

    if (start_vertex < 1 || start_vertex > n) {
        printf("Invalid starting vertex. Please enter a value between 1 and %d.\n", n);
        return 1;
    }
    
    printf("Enter the cost adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    // Check if the graph is undirected.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != graph[j][i]) {
                printf("Error: The input matrix is not symmetric (undirected).\n");
                return 1;
            }
        }
    }

    primMST(n, graph, start_vertex);

    return 0;
}
/*
Sample Input:
Enter the Number of Vertices: 9
Enter the Starting Vertex: 1
Enter the cost adjacency Matrix:
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0 
Output:
0 4 0 0 0 0 0 8 0
4 0 0 0 0 0 0 0 0
0 0 0 7 0 4 0 0 2
0 0 7 0 9 0 0 0 0
0 0 0 9 0 0 0 0 0
0 0 4 0 0 0 2 0 0
0 0 0 0 0 2 0 1 0
8 0 0 0 0 0 1 0 0
0 0 2 0 0 0 0 0 0
Total Weight of the Spanning Tree: 37
*/