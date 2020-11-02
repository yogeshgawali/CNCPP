#include<stdio.h>

int reverse(int x)
{
    char st[10];
    int revn, i, len, digit;
    sprintf(st, "%d", x);
    len = strlen(st);
    printf("String form: %s\n", st);
    for(i=0; i<len; i++)
    {
        printf("Iteration %d:\n", i);
        digit = st[len-i-1]-48;
        revn  = revn*10 + digit;
        printf("digit= %d\trevn= %d\n\n", digit, revn);
    }
    return revn;
}

int main()
{
    printf("%d",reverse(12345));
    return 0;
}
