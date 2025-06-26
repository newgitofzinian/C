#include <iostream>

typedef int ElemType;
typedef struct {
    ElemType *elem;
    int TableLen;
} SSTable;

void ST_init(SSTable &ST, int TableLen) {
    ST.TableLen = TableLen + 1; // Add 1 to account for the sentinel element 哨兵元素
    ST.elem = (ElemType*)malloc(TableLen * sizeof(ElemType));
    srand(time(NULL));
    for (int i = 1; i < ST.TableLen; i++) {
        ST.elem[i] = rand() % 100;
    }
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

int ST_search(SSTable ST, ElemType key) {
    ST.elem[0] = key; // Set the sentinel element to the key to search for
    int i;
    for ( i = ST.TableLen - 1; ST.elem[i]!= key; --i);
    return i; // Return the position of the key in the table
}

int main() {
    SSTable ST;
    ElemType key;
    int pos;
    ST_init(ST, 10);
    ST_print(ST);
    printf("Enter a key to search: \n");
    scanf("%d", &key);
    pos = ST_search(ST, key);
    if (pos) {
        printf("Search successful, key found at position %d\n", pos);
    }
    else {
        printf("Search unsuccessful, key not found\n");
    }
}