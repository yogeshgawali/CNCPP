#include <stdio.h>
    int main()
    {
        int a[4] = {1, 2, 3, 4};
        int *p = &a[1];
        int *ptr = &a[2];
        ptr = ptr * 1;
        printf("%d\n", *ptr);
    }
