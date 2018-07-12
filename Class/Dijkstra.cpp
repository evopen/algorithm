#include <stdio.h>
#define M 65535  //无穷大

void Dijkstra(int n, int v, int dist[], int prev[], int **c) {
    bool s[M];
    for (int i = 1; i <= n; i++) {
        dist[i] = c[v][i];
        s[i] = false;
        if (dist[i] == M)
            prev[i] = 0;
        else
            prev[i] = v;
    }
    dist[v] = 0;
    s[v] = true;
    for (int i = 1; i < n; i++) {
        int temp = M;
        int u = v;
        for (int j = 1; j <= n; j++)
            if ((!s[j]) && (dist[j] < temp)) {
                u = j;
                temp = dist[j];
            }
        s[u] = true;
        for (int j = 1; j <= n; j++) {
            if ((!s[j]) && (c[u][j] < M)) {
                int newdist = dist[u] + c[u][j];
                if (newdist < dist[j]) {
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
        }
    }
}
