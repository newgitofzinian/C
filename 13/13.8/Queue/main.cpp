#include <iostream>

typedef int ElemType;
typedef struct Node{
    ElemType data;
    Node* next;
} Node, *LinkNode;
typedef struct Queue {
    Node* front;
    Node* rear;
} LinkQueue;

void InitQueue(LinkQueue &Q){
    LinkNode q = (LinkNode)malloc(sizeof(Node));
    q->next = nullptr;
    Q.front = Q.rear = q;
};

bool isEmpty(LinkQueue Q){
    return (Q.front == Q.rear);
};

bool isFull(LinkQueue Q) {
    return (Q.rear->next == Q.front );
}

bool EnQueue(LinkQueue &Q, ElemType x) {
   if (isFull(Q) || Q.rear->next == nullptr) {
       // 满队列增加空间
       LinkNode p = (LinkNode)malloc(sizeof(Node));
       Q.rear->data = x;
       // p->data = x;
       p->next = Q.front;
       Q.rear->next = p;
       Q.rear = p;
       return true;
   } else {
       // 未满队列直接入队
       Q.rear->data = x;
       Q.rear = Q.rear->next;
       return true;
   }
}

bool DeQueue(LinkQueue &Q, ElemType &x) {
    if (isEmpty(Q)) {
        return false;
    } else {
        x = Q.front->data;
        Q.front = Q.front->next;
        return true;
    }
}

void PrintQueue(LinkQueue Q) {
    LinkNode p = Q.front;
    while (p!= Q.rear) {
        std::cout << p->data << " ";
        p = p->next;
    }
    // std::endl;
    printf("\n");
}




int main() {
    LinkQueue Q;
    InitQueue(Q);

    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    PrintQueue(Q);

    ElemType x;
    DeQueue(Q, x);
    std::cout << x << std::endl;
    DeQueue(Q, x);
    std::cout << x << std::endl;
    DeQueue(Q, x);
    std::cout << x << std::endl;

    PrintQueue(Q);
    EnQueue(Q, 5);
    EnQueue(Q, 6);
    EnQueue(Q, 7);

    PrintQueue(Q);
    // DestroyQueue(Q);

    return 0;
}