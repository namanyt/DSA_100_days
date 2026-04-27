#include <stdio.h>

/* Sort an array using insertion sort. */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; /* shift right */
            j--;
        }
        arr[j + 1] = key; /* insert key */
    }

    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", arr[i]);
    }
    return 0; /* success */
}
