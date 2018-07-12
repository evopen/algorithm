#include <stdio.h>

void MatrixChain(int *matrix, int count, int **result, int **bp) {
    for (int i = 1; i <= count; i++) result[i][i] = 0;
    for (int l = 2; l <= count; l++) {  // l:链长
        for (int head = 1; head <= count - l + 1; head++) {
            int tail = head + l - 1;
            // Initialize result breakpoint to the first matrix
            result[head][tail] = result[head + 1][tail] +
                                 matrix[head - 1] * matrix[head] * matrix[tail];
            bp[head][tail] = head;
            for (int breakPoint = head + 1; breakPoint < tail; breakPoint++) {
                int complexity =
                    result[head][breakPoint] + result[breakPoint + 1][tail] +
                    matrix[head - 1] * matrix[breakPoint] * matrix[tail];
                if (complexity < result[head][tail]) {
                    result[head][tail] = complexity;
                    bp[head][tail] = breakPoint;
                }
            }
        }
    }
}

int main() {
    int matrixColumnSize[7] = {30, 35, 15, 5, 10, 20, 25};
    int matrixCount = 6;
    int **result = new int *[matrixCount];
    int **bp = new int *[matrixCount];
    for (int i = 0; i < matrixCount; i++) {
        result[i] = new int[matrixCount];
        bp[i] = new int[matrixCount];
    }
    MatrixChain(matrixColumnSize, matrixCount, result, bp);
    for (int i = 1; i <= matrixCount; i++) {
        for (int tab = 1; tab < i; tab++) printf("        ");
        for (int j = i; j <= matrixCount; j++) printf("%8d", result[i][j]);
        printf("\n");
    }
    return 0;
}
