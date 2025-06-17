//
// Created by 子年 on 25-6-13.
//

#include "dynamic_seq_list.h"

void InitList(DynamicSeqList &list) {
    list.data = nullptr;
    // list.data = (ElemType *) malloc(MaxSize*sizeof(ElemType));
    list.capacity = InitSize;
    list.length = 0;
}


// ======================
// 以下是AI生成
#include "dynamic_seq_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 初始化动态顺序表
void init_list(DynamicSeqList* list) {
    list->data = NULL;
    list->capacity = 0;
    list->size = 0;
}

// 扩容函数
static void resize_list(DynamicSeqList* list) {
    size_t new_capacity = list->capacity == 0 ? 4 : list->capacity * 2;
    int* new_data = (int*)realloc(list->data, new_capacity * sizeof(int));
    if (!new_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    list->data = new_data;
    list->capacity = new_capacity;
}

// 插入元素到顺序表尾部
int insert_element(DynamicSeqList* list, int element) {
    if (list->size == list->capacity) {
        resize_list(list); // 如果容量不足，则扩容
    }
    list->data[list->size++] = element;
    return 1; // 插入成功
}

// 删除指定位置的元素
int delete_element(DynamicSeqList* list, size_t position) {
    if (position >= list->size) {
        return 0; // 删除失败，位置无效
    }

    for (size_t i = position; i < list->size - 1; ++i) {
        list->data[i] = list->data[i + 1]; // 向前移动元素
    }
    --list->size;
    return 1; // 删除成功
}

// 查询指定位置的元素
int get_element(const DynamicSeqList* list, size_t position) {
    if (position >= list->size) {
        fprintf(stderr, "Invalid position\n");
        exit(EXIT_FAILURE);
    }
    return list->data[position];
}

// 获取顺序表的大小
size_t get_size(const DynamicSeqList* list) {
    return list->size;
}

// 打印顺序表内容
void print_list(const DynamicSeqList* list) {
    for (size_t i = 0; i < list->size; ++i) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// 释放顺序表占用的内存
void free_list(DynamicSeqList* list) {
    free(list->data);
    list->data = NULL;
    list->capacity = 0;
    list->size = 0;
}