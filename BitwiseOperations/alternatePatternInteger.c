#include<stdio.h>


int binary_conversion(int num)
{
    if(num == 0)
        return 0;
    else
        return (num % 2) + 10 * binary_conversion(num / 2);
}

int main()
{
    long a, bin;
    printf("Enter a number: ");
    scanf("%d", &a);
    bin = binary_conversion(a);
    printf("You have entered %d\nBinary form: %d\n", a, bin);
    if( !(a & (a>>1)))
        printf("%d has an alternate pattern..!", a);
    else
        printf("%d do not have an alternate pattern..!", a);
    return 0;
}
