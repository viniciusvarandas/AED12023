#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INFINITY 999999
#define MAX_CITIES 1200

typedef unsigned uint;

uint dist[MAX_CITIES];
uint graph[MAX_CITIES][MAX_CITIES];

void dijkstra(int, int, uint g[MAX_CITIES][MAX_CITIES], uint *);

int main(int argc, char **argv) {
    int r, e, c;
    int n, m, u, v;

    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                graph[i][j] = INFINITY;

        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            graph[u][v] = graph[v][u] = 1;
        }

        scanf("%d %d %d", &c, &r, &e);

        for (int i = 0; i <= n; ++i)
            graph[e][i] = graph[i][e] = INFINITY;

        dijkstra(c, n, graph, dist);

        printf("%d\n", dist[r]);
    }

    return 0;
}

void dijkstra(int s, int n, uint g[MAX_CITIES][MAX_CITIES], uint *d) {
    bool vis[MAX_CITIES];
    memset(vis, false, sizeof(vis));

    for (int i = 0; i <= n; ++i)
        d[i] = INFINITY;

    d[s] = 0;

    for (int i = 0; i <= n; ++i) {
        int v = -1;
        for (int j = 0; j <= n; ++j) {
            if (!vis[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INFINITY)
            break;

        vis[v] = true;

        for (int j = 0; j <= n; ++j) {
            if (d[v] + g[v][j] < d[j])
                d[j] = g[v][j] + d[v];
        }
    }
}
