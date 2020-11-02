#include<stdio.h>

int main()
{
    int len=0;
    char *c;
    c = (char*)malloc(100*sizeof(char));
    printf("Enter a string: ");
    scanf("%[^\n]%*c", c);
    len = strlen(c);
    printf("Length of string: %d", len);
    free(c);
    return 0;
}
