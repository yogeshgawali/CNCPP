#include <stdio.h>
    int main()
    {
        int a[4] = {1, 2, 3, 4};
        int b[4] = {1, 2, 3, 4};
        int n = &b[3] - &a[2];
        printf("%d\n", n);
    }
