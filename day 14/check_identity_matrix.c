#include <stdio.h>

/* Check whether a square matrix is an identity matrix. */
int main() {
    int n; /* matrix size */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int a[50][50]; /* matrix */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]); /* read elements */
        }
    }

    int ok = 1; /* identity flag */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && a[i][j] != 1) {
                ok = 0; /* diagonal must be 1 */
            }
            if (i != j && a[i][j] != 0) {
                ok = 0; /* non-diagonal must be 0 */
            }
        }
    }

    printf(ok ? "Identity Matrix" : "Not an Identity Matrix");
    return 0; /* success */
}
