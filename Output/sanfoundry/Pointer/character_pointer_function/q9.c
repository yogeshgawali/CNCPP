#include <stdio.h>
    void fun(char *k)
    {
        printf("%s", k);
    }
    void main()
    {
        char s[] = "hello";
        fun(s);
    }
