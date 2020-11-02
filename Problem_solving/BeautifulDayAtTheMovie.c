#include<stdio.h>
#include<stdlib.h>
int reverse(int x)
{
    char st[10];
    int revn, i, len, digit;
    sprintf(st, "%d", x);
    len = strlen(st);
    for(i=0; i<len; i++)
    {
        digit = st[len-i-1]-48;
        revn  = revn*10 + digit;
    }
    return revn;
}

int beautifulDays(int i, int j, int k)
{
    int rev=0, count=0, x, val, ab;
    for(x=i; x<=j; x++)
    {
        rev = reverse(x);
        ab = abs(x-rev);
        val = ab/k;
        if( (val*k) != ab)
        {
             count++;
        }
        //printf("\t%d\n",count);
    }
    return count;
}

int main()
{
    int num = beautifulDays(20, 30, 6);
    printf("%d", num);
    return 0;
}
