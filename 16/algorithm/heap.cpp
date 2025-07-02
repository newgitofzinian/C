//
// Created by 子年 on 25-7-2.
//
#include "algorithm.h"


void HeapAdjust(ElemType arr[], int start, int len) {
    int root = start;
    int child;
    for (child = 2 * root + 1; child < len; child = 2 * child + 1) {
        // 找出root节点的左右孩子中较大的
        if (child + 1 < len && arr[child] < arr[child + 1]) {
            child++;
        }
        // 如果root节点的左右孩子中较大的不是root节点，则交换root节点和较大的孩子节点
        if (arr[child] > arr[root]) {
            swap(arr[root], arr[child]);
            root = child; // 继续调整子树, 新的root节点是child节点, 继续比较
        } else {
            break;
        }
    }
}


void BuildMaxHeap(ElemType arr[], int len) {
    for (int i = len / 2 - 1; i >= 0; i--) {
        // 从最后一个非叶子节点开始 调整为最大堆
        HeapAdjust(arr, i, len); // 调整以i为根节点的子树为最大堆
    }
}


// 4 10 20 22 25 49 31 45 28 0
void heap_sort(ElemType arr[], int len, int id) {
    // 建堆
    BuildMaxHeap(arr, len);
    // 堆排序
    for (int i = len - 1; i > 0; i--) {
        if (id == 1) {
            // 交换堆顶元素和最后一个元素
            swap(arr[0], arr[i]);
            // 调整堆
            HeapAdjust(arr, 0, i);
        } else {
            HeapAdjust(arr, len - i, i);
        }
    }
}