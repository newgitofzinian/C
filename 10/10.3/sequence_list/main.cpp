#include <stdio.h>

// 顺序表的插入操作
#define MaxSize 50
typedef int ElemType;
// 动态分配 了解即可,不考察
#define InitSize 100
typedef struct {
    ElemType *data;
    int capacity; // 动态数组的最大容量
    int length;
}SeqList;

// 静态分配 重点!!!!
typedef struct {
    ElemType data[MaxSize];
    int length; // 当前顺序表有多少个元素
}SqList;
/**  顺序表的插入,因为L会改变,所以使用引用
 *  @brief 插入元素到顺序表
 *  @return bool值,插入成功或失败
 *  @L 插入的目标顺序表
 *  @pos 插入位置
 *  @element 插入的数据
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

void PrintList(SqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("%3d", L.data[i]);
    }
    printf("\n");
}
int main() {
    SqList L; // 定义一个顺序表
    bool ret;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length= 3; // 设置长度
    ret = ListInsert(L, 2, 60);
    if (ret) {
        printf("插入成功\n");
        PrintList(L);
    }else {
        printf("插入失败\n");
    }


    return 0;
}