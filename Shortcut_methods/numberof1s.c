#include<stdio.h>

int func1(int n)
{
    int count=0;
    while(n)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}

int func2(int x)
{
    x = (x & (0x55555555)) + ((x >> 1) & (0x55555555));
    x = (x & (0x33333333)) + ((x >> 2) & (0x33333333));
    x = (x & (0x0f0f0f0f)) + ((x >> 4) & (0x0f0f0f0f));
    x = (x & (0x00ff00ff)) + ((x >> 8) & (0x00ff00ff));
    x = (x & (0x0000ffff)) + ((x >> 16) & (0x0000ffff));
    return x;
}

int func3(int x)
{
     int count=0;
     while(x){
       count += (x & 1);
       x  = x >> 1;
     }
     return count;
}

int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);

    printf("i's count using operators: %d\n", func1(a));
    printf("i's count using bitwise operators: %d\n", func2(a));
    printf("i's count using traditional method: %d\n", func3(a));
    return 0;
}
