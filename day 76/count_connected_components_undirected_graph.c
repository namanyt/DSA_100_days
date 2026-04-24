#include <stdio.h>

/* DFS traversal for connected components. */
static void dfs(int u, int adj[200][200], int deg[200], int vis[200]) {
    vis[u] = 1;
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!vis[v]) {
            dfs(v, adj, deg, vis);
        }
    }
}

/* Count connected components in an undirected graph. */
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
        adj[v][deg[v]++] = u;
    }

    int vis[200] = {0};
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, deg, vis);
            count++;
        }
    }

    printf("%d", count);
    return 0; /* success */
}
