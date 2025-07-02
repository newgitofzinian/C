//
// Created by 子年 on 25-6-29.
//
#include "algorithm.h"

/**
 *
 * @param str 需要排序的数组
 * @param id 排序的方向，1表示升序，0表示降序
 */

void swap(ElemType& a, ElemType& b) {
    ElemType temp = a;
    a = b;
    b = temp;
}

void bubble_sort(ElemType str[], int len, int id) {
    bool flag;
    if (id == 1) {
        for (int i = 0; i < len - 1; i++) {
            flag = false;
            for (int j = 0; j < len - 1 - i; j++) {
                if (str[j] > str[j + 1]) {
                    swap(str[j], str[j + 1]);
                    flag = true;
                }
            }
            if (!flag) {    // 若没有发生交换，则说明已经有序，则退出循环
                break;
            }
        }
    } else if (id == 0) {
        for (int i = 0; i < len - 1; i++) {
            flag = false;
            for (int j = 0; j < len -1 -i; j++) {
                if (str[j] < str[j + 1]) {
                    swap(str[j], str[j + 1]);
                    flag = true;
                }
            }
            if (!flag) { // 若没有发生交换，则说明已经有序，则退出循环
                break;
            }
        }
    }
    return;
}
