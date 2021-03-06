#include <stdio.h>

void merge(int *a, int *b, int first, int mid, int last) {
    int i = first;
    int j = mid + 1;
    int k = first;
    while (i <= mid && j <= last) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    if (i == mid + 1) {
        while (j <= last) {
            b[k++] = a[j++];
        }
    } else {
        while (i <= mid) {
            b[k++] = a[i++];
        }
    }
}

inline void copy(int *a, int *b, int first, int last) {
    for (int i = first; i <= last; ++i) a[i] = b[i];
}

void mergeSort(int *a, int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(a, first, mid);
        mergeSort(a, mid + 1, last);
        int b[7] = {0};
        merge(a, b, first, mid, last);
        copy(a, b, first, last);
    }
}

int main() {
    int length = 7;
    int s[] = {12, 7, 3, 9, 15, 8, 1};
    mergeSort(s, 0, 6);
    for (int i = 0; i < length; i++) {
        printf("%d ", s[i]);
    }
    return 0;
}
