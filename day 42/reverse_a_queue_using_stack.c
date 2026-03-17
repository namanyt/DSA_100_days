#include <stdio.h>

/* Reverse a queue by using a stack (array). */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no input */
    }

    int stack[2000]; /* stack storage */
    for (int i = 0; i < n; i++) {
        scanf("%d", &stack[i]); /* enqueue values, push onto stack */
    }

    /* Pop from stack to print reversed queue. */
    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1) {
            printf(" ");
        }
        printf("%d", stack[i]);
    }

    return 0; /* success */
}
