#include <stdio.h>
#include <stdlib.h>

/* Search in a step array (adjacent difference bounded by k). */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k, x;
    scanf("%d %d", &k, &x);

    int i = 0;
    while (i < n) {
        if (arr[i] == x) {
            printf("%d", i);
            return 0;
        }
        int step = abs(arr[i] - x) / k; /* jump size */
        if (step < 1) {
            step = 1;
        }
        i += step;
    }

    printf("-1");
    return 0; /* success */
}
