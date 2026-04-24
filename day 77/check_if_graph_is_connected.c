#include <stdio.h>

/* DFS traversal to mark reachable nodes. */
static void dfs(int u, int adj[200][200], int deg[200], int vis[200]) {
    vis[u] = 1;
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!vis[v]) {
            dfs(v, adj, deg, vis);
        }
    }
}

/* Check if an undirected graph is connected. */
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
    dfs(0, adj, deg, vis);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0; /* success */
}
