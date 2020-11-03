#include <stdio.h>
    void main()
    {
        char *s = "hello";
        char *p = s;
        printf("%c\t%c", *(p + 1), s[1]);
    }
