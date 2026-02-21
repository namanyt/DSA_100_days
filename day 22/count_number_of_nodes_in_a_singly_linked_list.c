#include <stdio.h>

/* Count the number of nodes (values) provided. */
int main() {
    int n; /* number of nodes */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    /* Consume n integers (node data). */
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
    }

    printf("%d", n); /* count is n */
    return 0; /* success */
}
