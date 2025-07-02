#include <stdio.h>


// gets 类似于 scanf，但是它会一直读取输入直到遇到换行符
// puts 类似于 printf，但是它会在输出后添加换行符

int main(void) {
    char c[20];
    gets(c);
    printf("You entered: %s\n", c);
    puts(c); // 输出后会自动添加换行符,等价于 printf("%s\n", c);

    // printf("Hello, World!\n");
    return 0;
}