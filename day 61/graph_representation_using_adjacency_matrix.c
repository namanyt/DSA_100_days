#include <stdio.h>

/* Build and print adjacency matrix for an undirected graph. */
int main() {
    int n, m; /* vertices and edges */
    if (scanf("%d %d", &n, &m) != 2) {
        return 0; /* no valid input */
    }

    int mat[200][200] = {0}; /* adjacency matrix */
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; /* convert to 0-based */
        v--;
        mat[u][v] = 1;
        mat[v][u] = 1; /* undirected graph */
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j) {
                printf(" ");
            }
            printf("%d", mat[i][j]);
        }
        if (i < n - 1) {
            printf("\n");
        }
    }
    return 0; /* success */
}
