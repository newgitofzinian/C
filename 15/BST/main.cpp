#include <iostream>
typedef int ElemType;
typedef int KeyType;
typedef struct TNode{
    ElemType data;
    TNode *lchild, *rchild;
}TNode, *BiTree;
// 二叉排序树 Binary Search Tree
// 只会考察中序遍历

// 缺点: 树的高度较高，查找效率低, 空间复杂度高
// 优点: 实现简单, 插入和删除操作的时间复杂度为O(logn), 空间复杂度为O(1)
bool BST_insert1(BiTree &T, KeyType x) {
    if (T == NULL) {
        T = (BiTree)malloc(sizeof(TNode));
        T->data = x;
        T->lchild=T->rchild = NULL;
        return true;
    }
    else if (x == T->data){
         return false;
    }
    else if (x < T->data){
        return BST_insert1(T->lchild, x);
    }
    else {
        return BST_insert1(T->rchild, x);
    }

}

// key值唯一, 时间复杂度O(logn)
// 空间复杂度O(1)
bool BST_insert2(BiTree &T, KeyType x) {
    BiTree TreeNew = (BiTree)malloc( sizeof(TNode)); // 申请内存
    TreeNew->data = x;
    if (T == NULL) {
        T = TreeNew;
        return true;
    }
    BiTree p =T, parent; // p用来查找树, parent用来记录父节点
    while (p) {
        parent = p;
        if (x == p->data) {
            return false;
        }
        else if (x < p->data) {
            p = p->lchild;
        }
        else {
            p = p->rchild;
        }
    }
    if (x < parent->data) {
        parent->lchild = TreeNew;
    }
    else {
        parent->rchild = TreeNew;
    }
    return true;
}


void Creat_BST(BiTree &T, KeyType str[], int n) {
    T = NULL;
    int i = 0;
    while (i<n) {
        // BST_insert1(T, str[i]);
        BST_insert2(T, str[i]);
        i++;
    }
}

void InOrder(BiTree T) {
    if (T == NULL) {
        return;
    }
    InOrder(T->lchild);
    std::cout <<  T->data << " ";
    InOrder(T->rchild);
}

BiTree BST_Search(BiTree T, KeyType x, BiTree &parent) {
    parent = NULL;
    while (T != NULL&&T->data!= x) {
        if (x < T->data) {
            parent = T;
            T = T->lchild;
        }
        else {
            parent = T;
            T = T->rchild;
        }
    }
    return T;
}

// 删除结点,大题不考察
BiTree BST_DeleteNode(BiTree &T, KeyType x) {
    BiTree parent, node, temp;
    node = BST_Search(T, x, parent);
    if (node == NULL) {  // 没有找到
        return T;
    }
    if (node->lchild == NULL || node->rchild == NULL) { // 只有一个孩子
        if (node->lchild == NULL) {
            temp = node->rchild;
            if (parent->lchild == node) {
                parent->lchild = temp;
            }
            else {
                parent->rchild = temp;
            }
        }
        else {
            temp = node->lchild;
            if (parent->lchild == node) {
                parent->lchild = temp;
            }
            else {
                parent->rchild = temp;
            }
        }
        free(node);
        return T;
    }
    else { // 有两个孩子
        // 要么拿左子树的最右结点, 要么拿右子树的最左结点,即左子树的最大值或右子树的最小值
        temp = node->rchild;
        while (temp->lchild != NULL) {
            temp = temp->lchild;
        } // 找到右子树中最左的结点
        node->data = temp->data;
        BST_DeleteNode(temp, temp->data);
        return T;
    }
}


int main() {
    BiTree T = NULL; // 树根
    BiTree parent;
    BiTree Search;
    KeyType str[11] = {1, 2, 3, 5, 4, 6, 7, 8, 9, 10, 11};
    Creat_BST(T, str, 11);
    InOrder(T);
    std::cout << "\n";
    Search = BST_Search(T, 40, parent);
    if (Search) {
        printf("Search success, value is %d, parent is %d\n", Search->data, parent->data);
    }
    else {
        printf("Search failed\n");
    }
    printf("\n");
    BST_DeleteNode(T, 3);
    InOrder(T);
    std::cout << "\n";
    return 0;
}
