# 考研真题实战之2019年(单链表)

## 题目描述

41. (13分) 设线性表 L = ($a_1$, $a_2$, $a_3$, ..., $a_{n-2}$, $a_{n-1}$, $a_n$) 采用带头结点的单链表保存，链表中的结点定义如下：

```c
typedef struct node {
    int data;       
    struct node *next;  
} NODE;
```

请设计一个空间复杂度为 O(1) 且时间上尽可能高效的算法，重新排列 L 中的各结点，得到线性表 L' = ($a_1$, $a_n$, $a_2$, $a_{n-1}$, $a_3$, $a_{n-2}$, ...)。要求：

1. 给出算法的基本设计思想。
2. 根据设计思想，采用 C 或 C++ 语言描述算法，关键之处给出注释。
3. 说明你所设计的算法的时间复杂度。

### 解读

**首先空间复杂度是O(1),我们不能申请额外的空间,然后找到链表的中间节点,前面一半是链表L,
将链表的后半部分分给一个新的头结点L2,然后将L2进行原地逆置,然后再将L与L2合并.
这样就得到了L'的顺序.时间复杂度是O(n),因为我们需要遍历链表两次,第一次遍历链表得到链表的中间节点,
第二次遍历链表进行逆置.**

## 解
### 1. 算法的基本思想:
首先,找到链表的中间节点,利用双指针slow和fast,找出中间结点slow,其次,将链表的后半部分分给一个新的头结点L2,即`L2=mid->next`;然后令`slow->next = nullptr`,最后返回,赋给mid.第二步将L2中的元素倒置,利用三指针进行指针的指向逆向,最后把更新后的第一个结点重新给到头节点`head->next = prev`完成倒置.最后合并L1和L2.循环遍历,每次循环中,先讲L1的结点合并,然后`L1 = L1->next`,令最后的目标链表`L=L->next`后再进行赋值.最后L1或L2中剩下一个元素,进行一个判断是否为空再进行合并即可完成.

### C++ 代码实现:

```c++
void find_middle(node* L, node*& L2) {
    L2 = (node*)malloc(sizeof(node));
    node* slow;
    node* fast;
    slow = L->next;
    fast = L->next;
    while (fast != nullptr) {
        fast = fast->next;
        if (nullptr == fast) {
            break;
        }
        fast = fast->next;
        if (nullptr == fast) {
            break;
        }
        slow = slow->next;
    }
    L2->next = slow->next;
    slow->next = nullptr;
}


node * reverseList(node *head) {
    node *prev = nullptr;
    node *curr = head->next;
    node *next = nullptr;
    while (curr!= nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = prev;
    return head;
}

node * mergeList(node *head1, node *head2) {
    node *dummy = (node*)malloc(sizeof(node));
    dummy->next = nullptr;
    node *tail = dummy;
    head1 = head1->next;
    head2 = head2->next;
    while (head1 != nullptr && head2 != nullptr) {
        tail->next = head1;
        tail = tail->next;
        head1 = head1->next;

        tail->next = head2;
        tail = tail->next;

        head2 = head2->next;
    }
    // 因为head1要么节点数与head2相同,要么多一个节点,所以最后要判断一下
    if (head1 != nullptr) {
        tail->next = head1;
    }
    return dummy;

}

```

### 时间复杂度分析:

- 找出链表的中间节点:O(n)
- 倒置链表:O(n)
- 合并链表:O(n)
- 总时间复杂度:O(n)