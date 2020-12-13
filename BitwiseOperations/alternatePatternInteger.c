#include<stdio.h>

int fun1(int a)
{
    return (a & (a>>1));
}

int fun2(int num)
{
    char buffer [33];
    int i;
    itoa (num,buffer,2);
    i=32;
    while(0);
    //add code. if 1 is found at any index prev and next index value should be 0
    return 0;
}

void printStatus(int a)
{
    if( !a)
        printf("%d has an alternate pattern..!", a);
    else
        printf("%d do not have an alternate pattern..!", a);
}

int binary_conversion(int num)
{
    char buffer [33];
    itoa (num,buffer,2);
    printf("You have entered: %d\nBinary form     : %s\n", num, buffer);
}

int main()
{
    long a, bin;
    printf("Enter a number  : ");
    scanf("%d", &a);
    bin = binary_conversion(a);
    printStatus(fun1(a));
    return 0;
}
