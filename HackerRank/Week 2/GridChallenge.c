#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

char* gridChallenge(int n, char grid[n][n+1]) {
    // Step 1: Sort each row alphabetically
    for (int i = 0; i < n; i++) {
        qsort(grid[i], n, sizeof(char), cmpfunc);
    }

    // Step 2: Check column-wise order
    for (int col = 0; col < n; col++) {
        for (int row = 1; row < n; row++) {
            if (grid[row][col] < grid[row-1][col]) {
                return "NO";
            }
        }
    }

    return "YES";
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        char grid[n][n+1];  // +1 for null terminator
        for (int i = 0; i < n; i++) {
            scanf("%s", grid[i]);
        }

        printf("%s\n", gridChallenge(n, grid));
    }

    return 0;
}
