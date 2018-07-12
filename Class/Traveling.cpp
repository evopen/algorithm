#include <stdio.h>

void Swap(int ,int);

class Traveling {
    int n, *x, *bestx;
    int **a, cc, bestc, NoEdge;
    void Backtrack(int i) {
        if (i == n) {
            if (a[x[n - 1]][x[n]] != NoEdge && a[x[n]][1] != NoEdge &&
                (cc + a[x[n - 1]][x[n]] + a[x[n]][1] < bestc ||
                 bestc == NoEdge)) {
                for (int j = 1; i <= n; j++) {
                    bestx[j] = x[j];
                }
                bestc = cc + a[x[n - 1]][x[n]] + a[x[n]][1];
            }
        } else {
            for (int j = i; j <= n; j++) {
                if (a[x[i - 1]][x[j]] != NoEdge &&
                    (cc + a[x[i - 1]][x[j]] > bestc || bestc == NoEdge)) {
                    Swap(x[i], x[j]);
                    cc += a[x[i - 1]][x[i]];
                    Backtrack(i + 1);
                    cc -= a[x[i - 1]][x[i]];
                    Swap(x[i], x[j]);
                }
            }
        }
    }
};
