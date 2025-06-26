#include <iostream>
#include<stdlib.h>

// 折半查找,又称二分查找
// 时间复杂度O(logn)
// 适用于有序数组
// 数组必须是有序的，否则无法使用折半查找
// 数组的第一个元素作为起始位置，最后一个元素作为终止位置

typedef int ElemType;
typedef struct {
    ElemType *elem;
    int TableLen;
} SSTable;


int BinarySearch(SSTable L, ElemType key) {
    int low = 0, high = L.TableLen - 1;
    do {
        int mid = (low + high) / 2;
        if (key == L.elem[mid]) return mid;
        if (key > L.elem[mid]) {
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }while (low > high);
    // while (low <= high) {
    //     int mid = (low + high) / 2;
    //     if (key == L.elem[mid]) return mid;
    //     if (key > L.elem[mid]) {
    //         low = mid + 1;
    //     }else {
    //         high = mid - 1;
    //     }
    // }
    return -1;
}

int compare(const void *a, const void *b) {
    return (*(ElemType *)a - *(ElemType *)b);
}

void ST_init(SSTable &ST, int TableLen) {
    ST.TableLen = TableLen + 1; // Add 1 to account for the sentinel element 哨兵元素
    ST.elem = (ElemType*)malloc(TableLen * sizeof(ElemType));
    srand(time(NULL));
    for (int i = 1; i < ST.TableLen ; i++) {
        ST.elem[i] = rand() % 100;
    }
    // void qsort(void *buf, size_t num, size_t size, int(*compare)(const void*, const void*));

    qsort(ST.elem, ST.TableLen, sizeof(ElemType), compare);
}

void ST_print(SSTable ST) {
    if (ST.TableLen == 0) {
        printf("Table is empty\n");
        return;
    }
    for (int i = 1; i < ST.TableLen; i++) {
        printf("%3d ", ST.elem[i]);
    }
    printf("\n");
}


int main() {
    SSTable ST;
    ElemType key;
    int pos;
    ST_init(ST, 11);
    ST_print(ST);
    printf("Enter a key to search: \n");
    scanf("%d", &key);
    pos = BinarySearch(ST, key);
    if (pos) {
        printf("Search successful, key found at position %d\n", pos);
    }
    else {
        printf("Search unsuccessful, key not found\n");
    }

    return 0;
}