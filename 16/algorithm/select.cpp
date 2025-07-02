//
// Created by 子年 on 25-7-2.
//
#include "algorithm.h"
void select_sort(int arr[], int n, int id) {
    for (int i = 0; i < n - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            if (id == 1) {
                if (arr[j] < arr[idx]) {
                    idx = j;
                }
            } else if (id == 0) {
                if (arr[j] > arr[idx]) {
                    idx = j;
                }
            }
        }
        if (idx != i) {
            swap(arr[i], arr[idx]);
        }
    }
}