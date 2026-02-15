#include <stdio.h>

/* Sum the primary diagonal of a matrix. */
int main() {
    int m, n; /* rows and columns */
    if (scanf("%d %d", &m, &n) != 2) {
        return 0; /* no valid input */
    }

    int sum = 0; /* diagonal sum */
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val); /* read element */
            if (i == j) {
                sum += val; /* primary diagonal */
            }
        }
    }

    printf("%d", sum); /* output sum */
    return 0; /* success */
}
