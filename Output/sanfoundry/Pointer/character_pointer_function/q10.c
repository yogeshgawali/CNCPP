#include <stdio.h>
    int main()
    {
        char *str = "This"; //Line 1
        char *ptr = "Program\n"; //Line 2
        str = ptr; //Line 3
        printf("%s, %s\n", str, ptr); //Line 4
    }
