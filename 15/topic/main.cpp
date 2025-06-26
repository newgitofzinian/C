#include <iostream>

int findMedian(int A[], int n) {
    return A[n / 2];
}

// 双数组的二分查找
int binarySearch(int A[], int B[], int n) {
    if (n == 1) {
        return std::min(A[0], B[0]);
    }

    int mid = n / 2;
    int a = findMedian(A, n);
    int b = findMedian(B, n);

    if (a == b) {
        return a;
    }

    if (a < b) {
        return binarySearch(A + mid, B, n - mid);
    } else {
        return binarySearch(A, B + mid, n - mid);
    }
}

int main() {
        int A[] = {1, 3, 5, 7, 9};
        int B[] = {2, 4, 6, 8, 10};
        int n = sizeof(A) / sizeof(A[0]);
        int median = binarySearch(A, B, n);
        std::cout << "Median is " << median << std::endl;

    return 0;
}