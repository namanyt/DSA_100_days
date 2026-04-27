#include <stdio.h>

/* Find index of any peak element. */
int main() {
    int n; /* number of elements */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    int arr[2000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int left = (i == 0) ? -2147483648 : arr[i - 1];
        int right = (i == n - 1) ? -2147483648 : arr[i + 1];
        if (arr[i] > left && arr[i] > right) {
            printf("%d", i);
            return 0;
        }
    }

    printf("-1");
    return 0; /* success */
}
