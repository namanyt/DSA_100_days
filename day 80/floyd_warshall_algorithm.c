#include <stdio.h>
#include <limits.h>

/* Floyd-Warshall all-pairs shortest paths. */
int main() {
    int n; /* number of vertices */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    long long dist[200][200];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            if (x == -1 && i != j) {
                dist[i][j] = LLONG_MAX / 4; /* represent infinity */
            } else {
                dist[i][j] = x;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j) {
                printf(" ");
            }
            if (dist[i][j] >= LLONG_MAX / 8) {
                printf("-1");
            } else {
                printf("%lld", dist[i][j]);
            }
        }
        if (i < n - 1) {
            printf("\n");
        }
    }

    return 0; /* success */
}
