#include <stdio.h>

/* DFS helper for topological ordering. */
static void dfs(int u, int adj[200][200], int deg[200], int vis[200], int stack[], int *top) {
    vis[u] = 1;
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!vis[v]) {
            dfs(v, adj, deg, vis, stack, top);
        }
    }
    stack[(*top)++] = u; /* push after visiting children */
}

/* Topological sort using DFS. */
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
    int stack[200];
    int top = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, deg, vis, stack, &top);
        }
    }

    for (int i = top - 1; i >= 0; i--) {
        if (i != top - 1) {
            printf(" ");
        }
        printf("%d", stack[i]); /* output 0-based vertex */
    }

    return 0; /* success */
}
