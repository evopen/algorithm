#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int binarySearch(vector<T> array, const T &key, int size) {
    int start = 0;
    int end = size;
    int middle = (start + end) / 2;
    while (start <= end) {
        if (array[middle] == key) {
            return middle;
        }
        if (array[middle] > key) {
            end = middle - 1;
            middle = (start + end) / 2;
        } else {
            start = middle + 1;
            middle = (start + end) / 2;
        }
    }
    return start;
}

int main() {
    vector<char> A = {'a', 'b', 'g', 'w'};
    int index = binarySearch(A, 'h', A.size());
    if (index != -1) {
        cout << "Not found." << endl;
    } else {
        cout << "Index: " << index << endl;
    }
    return 0;
}
