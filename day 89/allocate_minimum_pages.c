#include <stdio.h>

/* Check if pages can be allocated with max_pages per student. */
static int can_allocate(int arr[], int n, int m, int max_pages) {
    int students = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_pages) {
            return 0; /* single book too large */
        }
        if (sum + arr[i] > max_pages) {
            students++;
            sum = arr[i];
        } else {
            sum += arr[i];
        }
    }
    return students <= m;
}

/* Minimize the maximum pages assigned to a student. */
int main() {
    int n, m; /* number of books and students */
    if (scanf("%d %d", &n, &m) != 2) {
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
        if (can_allocate(arr, n, m, mid)) {
            ans = mid; /* feasible */
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    printf("%d", ans);
    return 0; /* success */
}
