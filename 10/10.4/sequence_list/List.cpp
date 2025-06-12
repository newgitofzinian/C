//
// Created by 子年 on 25-6-12.
//

#include "List.h"


/**  顺序表的插入,因为L会改变,所以使用引用
 *  @brief 插入元素到顺序表
 *  @return bool值,插入成功或失败
 *  @param L 插入的目标顺序表
 *  @param pos 插入位置
 *  @param element 插入的数据
 */
bool ListInsert(SqList &L, int pos, ElemType element) {
    // 判断插入的位置是否合法
    if (pos < 1  || pos > L.length+1) {
        return false;   // 不合法
    }
    if (L.length == MaxSize) {
        return false;   // 放满了就不能放了
    }
    // 把后面的汉元素依次往后移动,空出位置,放入要插入到的元素
    for (int j = L.length ; j >= pos; --j) {
        L.data[j] = L.data[j-1];
    }
    L.data[pos-1] = element;
    L.length++; //否则还是只有三个元素
    return true;
}

/**
 * @brief 打印顺序表
 * @param L 打印的顺序表
 */
void PrintList(SqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

/**
 * @brief 删除顺序表中的元素
 * @param L 顺序表
 * @param pos 删除的第几个元素
 * @param del 获取被删除的值
 * @return ture 成功 false 失败
 */
bool ListDelete(SqList &L, ElemType &del, int pos) {
    // 判断删除的位置是否合法
    if (pos < 1 || pos > L.length) {
        return false;
    }
    del = L.data[pos-1]; // 保存要删除的元素的值
    for (int i = pos-1 ; i < L.length-1; ++i) {
        L.data[i] = L.data[i+1];
    }
    L.length--;
    return true;
}

/** 不考虑有两个元素,有只找第一个
 * @brief 查找某个元素的位置,找到了就返回对应位置,没有就返回0
 * @param L 线性表
 * @param pos 元素值
 * @return 元素位置,没有就是0
 */
int LocateElem(SqList L, int pos) {
    for (int i = 0; i < L.length; ++i) {
        if (pos == L.data[i]) {
            return i+1;  // i是数组的下表,加一才是顺序表的下表
        }
    }
    return 0; // 循环结束未找到
}

