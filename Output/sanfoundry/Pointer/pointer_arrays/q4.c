#include <stdio.h>
    void main()
    {
        char *s= "hello";
        char *p = s;
        printf("%c\t%c", *(p + 3),  s[1]);
    }
