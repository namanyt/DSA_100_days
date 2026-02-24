#include <stdio.h>

/* Merge two sorted sequences and print the result. */
int main() {
    int n, m; /* sizes of both lists */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int a[2000], b[2000]; /* arrays to store values */
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); /* read list A */
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]); /* read list B */
    }

    int i = 0, j = 0; /* merge pointers */
    int first = 1;    /* spacing flag */

    while (i < n && j < m) {
        int v = (a[i] <= b[j]) ? a[i++] : b[j++]; /* pick smaller */
        if (!first) {
            printf(" ");
        }
        printf("%d", v);
        first = 0;
    }

    while (i < n) {
        if (!first) {
            printf(" ");
        }
        printf("%d", a[i++]); /* remaining from A */
        first = 0;
    }

    while (j < m) {
        if (!first) {
            printf(" ");
        }
        printf("%d", b[j++]); /* remaining from B */
        first = 0;
    }
    return 0; /* success */
}
