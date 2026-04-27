#include <stdio.h>

/* Sort an array using counting sort. */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000];
    int maxv = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > maxv) {
            maxv = arr[i];
        }
    }

    int count[10000] = {0};
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int first = 1;
    for (int v = 0; v <= maxv; v++) {
        while (count[v]--) {
            if (!first) {
                printf(" ");
            }
            printf("%d", v);
            first = 0;
        }
    }

    return 0; /* success */
}
