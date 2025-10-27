#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
/*
Aim of the program: Write a program to implement the matrix chain multiplication problem
using M-table &amp; S-table to find optimal parenthesization of a matrix-chain product. Print the
number of scalar multiplications required for the given input.
*/
void printOptimalParens(int **s, int i, int j) {
    if (i == j) {
        printf("A%d", i + 1);
    } else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printf(" ");
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int *p = (int *)malloc((n + 1) * sizeof(int));
    int rows, cols;

    // Input dimensions and validate compatibility
    for (int i = 0; i < n; i++) {
        printf("Enter row and col size of A%d: ", i + 1);
        scanf("%d %d", &rows, &cols);
        if (i == 0) {
            p[0] = rows;
        } else if (p[i] != rows) {
            printf("Incompatible dimensions between A%d and A%d\n", i, i + 1);
            free(p);
            return 1;
        }
        p[i + 1] = cols;
    }

    // Allocate M and S tables
    int **m = (int **)malloc(n * sizeof(int *));
    int **s = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        m[i] = (int *)malloc(n * sizeof(int));
        s[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }

    // Matrix chain multiplication DP
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Print M Table
    printf("M Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i)
                printf("0 ");
            else
                printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    // Print S Table
    printf("S Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i)
                printf("0 ");
            else
                printf("%d ", s[i][j] + 1); // +1 for 1-based index in output
        }
        printf("\n");
    }

    // Print optimal parenthesization
    printf("Optimal parenthesization: ");
    printOptimalParens(s, 0, n - 1);
    printf("\n");

    printf("The optimal ordering of the given matrices requires %d scalar multiplications.\n", m[0][n - 1]);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(m[i]);
        free(s[i]);
    }
    free(m);
    free(s);
    free(p);

    return 0;
}