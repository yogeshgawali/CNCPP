#include <stdio.h>
    int main()
    {
        int i = 10;
        int *const p = &i;
        foo(&p);
        printf("%d\n", *p);
    }
    void foo(int **p)
    {
        int j = 11;
        *p = &j;
        printf("%d\n", **p);
    }
