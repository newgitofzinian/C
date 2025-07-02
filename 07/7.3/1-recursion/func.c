//
// Created by 子年 on 25-6-10.
//

#include "func.h"

// 递归函数， 阶乘
int f(int x) {
    if (x == 1) {
        return 1;
    }
    return x * f(x - 1);
}

// 上台阶，到第n级台阶有多少种方法
int staircase(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return staircase(n - 1) + staircase(n - 2); // 时间复杂度O(2^n) ， 空间复杂度O(n) 一般不适用

}