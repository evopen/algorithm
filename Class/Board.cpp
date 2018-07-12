class Board {
    int n, m, *x, *bestx, bestd, *total, *now, **B;
    void Backtrack(int i, int cd) {
        if (i == n) {
            for (int j = 1; j <= n; j++) {
                bestx[j] = x[j];
                bestd = cd;
            }
        } else {
            for (int j = i; j <= n; j++) {
                int ld = 0;
                for (int k = 1; k <= m; k++) {
                    now[k] += B[x[j]][k];
                    if (now[k] > 0 && total[k] != now[k]) ld++;
                }
                if (cd > ld) ld = cd;
                if (ld < bestd) {
                    Swap(x[i], x[j]);
                    Backtrack(i + 1, ld);
                    Swap(x[i], x[j]);
                }
                for (int k = 1; k <= m; k++) {
                    now[k] += B[x[j]][k];
                }
            }
        }
    }
};
