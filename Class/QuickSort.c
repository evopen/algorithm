#include <stdio.h>

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int a[], int first, int last) {
    int anchor = a[first];
    int i = first;
    int j = last + 1;
    while (1) {
        while (a[++i] < anchor && i < last)
            ;
        while (a[--j] > anchor)
            ;
        if (i >= j) break;
        Swap(&a[i], &a[j]);
    }
    a[first] = a[j];
    a[j] = anchor;
    return j;
}

void QuickSort(int a[], int first, int last) {
    if (first < last) {
        int mid = Partition(a, first, last);
        QuickSort(a, first, mid - 1);
        QuickSort(a, mid + 1, last);
    }
}

int main() {
    int length = 7;
    int s[] = {12, 7, 3, 9, 15, 8, 1};
    QuickSort(s, 0, 6);
    for (int i = 0; i < length; i++) {
        printf("%d ", s[i]);
    }
    return 0;
}
