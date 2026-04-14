#include <stdio.h>

/* DFS to detect cycle in an undirected graph. */
static int dfs(int u, int parent, int adj[200][200], int deg[200], int vis[200]) {
    vis[u] = 1;
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!vis[v]) {
            if (dfs(v, u, adj, deg, vis)) {
                return 1;
            }
        } else if (v != parent) {
            return 1; /* back edge */
        }
    }
    return 0;
}

/* Read graph and report if a cycle exists. */
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
    for (int i = 0; i < n; i++) {
        if (!vis[i] && dfs(i, -1, adj, deg, vis)) {
            printf("YES");
            return 0;
        }
    }

    printf("NO");
    return 0; /* success */
}
