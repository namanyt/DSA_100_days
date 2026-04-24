#include <stdio.h>

/* First index where arr[i] >= x. */
static int lower_bound(int arr[], int n, int x) {
    int l = 0, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (arr[m] < x) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

/* First index where arr[i] > x. */
static int upper_bound(int arr[], int n, int x) {
    int l = 0, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (arr[m] <= x) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

/* Read array and print lower/upper bound indices. */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    scanf("%d", &x);

    printf("%d %d", lower_bound(arr, n, x), upper_bound(arr, n, x));
    return 0; /* success */
}
