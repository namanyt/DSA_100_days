#include <stdio.h>

/* Topological sort using Kahn's algorithm (BFS). */
int main() {
    int n, m; /* vertices and edges */
    if (scanf("%d %d", &n, &m) != 2) {
        return 0; /* no valid input */
    }

    int adj[200][200];
    int deg[200] = {0};
    int indeg[200] = {0};

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; /* convert to 0-based */
        v--;
        adj[u][deg[u]++] = v;
        indeg[v]++;
    }

    int queue[2000];
    int front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            queue[rear++] = i;
        }
    }

    int first = 1;
    while (front < rear) {
        int u = queue[front++];
        if (!first) {
            printf(" ");
        }
        printf("%d", u); /* output 0-based vertex */
        first = 0;

        for (int i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            indeg[v]--;
            if (indeg[v] == 0) {
                queue[rear++] = v;
            }
        }
    }

    return 0; /* success */
}
