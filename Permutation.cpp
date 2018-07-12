#include <stdio.h>

int n = 4;

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Permutation(int a[], int i) {
    if (i == n) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[j]);
        }
        printf("\n");
    } else {
        for (int j = i; j < n; j++) {
            Swap(&a[i], &a[j]);
            Permutation(a, i + 1);
            Swap(&a[i], &a[j]);
        }
    }
}

int main() {
    int a[] = {1, 2, 3, 4};
    Permutation(a, 0);
}
