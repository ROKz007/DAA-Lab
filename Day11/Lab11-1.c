#include <stdio.h>
#include <stdlib.h>
#define INF 9999
/*
Aim of the program: Given a directed graph G (V, E) and a starting vertex ‘s’.
● Determine the lengths of the shortest paths from the starting vertex ‘s’ to all other
vertices in the graph G using Dijkstra’s Algorithm.
● Display the shortest path from the given source ‘s’ to all other vertices.
*/
void dijkstra(int n, int source, int cost[10][10]) {
    int dist[10], visited[10], parent[10];
    int i, j, count, nextnode, mindistance;

    for (i = 0; i < n; i++) {
        dist[i] = cost[source][i];
        parent[i] = source;
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;
    count = 1;

    while (count < n - 1) {
        mindistance = INF;

        for (i = 0; i < n; i++)
            if (dist[i] < mindistance && !visited[i]) {
                mindistance = dist[i];
                nextnode = i;
            }

        visited[nextnode] = 1;

        for (i = 0; i < n; i++)
            if (!visited[i] && mindistance + cost[nextnode][i] < dist[i]) {
                dist[i] = mindistance + cost[nextnode][i];
                parent[i] = nextnode;
            }

        count++;
    }

    printf("\nSource\tDestination\tCost\tPath");
    for (i = 0; i < n; i++) {
        if (i != source) {
            printf("\n%d\t%d\t\t%d\t", source + 1, i + 1, dist[i]);
            int path[10];
            int path_index = 0;
            j = i;
            while (j != source) {
                path[path_index] = j;
                path_index++;
                j = parent[j];
            }
            printf("%d", source + 1);
            for (j = path_index - 1; j >= 0; j--) {
                printf("->%d", path[j] + 1);
            }
        } else {
            printf("\n%d\t%d\t\t%d\t-", source + 1, i + 1, dist[i]);
        }
    }
    printf("\n");
}

int main() {
    int n, source;
    int cost[10][10];
    int i, j;

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 0 for no direct path):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = INF;
            }
        }
    }

    printf("Enter the Source Vertex (1 to %d): ", n);
    scanf("%d", &source);
    source--;

    dijkstra(n, source, cost);

    return 0;
}
