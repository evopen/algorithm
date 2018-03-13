#include <iostream>
#include <vector>

using namespace std;

vector<vector<double> > multiply(vector<vector<double> > A,
                                 vector<vector<double> > B) {
    int n = A.size();
    vector<vector<double> > C;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            C[i][j] = 0;
            for (int k = 1; k <= n; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    vector<vector<double> > A;
    A.resize(2);
    for (int i = 0; i < 2; i++) {
        A[i].resize(2);
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            A[i][j] = 1;
        }
    }
    vector<vector<double> > B = A;
    vector<vector<double> > C;
    C = multiply(A, B);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << C[i][j] << endl;
        }
    }
}
