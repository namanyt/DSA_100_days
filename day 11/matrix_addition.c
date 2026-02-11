#include <stdio.h>

/* Add two matrices of the same dimensions. */
int main() {
    int m, n; /* rows and columns */
    if (scanf("%d %d", &m, &n) != 2) {
        return 0; /* no valid input */
    }

    int a[50][50], b[50][50]; /* matrices */
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]); /* read matrix A */
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]); /* read matrix B */
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j) {
                printf(" "); /* space between elements */
            }
            printf("%d", a[i][j] + b[i][j]); /* element-wise sum */
        }
        if (i < m - 1) {
            printf("\n"); /* new row */
        }
    }
    return 0; /* success */
}
