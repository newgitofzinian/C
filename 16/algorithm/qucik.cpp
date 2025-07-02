//
// Created by 子年 on 25-6-29.
//
#include"algorithm.h"

// 考研所考察的快排划分通常总以表中第一个元素为基准.
ElemType Partittion(ElemType arr[], int low, int high) {    // 一趟划分
    ElemType pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= pivot) {
            high--;
        }
        arr[low] = arr[high];
        while (low < high && arr[low] < pivot) {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

// 实际生产环境中, 考研所考察的快排划分通常以随机选取的元素为基准.
ElemType Partittion2(ElemType arr[], int low, int high) {    // 一趟划分
    int pivot = rand() % (high - low + 1) + low;
    swap(arr[pivot], arr[high]); // 随机选取基准, 并交换到末尾
    pivot = high;  // 基准元素的位置
    for (int i = low; i < high; i++) {
        if (arr[i] < arr[pivot]) { // 小于基准元素的元素, 左移
            swap(arr[i], arr[low]);
            low++;
        }
    }
    swap(arr[low], arr[pivot]); // 基准元素归位
    return low;
}

void quick_sort(ElemType arr[], int low, int high) {
    if (low < high) {   // 递归条件
        ElemType pivot = Partittion(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
    return;

}