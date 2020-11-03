#include <stdio.h>
    int main()
    {
        char *str = "hello world";
        char strc[] = "good morning india\n";
        strcpy(strc, str);
        printf("%s\n", strc);
        return 0;
    }
