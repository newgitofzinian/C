#include <iostream>

// 在子函数内修改主函数的普通变量的值
void modify(int& b) {   // 引用作为函数参数
    b = b + 1;
}

// 子函数修改住函数的一级指针变量 重要‼️
void modify_pointer(int* &p, int *q) {
    p = q;
}

// TIP 要<b>Run</b>代码，请按 <shortcut actionId="Run"/> 或点击装订区域中的 <icon src="AllIcons.Actions.Execute"/> 图标。
int main() {
    int a = 10;
    modify(a);
    std::cout << "after modify, a = " << a << std::endl;

    int *p = NULL;
    int *q = &a;
    modify_pointer(p, q);
    printf("after modify_pointer, p = %p, q = %d\n", p, *q);
    std::cout << "after modify_pointer, p = " << p << ", q = " << q << std::endl;


    return 0;
    // TIP 请访问 <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a> 查看 CLion 帮助。此外，您还可以从主菜单中选择“帮助 | 学习 IDE 功能”，尝试 CLion 的交互式课次。
}