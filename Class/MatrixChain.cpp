#include <stdio.h>

void MatrixChain(int *matrix, int count, int **complexityMatrix,
                 int **breakPointMatrix) {
    for (int i = 1; i <= count; i++) complexityMatrix[i][i] = 0;
    for (int chainLength = 2; chainLength <= count; chainLength++) {
        for (int head = 1; head <= count - chainLength + 1; head++) {
            int tail = head + chainLength - 1;
            // Initialize complexityMatrix breakpoint to the first matrix
            complexityMatrix[head][tail] =
                complexityMatrix[head + 1][tail] +
                matrix[head - 1] * matrix[head] * matrix[tail];
            breakPointMatrix[head][tail] = head;
            for (int breakPoint = head + 1; breakPoint < tail; breakPoint++) {
                int complexity =
                    complexityMatrix[head][breakPoint] +
                    complexityMatrix[breakPoint + 1][tail] +
                    matrix[head - 1] * matrix[breakPoint] * matrix[tail];
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
    MatrixChain(matrixColumnSize, matrixCount, complexityMatrix,
                breakPointMatrix);
    for (int i = 1; i <= matrixCount; i++) {
        for (int tab = 1; tab < i; tab++) printf("        ");
        for (int j = i; j <= matrixCount; j++)
            printf("%8d", complexityMatrix[i][j]);
        printf("\n");
    }
    return 0;
}
