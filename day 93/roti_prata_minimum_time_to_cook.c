#include <stdio.h>

/* Check if p pratas can be cooked within given time. */
static int can_make(int ranks[], int l, int p, int time) {
    int count = 0;
    for (int i = 0; i < l; i++) {
        int r = ranks[i];
        int t = 0;
        int k = 1;
        while (t + k * r <= time) {
            t += k * r;
            count++;
            k++;
            if (count >= p) {
                return 1;
            }
        }
    }
    return count >= p;
}

/* Binary search on time to cook pratas. */
int main() {
    int t; /* test cases */
    if (scanf("%d", &t) != 1) {
        return 0; /* no valid input */
    }

    while (t--) {
        int p;
        scanf("%d", &p);
        int l;
        scanf("%d", &l);
        int ranks[100];
        for (int i = 0; i < l; i++) {
            scanf("%d", &ranks[i]);
        }

        int low = 0, high = 1000000, ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (can_make(ranks, l, p, mid)) {
                ans = mid; /* feasible time */
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        printf("%d", ans);
        if (t) {
            printf("\n");
        }
    }

    return 0; /* success */
}
