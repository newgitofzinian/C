#include <stdio.h>

int main(void)
{
    int i;
    while (scanf("%d", &i))
    {
        if (i > 0)
        {
            printf("%d is bigger than 0\n", i);
        }
        else
        {
            printf("%d is smaller than 0\n", i);
        }
    }
    return 0;
}
