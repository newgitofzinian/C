#include <iostream>
// 队列 FIFO First In First Out
// 栈 LIFO Last In First Out
// 循环队列 数组
#define MaxSize 5
typedef int ElemType;
typedef struct {
    int data[MaxSize]; // 循环队列存储MaxSize-1个数据
    int front, rear; // front 指向队首， rear 指向队尾
}SqQueue;

void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

bool isEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

bool isFull(SqQueue Q) {
    return (Q.rear + 1) % MaxSize == Q.front;
}

bool EnQueue(SqQueue &Q, ElemType x) {
    if (isFull(Q)) {
        std::cout << "Queue is full!" << std::endl;
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x) {
    if (isEmpty(Q)) {
        std::cout << "Queue is empty!" << std::endl;
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}
// 打印队列
void PrintQueue(SqQueue Q) {
    if (isEmpty(Q)) {
        std::cout << "Queue is empty!" << std::endl;
        return;
    }
    int i = Q.front;
    do {
        std::cout << Q.data[i] << " ";
        i = (i + 1) % MaxSize;
    } while (i != Q.rear);
    std::cout << std::endl;

}

int main() {
    SqQueue Q;
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

    falg = isFull(Q);
    std::cout << "That queue is full is " << falg << std::endl;



    return 0;
}