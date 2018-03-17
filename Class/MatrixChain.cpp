#include <iostream>
using namespace std;

void MatrixChain(int *matrixChain, int chainSize, int **optimumMatrix, int **breakPointMatrix) {
    for (int i = 1; i <= chainSize; i++) 
        optimumMatrix[i][i] = 0;
    for (int offset = 2; offset <= chainSize; offset++) {
        for (int head = 1; head <= chainSize - offset + 1; head++) {
            int tail = head + offset - 1;
            // Initialize optimumMatrix breakpoint to the first matrix
            optimumMatrix[head][tail] = optimumMatrix[head + 1][tail] +
                matrixChain[head - 1] * matrixChain[head] * matrixChain[tail];
            breakPointMatrix[head][tail] = head;
            for (int breakPoint = head + 1; breakPoint < tail; breakPoint++) {
                int optimumPoint = optimumMatrix[head][breakPoint] + optimumMatrix[breakPoint + 1][tail] +
                                   matrixChain[head - 1] * matrixChain[breakPoint] * matrixChain[tail];
                if (optimumPoint < optimumMatrix[head][tail]) {
                    optimumMatrix[head][tail] = optimumPoint;
                    breakPointMatrix[head][tail] = breakPoint;
                }
            }
        }
    }
}

int main() {
    int matrixColumnSize[7] = {30, 35, 15, 5, 10, 20, 25};
    int matrixCount = 6;
    int **optimumMatrix = new int *[matrixCount];
    int **breakPointMatrix = new int *[matrixCount];
    for (int i = 0; i < matrixCount; i++) {
        optimumMatrix[i] = new int[matrixCount];
        breakPointMatrix[i] = new int[matrixCount];
    }
    MatrixChain(matrixColumnSize, matrixCount, optimumMatrix, breakPointMatrix);
    for (int i = 1; i <= matrixCount; i++) {
        for (int tab = 1; tab < i; tab++)
            cout << "\t";
        for (int j = i; j <= matrixCount; j++) 
            cout << optimumMatrix[i][j] << "\t";
        cout << endl;
    }
    return 0;
}
