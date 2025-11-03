#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*
Aim of the program: Given a directed weighted graph G (V, E) where weight indicates
distance. Vertices will be numbered consecutively from 1 to n (user input), and edges will have
varying distances or lengths.
● Determine the length of the shortest path between every pair of vertices using FloydWarshall’s algorithm.
● Display the intermediate vertices on the shortest-path from the given pair of vertices
(u,v). 
*/
#define INF 99999

void printPath(int s, int d, int** next, int n) {
    if (next[s][d] == -1) {
        printf("No path exists");
        return;
    }

    int* path = (int*)malloc(n * sizeof(int));
    if (path == NULL) {
        printf("Error: Memory allocation failed for path.\n");
        return;
    }
    
    int path_len = 0;
    int curr = s;

    while (curr != d) {
        if (curr == -1) {
            printf("Error in path reconstruction");
            free(path);
            return;
        }
        path[path_len++] = curr;
        curr = next[curr][d];
    }
    path[path_len++] = d;

    for (int i = 0; i < path_len; ++i) {
        printf("%d", path[i] + 1);
        if (i < path_len - 1) {
            printf("-->");
        }
    }
    
    free(path);
}

void printMatrix(int** dist, int n) {
    printf("      ");
    for(int i = 0; i < n; ++i) {
        printf("%5d", i + 1);
    }
    printf("\n-----------------------------\n");

    for (int i = 0; i < n; ++i) {
        printf("%3d | ", i + 1);
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                printf("%5s", "INF");
            } else {
                printf("%5d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int** dist = (int**)malloc(n * sizeof(int*));
    int** next = (int**)malloc(n * sizeof(int*));
    
    if (dist == NULL || next == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        dist[i] = (int*)malloc(n * sizeof(int));
        next[i] = (int*)malloc(n * sizeof(int));
        if (dist[i] == NULL || next[i] == NULL) {
            printf("Error: Memory allocation failed for row %d.\n", i);
            return 1;
        }
    }
    
    printf("Enter the cost adjacency matrix (%dx%d):\n", n, n);
    printf("(Use 0 for no direct path between different vertices, as in the example)\n");

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int weight;
            scanf("%d", &weight);

            if (i == j) {
                dist[i][j] = 0;
                next[i][j] = i;
            } else if (weight != 0) {
                dist[i][j] = weight;
                next[i][j] = j;
            } else {
                dist[i][j] = INF;
                next[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j]) 
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    printf("\nShortest-path weight matrix:\n");
    printMatrix(dist, n);
    
    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < 0) {
            printf("\nWarning: Negative cycle detected!\n");
            break;
        }
    }

    while (1) {
        printf("\nEnter the source and destination vertex (1 to %d) (or 0 0 to quit): ", n);
        int source, dest;
        scanf("%d %d", &source, &dest);

        if (source == 0 || dest == 0) {
            break;
        }

        int s_idx = source - 1;
        int d_idx = dest - 1;

        if (s_idx < 0 || s_idx >= n || d_idx < 0 || d_idx >= n) {
            printf("Invalid vertex number. Please enter values between 1 and %d.\n", n);
        } else {
            printf("Shortest Path from vertex %d to vertex %d: ", source, dest);
            printPath(s_idx, d_idx, next, n);
            printf("\n");

            printf("Path weight: ");
            if (dist[s_idx][d_idx] == INF) {
                printf("No Path\n");
            } else {
                printf("%d\n", dist[s_idx][d_idx]);
            }
        }
    }

    freeMatrix(dist, n);
    freeMatrix(next, n);

    return 0;
}