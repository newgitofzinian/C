#include <iostream>
// 按位查找&按值查找

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    LNode* next;
}LNode, *LinkList;


LinkList LinkTailInsert(LinkList &L, int n = 10) {
    // ElemType x;
    L = (LinkList)malloc(sizeof(LNode)); // 头结点
    // L = new LNode; // 头结点
    LNode *s, *r = L; // r为表尾指针
    // scanf("%d", &x);
    // while (x!=-1) {
    //     s = (LinkList)malloc(sizeof(LNode));
    //     s->data = x;
    //     r->next = s;
    //     r = s;  // r指向新的尾结点
    //     scanf("%d", &x);
    // }
    for (int i = 0; i < n; ++i) {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = std::rand() % 100; // 生成0到99之间的随机数
        r->next = s;
        r = s;  // r指向新的尾结点
    }
    r->next = nullptr;
    return L;
}

void LinkListPrint(LinkList L) {
    LNode *p = L->next;
    while (p!= nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

// 自动生成链表返回并打印
LinkList GenerateRandomLinkList(int n = 10) {
    LinkList L = nullptr;
    std::srand(std::time(0)); // 使用当前时间作为随机数种子
    L = LinkTailInsert(L, n);
    LinkListPrint(L);
    return L;
}

// 按值查找,并返回元素所在位置的指针,以及元素下标
std::pair<LinkList, int> LocateElem(LinkList L, ElemType x) {
    LNode *p = L->next;  // 没有可能会因为头结点的存在而导致错误
    int i = 0;
    while (p!= nullptr) {
        if (p->data == x) {
            return std::make_pair(p, i);
        }
        p = p->next;
        i++;
    }
    return std::make_pair(nullptr, -1);
}
// 按位置序号查找
LinkList GetElem(LinkList p, size_t SearchPos) {
    // LNode *p = L->next;
    size_t i = 0;
    while (p!= nullptr && i < SearchPos) {
    // 打印SearchPos;
    // printf("i=%d, SearchPos=%d\n", i, SearchPos);
    // bool f1 = p != nullptr;
    // bool f2 = i < SearchPos;
    // std::cout << "f1=" << std::boolalpha << f1 << ", f2=" << std::boolalpha << f2 << std::endl;
    // while (p!= NULL && i < SearchPos) {
        printf("循环第%d次\n", i+1);
        p = p->next;
        i++;
    }
    return p;

}

int main() {
    size_t x;
    LinkList L,search;
    L = GenerateRandomLinkList(10);
    std::cout << "请输入查找的元素序号: ";
    std::cin >> x;
    // 打印x;
    // std::cout << x << std::endl;
    // 如果x的值不合法,则重新输入
    while (x < 1 || x > 10) {
        std::cout << "输入的序号不合法,请重新输入: ";
        std::cin >> x;
    }
    search =  GetElem(L, x-1);
    if (search != nullptr) {
        std::cout << "元素" << search->data << "在位置" << x << "处" << std::endl;
    }
    else {
        std::cout << "该位置超出列表范围" << std::endl;
    }
    std::cout << "请输入查找的元素值: ";
    std::cin >> x;
    search = LocateElem(L, x).first; // 按值查找
    if (search != nullptr) {
        std::cout << "元素" << search->data << "在位置" << LocateElem(L, x).second << "处" << std::endl;
    }
    else {
        std::cout << "元素不存在" << std::endl;
    }
    return 0;
}
