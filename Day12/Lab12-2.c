#include <stdio.h>
#include <string.h>
/*
Aim of the program: Write a program to find out the Longest Common Subsequence of two given strings. Calculate length of the LCS.
*/
#define MAX 100

void findLCS(char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[MAX][MAX];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    int lcs_len = dp[m][n];

    char lcs[MAX];
    int i = m, j = n, k = lcs_len;
    lcs[k] = '\0';
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[k - 1] = X[i - 1];
            i--; j--; k--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS: %s\n", lcs);
    printf("LCS Length: %d\n", lcs_len);
}

int main() {
    char X[MAX], Y[MAX];

    printf("Enter the first string into an array: ");
    scanf("%s", X);

    printf("Enter the second string into an array: ");
    scanf("%s", Y);

    findLCS(X, Y);

    return 0;
}