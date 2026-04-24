#include <stdio.h>
#include <limits.h>

/* Dijkstra's algorithm using adjacency matrix (O(n^2)). */
int main() {
    int n, m; /* vertices and edges */
    if (scanf("%d %d", &n, &m) != 2) {
        return 0; /* no valid input */
    }

    int w[200][200];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            w[i][j] = INT_MAX; /* no edge */
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, wt;
        scanf("%d %d %d", &u, &v, &wt);
        u--; /* convert to 0-based */
        v--;
        if (wt < w[u][v]) {
            w[u][v] = w[v][u] = wt; /* keep minimum weight */
        }
    }

    int src;
    scanf("%d", &src);
    src--; /* convert to 0-based */

    int dist[200];
    int used[200] = {0};
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!used[v] && (u == -1 || dist[v] < dist[u])) {
                u = v; /* pick closest unused vertex */
            }
        }
        if (u == -1 || dist[u] == INT_MAX) {
            break; /* unreachable vertices remain */
        }
        used[u] = 1;
        for (int v = 0; v < n; v++) {
            if (w[u][v] != INT_MAX && dist[u] + w[u][v] < dist[v]) {
                dist[v] = dist[u] + w[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", dist[i] == INT_MAX ? -1 : dist[i]);
    }

    return 0; /* success */
}
