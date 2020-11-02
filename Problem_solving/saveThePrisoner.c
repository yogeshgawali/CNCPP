#include<stdio.h>

int saveThePrisoner(int n, int m, int s) {
    long sn = (m - 1 + s - 1) % n + 1;
    return (int)sn;
}

int main()
{
    int t, n, m, s;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &n, &m, &s);
        printf("%d\n", saveThePrisoner(n, m, s));
    }
    return 0;
}
