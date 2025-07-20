#include <stdio.h>


int main(void) {
    FILE *fp = fopen("file.txt", "r"); //  打开文件

    if (NULL == fp) {   
        perror("fopen"); // 打开文件失败
        /* code */
        return -1;
    }
    

    // printf("Hello, World!\n");
    return 0;
}