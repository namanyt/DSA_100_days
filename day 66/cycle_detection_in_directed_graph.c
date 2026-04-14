#include <stdio.h>

/* DFS to detect cycles in a directed graph. */
static int dfs(int u, int adj[200][200], int deg[200], int vis[200], int in_stack[200]) {
    vis[u] = 1;
    in_stack[u] = 1;

    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!vis[v] && dfs(v, adj, deg, vis, in_stack)) {
            return 1;
        }
        if (in_stack[v]) {
            return 1; /* back edge found */
        }
    }

    in_stack[u] = 0;
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
    }

    int vis[200] = {0};
    int in_stack[200] = {0};
    for (int i = 0; i < n; i++) {
        if (!vis[i] && dfs(i, adj, deg, vis, in_stack)) {
            printf("YES");
            return 0;
        }
    }

    printf("NO");
    return 0; /* success */
}
