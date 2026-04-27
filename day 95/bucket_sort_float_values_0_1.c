#include <stdio.h>
#include <stdlib.h>

/* Compare floats for qsort. */
static int cmp_float(const void *a, const void *b) {
    float x = *(const float *)a;
    float y = *(const float *)b;
    return (x > y) - (x < y);
}

/* Bucket sort for floating values in [0, 1]. */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    float arr[2000];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    /* Use n buckets; store values in fixed arrays for simplicity. */
    float buckets[2000][2000];
    int size[2000] = {0};

    for (int i = 0; i < n; i++) {
        int idx = (int)(arr[i] * n); /* bucket index */
        if (idx < 0) {
            idx = 0;
        }
        if (idx >= n) {
            idx = n - 1;
        }
        buckets[idx][size[idx]++] = arr[i];
    }

    int first = 1;
    for (int i = 0; i < n; i++) {
        if (size[i] > 0) {
            qsort(buckets[i], size[i], sizeof(float), cmp_float);
            for (int j = 0; j < size[i]; j++) {
                if (!first) {
                    printf(" ");
                }
                printf("%.2f", buckets[i][j]);
                first = 0;
            }
        }
    }

    return 0; /* success */
}
