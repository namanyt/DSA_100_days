#include <stdio.h>

/* Find the intersection point by comparing suffix values. */
int main() {
    int n, m; /* lengths of lists */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int a[2000], b[2000]; /* list values */
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); /* read list A */
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]); /* read list B */
    }

    /* Find common suffix to simulate intersection. */
    int i = n - 1, j = m - 1; /* tail pointers */
    int last_common = -1;     /* intersection value */
    while (i >= 0 && j >= 0 && a[i] == b[j]) {
        last_common = a[i]; /* update last common value */
        i--;
        j--;
    }

    if (last_common == -1) {
        printf("No Intersection");
    } else {
        printf("%d", last_common);
    }
    return 0; /* success */
}
