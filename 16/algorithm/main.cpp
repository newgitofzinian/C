#include "algorithm.h"

// 考研必会的排序算法
// 1. 冒泡排序
// 2. 快速排序
// 3. 插入排序


int main() {
    // 生成随机数组
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }

    // 打印数组r
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 冒泡排序
    // bubble_sort(arr, 10);
    // 快速排序
    // quick_sort(arr, 0, 9);
    // 选择排序
    select_sort(arr, 10);
    // 打印排序后的数组
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //43 70 54 42 42 58 39 70 92 11
    // 11 39 42 42 43 54 58 70 70 92


    return 0;
}