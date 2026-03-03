#include <stdio.h>

/* Read values and print them in insertion order. */
int main() {
    int n; /* number of nodes */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x); /* read node value */
        if (i) {
            printf(" ");
        }
        printf("%d", x); /* output traversal */
    }
    return 0; /* success */
}
