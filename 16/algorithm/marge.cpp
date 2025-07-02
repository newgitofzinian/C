//
// Created by 子年 on 25-7-2.
//
#include "algorithm.h"
// 48 80 54 92 59 39 44 92 74 32
void Merge1(ElemType A[], int low, int mid, int high) { // 空间复杂度O(N)
    ElemType *B = (ElemType *)malloc((high - low + 1) * sizeof(ElemType));  // 临时数组
    // 将表A的两段, A[low...mid]和A[mid+1...high],两段各自有序,将两段合并成一个有序表
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (A[i] <= A[j]) { // 左半段的元素小于右半段的元素
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    // 将剩余的元素复制到临时数组
    while (i <= mid) {
        B[k++] = A[i++];
    }
    while (j <= high) {
        B[k++] = A[j++];
    }
    // 将临时数组中的元素复制回表A
    for (i = low; i <= high; i++) {
        A[i] = B[i];
    }
    free(B); // 释放临时数组的空间
}
#define N 7
void Merge(ElemType A[], int low, int mid, int high) { // 空间复杂度O(N)
    static ElemType B[N]; // 若high-low+1 > N,则会出现越界访问
    int i, j, k;
    for (i = low;  i <= high; i++) {
        B[i] = A[i]; // 将A[low...high]复制到B[low...high]
    }
    k = low;
    for (i = low , j = mid + 1; i <= mid&&j<=high;) {
        if (B[i] <= B[j]) { // 左半段的元素小于右半段的元素
            A[k++] = B[i++];
        } else {
            A[k++] = B[j++];
        }
    }
    while (i <= mid) {
        A[k++] = B[i++];
    }
    while (j <= high) {
        A[k++] = B[j++];
    }
}

void merge_sort(int A[], int low, int high) { // 空间复杂度O(N)
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(A, low, mid);        // 对左半段递归排序
        merge_sort(A, mid + 1, high);    // 对右半段递归排序
        Merge1(A, low, mid, high);        // 合并两个有序表
    }
}