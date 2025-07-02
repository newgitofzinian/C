# include "func.h"
// <>是去标准库目录下找头文件，""是指当前目录下找头文件
// void print_message(); // 声明print_message()函数，放在头文件中
// 如果函数放在后面，则需要在前面先声明


int main(void) {
    int a = 10;
    a = print_star(a);
    print_message(); // 调用print_message()函数
    print_star(5);
    return 0;
}


