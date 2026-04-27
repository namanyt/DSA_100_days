#include <stdio.h>

/* Merge two sorted halves and count inversions. */
static long long merge_count(int arr[], int temp[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    long long inv = 0;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv += (m - i + 1); /* count inversions */
        }
    }
    while (i <= m) {
        temp[k++] = arr[i++];
    }
    while (j <= r) {
        temp[k++] = arr[j++];
    }
    for (int t = l; t <= r; t++) {
        arr[t] = temp[t];
    }
    return inv;
}

/* Divide and count inversions using merge sort. */
static long long sort_count(int arr[], int temp[], int l, int r) {
    if (l >= r) {
        return 0;
    }
    int m = (l + r) / 2;
    long long inv = 0;
    inv += sort_count(arr, temp, l, m);
    inv += sort_count(arr, temp, m + 1, r);
    inv += merge_count(arr, temp, l, m, r);
    return inv;
}

/* Count inversions in an array. */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000];
    int temp[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long inv = sort_count(arr, temp, 0, n - 1);
    printf("%lld", inv);
    return 0; /* success */
}
