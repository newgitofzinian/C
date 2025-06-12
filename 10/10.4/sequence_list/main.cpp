#include "List.h"

// 顺序表的删除及查询




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
    ElemType del; // 删除的元素存在del中;
    ret = ListDelete(L, del, 3); //pos 默认为1
    if (ret) {
        printf("删除成功\n");
        printf("删除的元素是%3d\n", del);
        PrintList(L);
    }else {
        printf("删除失败\n");
    }
    int pos;// 存储元素位置
    pos = LocateElem(L, 60);
    if (pos) {
        printf("找到这个位置\n");
        printf("元素位置是%d", pos);
    }else {
        printf("没有找到这个位置\n");
    }

    return 0;
}