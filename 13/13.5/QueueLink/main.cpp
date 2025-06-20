#include <iostream>

// 队列的链式存储 非重点,了解即可
typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    LinkNode* next;
}LinkNode;
typedef struct {
    LinkNode* head;
    LinkNode* tail;
}LinkQueue;

// 初始化队列
void InitQueue(LinkQueue& Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}
bool isEmpty(LinkQueue Q) {
    return Q.head == nullptr;
}
// 入队
void EnQueue(LinkQueue &Q, ElemType x) {
    try {
        LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
        p->data = x;
        p->next = nullptr;
        if (isEmpty(Q)) { // 队列为空,需要首尾指针都指向新节点
            Q.head = p;
            Q.tail = p;
        }else{
            Q.tail->next = p;
            Q.tail = p;
        }
    } catch (std::bad_alloc e) {
        std::cerr << "Out of memory!" << std::endl;
    }
}
// 出队
ElemType DeQueue(LinkQueue &Q){
    if (isEmpty(Q)) {
        std::cerr << "Queue is empty!" << std::endl;
        return -1;
    }
    ElemType x = Q.head->data;
    LinkNode *p = Q.head;
    Q.head = Q.head->next;
    if (Q.head == nullptr) { // 队列中只有一个节点,删除后无结点
        Q.tail = nullptr;
    }
    free(p);
    return x;
}

// 打印队列
void PrintQueue(LinkQueue Q) {
    if (isEmpty(Q)) {
        std::cout << "Queue is empty!" << std::endl;
    }
    LinkNode *p = Q.head;
    while (p!= nullptr) {
        std::cout << p->data << " ";
        p = p->next;
        }
    std::cout << std::endl;
    }


int main() {
    LinkQueue Q;
    ElemType x;
    bool falg;

    // 初始化队列,并判断是否为空
    InitQueue(Q);
    falg = isEmpty(Q);
    std::cout << "That queue is empty is " << falg << std::endl;

    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);

    // 打印队列
    PrintQueue(Q);

    // 出队
    x = DeQueue(Q);
    std::cout << "Dequeue element is " << x << std::endl;

    // 再次打印队列
    PrintQueue(Q);

    std::cout << "That queue is full is " << falg << std::endl;
    return 0;
}
