#include <stdio.h>
    void f(char *k)
    {
        k++;
        k[2] = 'm';
    }
    void main()
    {
        char s[] = "hello";
        f(s);
        printf("%c\n", *s);
    }
