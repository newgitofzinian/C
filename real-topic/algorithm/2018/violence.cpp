//
// Created by 子年 on 25-7-20.
// 暴力解
#include <iostream>

int Partition(int A[], int L, int R) {
    int Mid = A[L];
    while (L < R) {
        while (L < R && A[R] >= Mid) R--;
        A[L] = A[R];
        while (L < R && A[L] <= Mid) L++;
        A[R] = A[L];
    }
    A[L] = Mid;
    return L;
}

void QuickSort(int A[], int low, int high) {
    if (low < high) {
        int pivotpos = Partition(A, low, high);
        QuickSort(A, 0, pivotpos-1);
        QuickSort(A, pivotpos, high);
    }
}

int Find(int A[], int n) {
    QuickSort(A, 0, n-1);
    int ret = 1;
    for (int i = 0; i < n; ++i) {
        if (A[i]>0) {
            if (A[i] != ret) {
                return ret;
            }
            ret ++;
        }
    }
}
