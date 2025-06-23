# 考研真题实战之2014年(二叉树)

## 题目描述

41. (10分) 二叉树的带权路径长度(WPL)是二叉树中所有叶结点的带权路径长度之和。给定一棵二叉树树T,采用二叉链表存储,结点结构如表所示:


| left | weight | right |
| ---- | ------ | ----- |

其中叶结点的weight保存该结点的非负权值.设`root`为指向T的根结点的指针,请设计求T的WPL的算法,要求:

1. 给出算法的基本设计思想.
2. 使用C/C++语言,给出二叉树结点的数据类型定义.
3. 根据设计思想,采用C/C++语言描述算法,关键之处给出注释

## 自己解答

### 算法思想
    二叉树的带权路径长度(WPL)是二叉树中所有叶结点的带权路径长度之和。

- 如果结点为空,则WPL为0
- 如果结点为叶结点,则WPL等于其权值
- 否则,递归算出左右子树的WPL,并加上当前结点的权值,得到当前结点的WPL
- 最后,返回根结点的WPL

### 数据结构定义

```c++
struct TreeNode{
    int weight;
    TreeNode* left, *right;
}
```

### 算法描述


```c++
int WPL(TreeNode* root){
    if(root == NULL) return 0; // 空树的WPL为0
    if(root->left == NULL && root->right == NULL) return root->weight; // 叶结点的WPL等于其权值
    int leftWPL = WPL(root->left); // 计算左子树的WPL
    int rightWPL = WPL(root->right); // 计算右子树的WPL
    int sumWPL = leftWPL + rightWPL + root->weight; // 计算当前结点的WPL
    return sumWPL;
}
```
**当然,除了数据结构定义,都是错的**
##  答案解析
二叉树的WPL为每个叶子结点的深度(路径长度)与权值之乘积的和。可以使用先序遍历或者层次遍历解决问题.

### 算法思想
1. 基于先序遍历,利用一个static变量记录WPL,把每个结点的深度作为递归函数的一个参数传递.

算法步骤如下:
- 如果结点是叶子结点,那么变量WPL 加上该结点的路径长度与权值之乘积.
- 如果结点不是叶子结点,左子树不为空,对左子树递归调用算法,若右子树不为空,对右子树调用递归算法.
- 深度参数均为本结点的路径长度参数加一;
- 返回WPL.

### 算法描述

```c++
int WPL(TreeNode* root, int depth = 1){
   if(root==NULL){
   return 0;}
   if(root->left==NULL && root ->right == NULL){  // 叶子结点
      return depth * root->weight;
   }
   int leftWPL = WPL(root->left, depth+1);
   int rightWPL = WPL(root->right, depth+1);
   return leftWPL + rightWPL;
}
   
```


















