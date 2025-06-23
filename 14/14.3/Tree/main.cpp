#include <iostream>


typedef int ElemType;
// Link to the BiTree struct
typedef struct TreeNode {
    ElemType data;
    TreeNode *lchild, *rchild;
}BiTNode, *BiTree;


void visit(BiTree T) {
    std::cout << T->data << " ";
}

// 中序遍历
void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
// 先序遍历
void Preorder(BiTree T) {
    if (T!= NULL) {
        visit(T);
        Preorder(T->lchild);
        Preorder(T->rchild);
    }
}
// 后序遍历
void Postorder(BiTree T) {
    if (T!= NULL) {
        Postorder(T->lchild);
        Postorder(T->rchild);
        visit(T);
    }
}
// 测试函数
void TestBiTree() {
    BiTree root = new BiTNode;
    root->data = 1;
    root->lchild = new BiTNode;
    root->lchild->data = 2;
    root->rchild = new BiTNode;
    root->rchild->data = 3;
    root->lchild->lchild = new BiTNode;
    root->lchild->lchild->data = 4;
    root->lchild->rchild = new BiTNode;
    root->lchild->rchild->data = 5;
    root->rchild->lchild = new BiTNode;
    root->rchild->lchild->data = 6;
    root->rchild->rchild = new BiTNode;
    root->rchild->rchild->data = 7;

    std::cout << "Inorder traversal of the binary tree is: ";
    InOrder(root);
    std::cout << std::endl;

    std::cout << "Preorder traversal of the binary tree is: ";
    Preorder(root);
    std::cout << std::endl;

    std::cout << "Postorder traversal of the binary tree is: ";
    Postorder(root);
    std::cout << std::endl;
}

int main() {
    TestBiTree();
    return 0;
}