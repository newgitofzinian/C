#include <stdio.h>

// 模拟printf("%s ", c)
void print(char d[]){
    int i = 0;
    while (d[i] != '\0') {  // 如果字符串数组不规范，没有预留\0，则会继续打印，显示乱码
        printf("%c", d[i]);
        i++;
    }
    printf("\n");
}



int main(void) {
    int i;
    char c[11]; // 虽然只有十个字符，但是默认会有一个换行符（结束符）
    // 可以每个字符单独初始化
    c[0] = 'I'; c[1] = ' ', c[2] = 'a'; c[3] = 'm'; c[4] = ' ';
    c[5] = 'h'; c[6] = 'a'; c[7] = 'p'; c[8] = 'p'; c[9] = 'y';
    // 也可以整体初始化
    char c1[11] = {'I', ' ', 'a', 'm', ' ', 'h', 'a', 'p', 'p', 'y'};
    // 通常采用的是这种
    char c2[] = "I am happy";
    char d[5] = "how";
    printf("%s\n", c); // %s，遇到\0就结束输出，结束符第一个是\0
    print(c1);
    // print()
    return 0;
}