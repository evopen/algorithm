#include <iostream>

using namespace std;

void dijkstra(int size, int orig, int dist[], int prev[], int **e) {
    bool s[size];

    // Initializing
    for (int i = 1; i <= size; ++i) {
        dist[i] = e[orig][i];
        s[i] = false;
        if (dist[i] == -1) {
            prev[i] = 0;
        } else {
            prev[i] = orig;
        }
    }
    dist[orig] = 0;
    prev[orig] = -1;
    s[orig] = true;

    for (int i = 1; i <= size; ++i) {
        int temp = INT_MAX;
        int u = orig;
        for (int j = 1; j <= size; ++j) {
            if (!s[j] && dist[j] < temp) {
                u = j;
                temp = dist[u];
            }
        }
        s[u] = true;
        for (int j = 1; j <= size; j++) {
            if(!s[j] && e[u][j] < INT_MAX) {
                if(dist[j] > dist[u] + e[u][j]) {
                    dist[j] = dist[u] + e[u][j];
                    prev[j] = u;
                }
            }
        }
    }

}
