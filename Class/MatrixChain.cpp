#include <iostream>
using namespace std;

void MatrixChain(int *matrixChain, int chainSize, int **complexityMatrix, int **breakPointMatrix) {
    for (int i = 1; i <= chainSize; i++) 
        complexityMatrix[i][i] = 0;
    for (int offset = 2; offset <= chainSize; offset++) {
        for (int head = 1; head <= chainSize - offset + 1; head++) {
            int tail = head + offset - 1;
            // Initialize complexityMatrix breakpoint to the first matrix
            complexityMatrix[head][tail] = complexityMatrix[head + 1][tail] +
                matrixChain[head - 1] * matrixChain[head] * matrixChain[tail];
            breakPointMatrix[head][tail] = head;
            for (int breakPoint = head + 1; breakPoint < tail; breakPoint++) {
                int complexity = complexityMatrix[head][breakPoint] + complexityMatrix[breakPoint + 1][tail] +
                                   matrixChain[head - 1] * matrixChain[breakPoint] * matrixChain[tail];
                if (complexity < complexityMatrix[head][tail]) {
                    complexityMatrix[head][tail] = complexity;
                    breakPointMatrix[head][tail] = breakPoint;
                }
            }
        }
    }
}

int main() {
    int matrixColumnSize[7] = {30, 35, 15, 5, 10, 20, 25};
    int matrixCount = 6;
    int **complexityMatrix = new int *[matrixCount];
    int **breakPointMatrix = new int *[matrixCount];
    for (int i = 0; i < matrixCount; i++) {
        complexityMatrix[i] = new int[matrixCount];
        breakPointMatrix[i] = new int[matrixCount];
    }
    MatrixChain(matrixColumnSize, matrixCount, complexityMatrix, breakPointMatrix);
    for (int i = 1; i <= matrixCount; i++) {
        for (int tab = 1; tab < i; tab++)
            cout << "\t";
        for (int j = i; j <= matrixCount; j++) 
            cout << complexityMatrix[i][j] << "\t";
        cout << endl;
    }
    return 0;
}
