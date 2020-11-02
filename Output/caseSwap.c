#include<stdio.h>

int main()
{
    int i=0;
    char str[] = "india";
    printf("Lower Case: %s\n", str);
    while(str[i] != '\0')
    {
        str[i] = str[i] ^ 0x20;
        i++;
    }
    printf("Upper Case: %s\n", str);
    i = 0;
    while(str[i] != '\0')
    {
        str[i] = str[i] ^ 0x20;
        i++;
    }
    printf("Upper Case: %s\n", str);
    return 0;
}
