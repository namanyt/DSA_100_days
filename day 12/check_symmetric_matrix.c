#include <stdio.h>

/* Check whether a matrix is symmetric. */
int main() {
    int m, n; /* rows and columns */
    if (scanf("%d %d", &m, &n) != 2) {
        return 0; /* no valid input */
    }

    int a[50][50]; /* matrix */
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]); /* read elements */
        }
    }

    if (m != n) {
        printf("Not a Symmetric Matrix"); /* must be square */
        return 0;
    }

    int ok = 1; /* symmetry flag */
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                ok = 0; /* mismatch found */
                break;
            }
        }
        if (!ok) {
            break;
        }
    }

    printf(ok ? "Symmetric Matrix" : "Not a Symmetric Matrix");
    return 0; /* success */
}
