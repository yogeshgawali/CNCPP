#include <stdio.h>
    void m(int p)
    {
        printf("%d\n", p);
    }
    void main()
    {
        int a = 6, b = 5;
        m(a, b);
        printf("%d %d\n", a, b);
    }
