//
// Created by 子年 on 25-6-22.
//
// KMP algorithm implementation in C

#include <iostream>
#include <string>
typedef char ElemType;
typedef struct {
    ElemType ch[50];
    int length;
}SString;


// 基于朴素算法优化的KMP算法

void GetNext(SString pattern, int next[]) {
    int j = 0;
    int k = -1;
    next[0] = -1;
    while (j < pattern.length) {
        if (k == -1 || pattern.ch[j] == pattern.ch[k]) {
            j++;
            k++;
            // if (pattern.ch[j] != pattern.ch[k]) {
                next[j] = k;
            // }
            // else {
                // next[j] = next[k];
            // }

        } else {
            k = next[k];
        }
    }
}

int Index_KMP(SString S, SString T, int next[]) {
    int i=1, j=1;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {  // 匹配成功,继续比较后续字符
            i++;
            j++;
        } else {
            j = next[j];
        }
        if (j > T.length) {
            // 匹配成功
            return i - T.length;
        }
        return -1;   // 匹配失败
    }
}



int main() {
    SString S = {"abcde", 5};
    SString T = {"aaaab", 5};
    int next[50] = {0};
    int move[50] = {0};
    GetNext(T, next);
    // 打印next数组
    for (int i = 1; i < T.length + 1; i++) {
        std::cout << next[i] << " ";
    }
    std::cout << std::endl;
    // move数组
    for (int i = 1; i < T.length + 1; i++) {
        move[i] = i -1 - next[i];
    }
    // 打印move数组
    for (int i = 1; i < T.length + 1; i++) {
        std::cout << move[i] << " ";
    }


    // int index = Index_KMP(S, T, next);
    // if (index != -1) {
    //     std::cout << "The pattern is found at index " << index << std::endl;
    // } else {
    //     std::cout << "The pattern is not found in the string" << std::endl;
    // }
    // return 0;
}