class Color {
    friend void nColoring(int, int, int **);
    int n;    // 顶点数
    int m;    // 颜色数
    int **a;  //邻接矩阵
    int *x;
    long sum;
    bool OK(int k) {
        for (int j = 1; j <= n; j++)
            if (a[k][j] == 1 && x[k] == x[j]) return false;
        return true;
    }

    void Backtrack(int k) {
        if (k > n) {
            sum++;
        } else {
            for (int i = 1; i <= m; i++) {
                x[k] = i;
                if (OK(k)) Backtrack(k + 1);
                x[k] = 0;
            }
        }
    }
};
