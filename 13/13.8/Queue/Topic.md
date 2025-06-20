# 考研真题实战之2019年(队列)

## 题目描述

42. (10分) 请设计一个队列,要求满足:1.初始队列为空;2. 入队时,运行增加队列占用空间;3. 出队后, 出队元素所占用的空间可重复使用,即整个队列所占用的空间只增不减;4.入队操作和出队操作的时间复杂度始终保持为`O(1)`. 请回答下列问题:
    (1) 该队列应该选择链式存储结构,还是应选择顺序存储结构?
    (2) 画出队列的初始状态,并给出判断队空和队满的条件.
    (3) 画出第一个元素入队后的队列状态.
    (4) 给出入队操作和出队操作的基本过程.

## 题目解析

1. 应该选择链式春初结构,队头指针为front,队尾指针尾rear.
   因为第二个要求允许增加队列占用空间,所以必须是链式存储.还需要循环队列.
2. 初始时,创建只有一个空闲结点的两段式单向循环链表,头指针和尾指针都指向这个结点.
   队空的条件就是`Q.front == Q.rear `; 当空闲结点填入数据,队满队条件`Q.rear->next == Q.front`
3.
- 假设初始状态如下：
  ```
  front -> [空闲结点] -> rear
           ↑------------|
  ```
- 第一个元素入队后，队列状态变为：
  ```
  front -> [空闲结点] -> [新结点] -> rear
           ↑--------------------------|
  ```
4. 入队操作：
   - 判断队列是否为满或尾结点指向的结点是否为空,若是,则创建一个新结点.把x赋给`Q.rear->data`,然后把`Q.rear->next`指向新结点,然后把`Q.rear`指向新结点.
   - 若队列不为空,同样将x赋值,然后`Q.rear = Q.rear->next`,即把尾指针后移一位.
   - 时间复杂度为O(1)
     
   出队操作：
   - 判断队列是否为空,若是,则返回空值.
   - 若队列不为空,则把`Q.front->data`返回,然后把`Q.front`指向`Q.front->next`,即把头指针后移一位.
   - 时间复杂度为O(1)

## 参考答案
```C++
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
   if (isFull(Q) || Q.rear -> next = nullptr) {
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
```

