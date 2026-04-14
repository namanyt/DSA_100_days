#include <stdio.h>

/* Validate a min-heap stored in an array (-1 as null). */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int vals[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &vals[i]);
    }

    if (n == 0) {
        printf("YES"); /* empty heap is valid */
        return 0;
    }

    /* Check completeness: after a -1, no non -1 should appear. */
    int seen_null = 0;
    for (int i = 0; i < n; i++) {
        if (vals[i] == -1) {
            seen_null = 1;
        } else if (seen_null) {
            printf("NO");
            return 0;
        }
    }

    /* Check min-heap property in array representation. */
    for (int i = 0; i < n; i++) {
        if (vals[i] == -1) {
            continue;
        }
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && vals[l] != -1 && vals[i] > vals[l]) {
            printf("NO");
            return 0;
        }
        if (r < n && vals[r] != -1 && vals[i] > vals[r]) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0; /* success */
}
