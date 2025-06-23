//
// Created by 子年 on 25-6-23.
//
#include "struct.h"
// 初始化队列,带头节点
void initQueue(LinkQueue &Q) {
    Q.front = Q.rear = (Queue) malloc(sizeof(QNode));
}
// 判断队列是否为空
bool isEmpty(LinkQueue Q) {
    return Q.front == nullptr;
}
// 入队操作
void enQueue(LinkQueue &Q, char x) {
    QNode *p = (Queue) malloc(sizeof(QNode));
    p->data = x;
    p->next = nullptr;
    if (Q.rear == nullptr) {
        Q.front = Q.rear = p;
    } else {
        Q.rear->next = p;
        Q.rear = p;
    }
}
// 出队操作
void deQueue(LinkQueue &Q, char &x) {
    if (Q.front == nullptr) {
        printf("Queue is empty!\n");
        return;
    }
    x = Q.front->data;
    QNode *p = Q.front;
    Q.front = Q.front->next;
    if (Q.front == nullptr) {
        Q.rear = nullptr;
    }
    free(p);
}
// 销毁队列
void DestroyQueue(LinkQueue &Q) {
    QNode *p = Q.front;
    while (p!= nullptr) {
        QNode *q = p;
        p = p->next;
        free(q);
    }
    Q.front = Q.rear = nullptr;
}

void visit(BiTree p) {
    // 访问p节点的操作
    if (p == nullptr) {
        return;
    }
    printf("%d ", p->data);
    visit(p->lchild);
    visit(p->rchild);
}
// 层序遍历二叉树
void LevelOrder(BiTree T) {
    LinkQueue Q;
    initQueue(Q);   // 初始化辅助队列
    BiTree p;
    enQueue(Q, T->data);  // 根节点入队
    while (!isEmpty(Q)) {
        deQueue(Q, p->data);  // 队头元素出队
        visit(p);  // 访问队头元素
        if (p->lchild!= nullptr) {
            enQueue(Q, p->lchild->data);  // 左孩子入队
        }
        if (p->rchild!= nullptr) {
            enQueue(Q, p->rchild->data);  // 右孩子入队
        }
    }
}
//
BiTree createTree(int pre[], int in[], int n) {
    if (n == 0) {
        return nullptr;
    }
    BiTree T = (BiTree) malloc(sizeof(BiNode));
    T->data = pre[0];
    int i;
    for (i = 0; i < n; i++) {
        if (in[i] == pre[0]) {
            break;
        }
    }
    T->lchild = createTree(pre + 1, in, i);
    T->rchild = createTree(pre + i + 1, in + i + 1, n - i - 1);
    return T;
}