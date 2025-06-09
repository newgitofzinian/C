#include <stdio.h>
#include <string.h>
// str系列字符串操作函数
// strlen() 计算字符串长度
// strcpy() 复制字符串
// strcat() 连接字符串、拼接
// strcmp() 比较字符串

// strcat和strcpy都不能放字符串，只能放字符串变量。
int mystrlen(char *c) {
    int i = 0;
    while (c[i] != '\0') {  //
        i++;
    }
    return i;
}

int main(void) {
    int len; // 字符串长度
    char c[20];
    char d[100] = "world";
    char e[100];
    gets(c); // 在c11标准中已经被废，推荐使用fget()函数代替
    puts(c);
    len = strlen(c);
    printf("The length of the string is %d\n", len);
    len = mystrlen(c);
    printf("The length of the string is %d\n", len);
    strcat(c, d); // 把d字符串连接到c字符串后面
    puts(c);
    printf("The length of the string is %d\n", strlen(c));
    strcpy(e, c) ; // 把c字符串复制到e字符串中
    puts(e);
    printf("c?d %d\n", strcmp(c, e)); // 0是相等 正数是c在e前面 负数是c在e后面
    printf("c?hello %d", strcmp(c, "hello")); // 比较的是ascii码值

    return 0;


}
