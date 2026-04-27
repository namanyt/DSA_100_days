#include <stdio.h>

/* Check if boards can be painted within max_time. */
static int can_paint(int arr[], int n, int k, int max_time) {
    int painters = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_time) {
            return 0; /* single board too large */
        }
        if (sum + arr[i] > max_time) {
            painters++;
            sum = arr[i];
        } else {
            sum += arr[i];
        }
    }
    return painters <= k;
}

/* Minimize maximum time to paint all boards. */
int main() {
    int n, k; /* number of boards and painters */
    if (scanf("%d %d", &n, &k) != 2) {
        return 0; /* no valid input */
    }

    int arr[2000];
    int total = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        total += arr[i];
    }

    int l = 0, r = total, ans = total;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (can_paint(arr, n, k, mid)) {
            ans = mid; /* feasible */
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    printf("%d", ans);
    return 0; /* success */
}
