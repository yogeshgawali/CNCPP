#include <stdio.h>

main()
{
    char *p = 0;
    *p = 'a';
    printf("value in pointer p is %c\n", *p);
}

/*
main()
{
    char *p = "Sanfoundry C-Test";
    p[0] = 'a';
    p[1] = 'b';
    printf("%s", p);
}
*/
