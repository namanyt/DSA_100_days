#include <stdio.h>
#include <limits.h>

/* Compute MST total weight using Prim's algorithm. */
int main() {
    int n, m; /* vertices and edges */
    if (scanf("%d %d", &n, &m) != 2) {
        return 0; /* no valid input */
    }

    int w[200][200];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            w[i][j] = INT_MAX; /* no edge initially */
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, wt;
        scanf("%d %d %d", &u, &v, &wt);
        u--; /* convert to 0-based */
        v--;
        if (wt < w[u][v]) {
            w[u][v] = w[v][u] = wt; /* keep minimum weight edge */
        }
    }

    int key[200];
    int in_mst[200] = {0};
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
    }
    key[0] = 0; /* start from node 0 */

    int total = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!in_mst[v] && (u == -1 || key[v] < key[u])) {
                u = v; /* pick closest non-MST vertex */
            }
        }
        in_mst[u] = 1;
        if (key[u] != INT_MAX) {
            total += key[u];
        }
        for (int v = 0; v < n; v++) {
            if (!in_mst[v] && w[u][v] < key[v]) {
                key[v] = w[u][v];
            }
        }
    }

    printf("%d", total);
    return 0; /* success */
}
