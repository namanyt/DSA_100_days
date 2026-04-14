#include <stdio.h>

/* Read graph and perform BFS from a source. */
int main() {
    int n, m; /* vertices and edges */
    if (scanf("%d %d", &n, &m) != 2) {
        return 0; /* no valid input */
    }

    int adj[200][200];
    int deg[200] = {0};
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; /* convert to 0-based */
        v--;
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u; /* undirected */
    }

    int src;
    scanf("%d", &src);
    src--; /* convert to 0-based */

    int vis[200] = {0};
    int queue[2000];
    int front = 0, rear = 0;
    queue[rear++] = src;
    vis[src] = 1;

    int first = 1;
    while (front < rear) {
        int u = queue[front++];
        if (!first) {
            printf(" ");
        }
        printf("%d", u + 1); /* output 1-based vertex */
        first = 0;

        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            if (!vis[v]) {
                vis[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    return 0; /* success */
}
