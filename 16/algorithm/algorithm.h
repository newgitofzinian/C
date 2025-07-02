//
// Created by 子年 on 25-6-29.
//

#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
typedef int ElemType;
typedef struct {
    ElemType *data;
    int len;
};


void swap(ElemType &a, ElemType &b);
void bubble_sort(ElemType arr[], int len, int id = 1); // 默认升序排序
void quick_sort(ElemType arr[], int low, int high); // 默认升序排序
void select_sort(ElemType arr[], int len, int id = 1); // 默认升序排序
void heap_sort(ElemType arr[], int len, int  = 1); // 堆排序
void merge_sort(ElemType arr[], int low, int high); // 归并排序
#endif //ALGORITHM_H
