#include "function.h"


// 层次建树
int main() {
    BiTree pnew;  // 申请一个树的新结点
    BiTree tree = nullptr;  // 树根, 空树
    BiElemType c;
    ptag_t phead=nullptr, ptail=nullptr, list_pnew=nullptr, pcur = nullptr;
    // current 当前的
    // abcdefghij
    while (scanf("%c", &c)) {
        if (c == '\n') {
            break;
        }
        // !!! calloc 用与分配内存,并初始化为0, 第一个参数树要分配的元素数量
        //  使用`calloc` 分配的内存需要在不再使用时手动释放，否则会导致内存泄漏

        pnew = (BiTree) calloc(1, sizeof(BiTNode));
        pnew->data = c;
        // 给队列结点申请新空间
        list_pnew = (ptag_t)calloc(1, sizeof(tag_t));
        list_pnew->addr = pnew;

        // 如果是树的第一个结点
        if (nullptr == tree) {
            tree = pnew; // tree 指向根结点
            phead = list_pnew;
            ptail = list_pnew;
            pcur = list_pnew; // pcur指向进入树的结点
        }
        else {
            // 让元素入队
            ptail->pnext = list_pnew;
            ptail = ptail->pnext;
            // 把结点放入树中
            if (nullptr == pcur->addr->lchild) {  // 左孩子为空
                pcur->addr->lchild = pnew;
            }
            else if (nullptr == pcur->addr->rchild){  // 右孩子为空
                pcur->addr->rchild = pnew;
                pcur = pcur->pnext; // 当前结点指向下一个
            }
        }
    }


    return 0;
}