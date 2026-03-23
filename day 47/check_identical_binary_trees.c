#include <stdio.h>

/* Check if two level-order arrays represent identical trees. */
int main() {
    int n, m; /* sizes of both arrays */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int a[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); /* read first tree array */
    }

    scanf("%d", &m);
    int b[2000];
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]); /* read second tree array */
    }

    if (n != m) {
        printf("NO");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0; /* success */
}
