#include <stdio.h>
// 大写变小写
int main() {
    char c = 'A';
    // 注意，‘a'是字符型常量，“a”是字符串型常量，两者不同，单双引号要注意
    printf("%c\n",c+32);
    printf("%d\n",c);
    printf("%d\n",sizeof(c));
    return 0;
}