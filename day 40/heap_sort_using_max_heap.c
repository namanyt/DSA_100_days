#include <stdio.h>

/* Heapify subtree rooted at i in a max-heap. */
static void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapify(arr, n, largest);
    }
}

/* Perform heap sort using a max-heap. */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000]; /* array to sort */
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); /* read elements */
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i); /* build max-heap */
    }
    for (int i = n - 1; i > 0; i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t; /* move max to end */
        heapify(arr, i, 0); /* restore heap */
    }

    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", arr[i]); /* output sorted array */
    }
    return 0; /* success */
}
