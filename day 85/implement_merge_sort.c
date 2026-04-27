#include <stdio.h>

/* Merge two sorted halves of arr[l..m] and arr[m+1..r]. */
static void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[2000], R[2000];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

/* Merge sort recursion. */
static void merge_sort(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
}

/* Read array, sort it using merge sort, and print. */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", arr[i]);
    }
    return 0; /* success */
}
