#include <iostream>
// 串的顺序存储
#define MAXLEN 255

typedef char ElemType;
typedef struct {
    ElemType ch[MAXLEN];
    int length;
}SString;
// 动态数组实现(堆分配存储)
typedef struct {
    ElemType *ch;
    int length;
}HString;
void initHString(HString &hs) {
    // HString hs; // 定义一个堆分配的字符串
    hs.ch = (ElemType*)malloc(MAXLEN*sizeof(ElemType)); // 使用完毕需要手动free
    hs.length = 0;
}
// 1B存储实际信息,4B存储辅助信息,存储密度低,所以不采纳
// 所以每个结点可以存储多个字符
typedef struct StringNode {
    // ElemType ch; //(1B)
    ElemType ch[4]; //(1B*4)
    StringNode *next;
}StringNode, *String;

// 串的基本操作
/* StrAssubf(&T, chars): 赋值操作,将串T赋值为chars.
 * StrCopy(&T, S): 复制操作,将串S复制得到串T.
 * StrEmpty(S): 判断串S是否为空.
 * StrLength(S): 计算串S的长度.
 * ClearString(&S): 清空串S.
 * DestroyString(&S): 销毁串S.
 * Concat(&T, S1, S2): 串连接操作,将串S1和S2连接得到串T.
 */

void StrAssubf(SString &T, char * chars) {
    // T.ch[1]  chars;  // ch[0] 不赋值
    T.ch[0] = '\0';
    int i = 1;
    while (chars[i-1]!= '\0') {
        T.ch[i] = chars[i-1];
        i++;
    }
    T.length = i-1;
}

void StrCopy(SString &T, SString S) {
    for (int i = 1; i <= S.length; i++) {
        T.ch[i] = S.ch[i];
    }
    T.length = S.length;
}

bool StrEmpty(SString S) {
    return S.length == 0;
}

int StrLength(SString S) {
    return S.length;
}

void ClearString(SString &S) {
    S.length = 0;
}
// 串的链式存储实现销毁串
void DestroyString(String &S) {
    while (S!= nullptr) {
        StringNode *p = S;
        S = S->next;
        free(p);
    }
}
// 串的动态数组实现销毁串
void DestroyHString(HString &hs) {
    free(hs.ch);
}

void Concat(SString &T, SString S1, SString S2) {
    if (S1.length + S2.length > MAXLEN) {
        std::cout << "Error: Concatenation failed, the length of the result is too long." << std::endl;
        return;
    }
    for (int i = 1; i <= S1.length; i++) {
        T.ch[i] = S1.ch[i];
    }
    for (int i = 1; i <= S2.length; i++) {
        T.ch[i+S1.length] = S2.ch[i];
    }
    T.length = S1.length + S2.length;
}

// 定位操作
int Index(SString S, SString T) {
    int i=1, j=1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length) {
        return i - T.length;
    }
    return -1;
}

// 给串赋值
void Assign(SString &S, char chars) {
    S.ch[1] = chars;
    S.length = 1;
}

// int main() {
//     SString s1, s2;
//     StrAssubf(s1, "aabbccddeeff");
//     StrAssubf(s2, "bccddeefff");
//
//     // 打印串
//     std::cout << "s1: ";
//     for (int i = 1; i <= s1.length; i++) {
//         std::cout << s1.ch[i];
//     }
//     std::cout << std::endl;
//
//     std::cout << "s2: ";
//     for (int i = 1; i <= s2.length; i++) {
//         std::cout << s2.ch[i];
//     }
//     std::cout << std::endl;
//
//
//
//     int ret = Index(s1, s2);
//     std::cout << "Index of " << s2.ch << " in " << s1.ch << " is " << ret << std::endl;
//
//     return 0;
// }