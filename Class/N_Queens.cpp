#include <stdio.h>
#include <cstdlib>

class Queen {
    friend int nQueen(int);
    int n, *x;
    long sum;

    bool Place(int k) {
        for (int i = 1; i < k; i++)
            if (abs(k - i) == abs(x[k] - x[i]) || x[i] == x[k]) return false;
        return true;
    }

    void Backtrack(int k) {
        if (k > n) {
            sum++;
        } else {
            for (int i = 1; i <= n; i++) {
                x[k] = i;
                if (Place(k)) Backtrack(k + 1);
            }
        }
    }
};

int nQueen(int n) {
    Queen Q;
    Q.n = n;
    Q.sum = 0;
    int *p = new int[n + 1];
    for (int i = 0; i <= n; i++) {
        p[i] = 0;
    }
    Q.x = p;
    Q.Backtrack(1);
    delete[] p;
    return Q.sum;
}

int main() {
    int result = nQueen(8);
    printf("%d", result);
    return 0;
}
