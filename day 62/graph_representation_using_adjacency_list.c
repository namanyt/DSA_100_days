#include <stdio.h>

/* Build and print adjacency list (directed). */
int main() {
    int n, m; /* vertices and edges */
    if (scanf("%d %d", &n, &m) != 2) {
        return 0; /* no valid input */
    }

    int adj[200][200];
    int deg[200] = {0}; /* out-degree for each vertex */

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; /* convert to 0-based */
        v--;
        adj[u][deg[u]++] = v + 1; /* store 1-based for output */
    }

    for (int i = 0; i < n; i++) {
        printf("%d ->", i + 1);
        for (int j = 0; j < deg[i]; j++) {
            printf(" %d", adj[i][j]);
        }
        if (i < n - 1) {
            printf("\n");
        }
    }

    return 0; /* success */
}
