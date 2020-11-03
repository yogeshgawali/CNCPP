#include <stdio.h>
    int main()
    {
        int a[4] = {1, 2, 3, 4};
        int *ptr  =  &a[2];
        float n = 1;
        ptr = ptr + n;
        printf("%d\n", *ptr);
    }
