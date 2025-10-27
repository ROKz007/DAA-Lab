#include <stdio.h>
#include <stdlib.h>
/*
Aim of the program: Given an undirected weighted connected graph G(V, E). Apply
Krushkal’s algorithm to
● Find the minimum spanning tree T(V, E’) and Display the selected edges of G.
● Display total cost of the minimum spanning tree T.
*/
typedef struct {
    int u, v, w;
} Edge;

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void union_set(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int cmp(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Edge *edges = (Edge*)malloc(m * sizeof(Edge));
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    qsort(edges, m, sizeof(Edge), cmp);

    int *parent = (int*)malloc((n+1) * sizeof(int));
    int *rank = (int*)calloc(n+1, sizeof(int));
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    printf("Edge Cost\n");
    int total = 0, count = 0;
    for (int i = 0; i < m && count < n-1; i++) {
        int u = edges[i].u, v = edges[i].v;
        int set_u = find(parent, u);
        int set_v = find(parent, v);
        if (set_u != set_v) {
            printf("%d--%d %d\n", u, v, edges[i].w);
            total += edges[i].w;
            union_set(parent, rank, set_u, set_v);
            count++;
        }
    }
    printf("Total Weight of the Spanning Tree: %d\n", total);

    free(edges);
    free(parent);
    free(rank);
    return 0;
}