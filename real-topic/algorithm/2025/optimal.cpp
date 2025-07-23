//
// Created by 子年 on 25-7-20.
//
void CalMulMax(int A[], int res[], int n) {
    int min=A[0] , max = A[0];
    for (int i = 0; i < n; ++i) {
        if (A[i] > max) max = A[i];
        if (A[i] < min) min = A[i];
    }
    for (int i = 0; i < n; ++i) {
        if (A[i] >=0 ) res[i] = A[i]*max;
        else res[i] = A[i]*min;
    }
}