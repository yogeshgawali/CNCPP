#include<stdio.h>

int viralAdvertising(int n)
{
    int d, s=5, l=2, c=2;
    for(d=2; d<=n; d++)
    {
        s = l*3;
        l = s/2;
        c += l;
    }
    return c;
}

int main()
{
    int d;
    printf("Enter day: ");
    scanf("%d", &d);
    printf("Total likes after %d days: %d", d, viralAdvertising(d));
    return 0;
}


/*
Enter day: 5
Total likes after 5 days: 24
*/
