#include <stdio.h>

/* Merge two sorted arrival logs into one chronological log. */
int main() {
    int p, q; /* sizes of the two logs */
    if (scanf("%d", &p) != 1) {
        return 0; /* no valid input */
    }

    int a[2000], b[2000]; /* arrays for the two logs */
    for (int i = 0; i < p; i++) {
        scanf("%d", &a[i]); /* read log 1 */
    }
    scanf("%d", &q); /* read size of log 2 */
    for (int i = 0; i < q; i++) {
        scanf("%d", &b[i]); /* read log 2 */
    }

    int i = 0, j = 0; /* merge pointers */
    int first = 1;    /* output spacing flag */
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            if (!first) {
                printf(" ");
            }
            printf("%d", a[i++]); /* take from log 1 */
        } else {
            if (!first) {
                printf(" ");
            }
            printf("%d", b[j++]); /* take from log 2 */
        }
        first = 0;
    }

    while (i < p) {
        if (!first) {
            printf(" ");
        }
        printf("%d", a[i++]); /* remaining from log 1 */
        first = 0;
    }
    while (j < q) {
        if (!first) {
            printf(" ");
        }
        printf("%d", b[j++]); /* remaining from log 2 */
        first = 0;
    }
    return 0; /* success */
}
