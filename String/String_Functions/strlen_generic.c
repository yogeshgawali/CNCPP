#include<stdio.h>

int main()
{
    int len=0;
    char *c;
    c = (char*)malloc(100*sizeof(char));
    printf("Enter a string: ");
    scanf("%[^\n]%*c", c);

    while(c[len]!='\0')
    {
        len++;
    }

    printf("Length of string: %d", len);
    free(c);
    return 0;
}
