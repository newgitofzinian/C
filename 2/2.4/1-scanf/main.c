#include <stdio.h>


void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // 读取并丢弃缓冲区中的字符，直到遇到换行符或文件结束符
}

// scanf读取输入输出
int main(void) {
    // scanf %d %f 发现\n,忽略
    // scanf %c 不忽略内容
    // scanf 会阻塞，是因为标准输入缓冲区是空的
    int i;
    scanf("%d", &i);    // 注意，一定要放地址
    printf("%d\n", i);
    // char c;
    // fflush(stdin);//清空标准输入缓冲区
    // clear_input_buffer(); // 清空输入缓冲区
    // scanf("%c", &c);
    // printf("c=%c\n", c);// 输出字符变量c
    /**
     *
     *123
     *123
     *c=
     *
     *c读取了10之后默认的\n
     ***/
    float f;
    scanf("%f", &f);
    printf("f=%f\n", f);


}