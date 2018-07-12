#include <stdio.h>

int BinarySearch(int a[], int x, int size) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (a[middle] == x) return middle;
        if (a[middle] > x)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}

int main() {
    int a[] = {0, 2, 5, 6, 8, 123, 5345, 65345};
    int index = BinarySearch(a, 123, sizeof(a) / sizeof(int));
    printf("%d", index);
    return 0;
}
